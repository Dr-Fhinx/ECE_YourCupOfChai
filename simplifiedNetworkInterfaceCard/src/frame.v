module frame(
input clock,hps_uart_rx,reset_pin,
output reg [3:0] data_out,
output reg final_data_valid
);

//uart_data
wire valid_uart_wire,invalid_uart_wire;
wire [7:0]uart_data_out;

//udp_packet
wire [63:0]envelope_udp_wire;
wire udpEnvelopeValid_wire;

//ipEnvelope
reg udpEnvelopeValid_reg;
wire [159:0]ipEnvelope_data_out_wire;
wire validipEnvelope_wire;

//crc32_4bit
wire [3:0]data_in;
wire [31:0]crc_out;
reg reset,data_valid;
reg [3:0]data_in_reg;

//predefined terms
reg [3:0]preamble_reg = 4'b0101;
reg [7:0] sfd = 8'b11010101;
reg [5:0]counter, timeSet;
reg [47:0] dest_mac = 48'hAABBCCDDEEFF;
reg [47:0] src_mac  = 48'h112233445566;
reg [15:0] ether_type = 16'h0800;
reg validPreamble,validSFD,validDEST_MAC,validSRC_MAC,validETHER_TYPE,validIP_HEADER,validUDP_HEADER,validFCS;

//calling other modules.
//fetching uart data
uart_data uut( .hps_uart_rx(hps_uart_rx),
.clock(clock),
.data_out(uart_data_out),
.invalid(invalid_uart_wire),
.valid(valid_uart_wire)
);
//packing uart data with udp
udp_envelope udp_packet (
.hps_uart_unpacked(uart_data_out),
.clock(clock),
.envelope(envelope_udp_wire),
.valid(valid_uart_wire),
.udpEnvelopeValid(udpEnvelopeValid_wire)
);
//ip
ipEnvelope ipHeader (
.clock(clock),
.udpEnvelopeValid(udpEnvelopeValid_wire),
.ipEnvelope_data_out(ipEnvelope_data_out_wire),
.validipEnvelope(validipEnvelope_wire)
);
//crc32
crc32_4bit crc_32(
.clk(clock),
.reset(reset),
.data_valid(data_valid),
.data_in(data_in_reg),
.crc_out(crc_out)
);

// designing a state machine.
reg [3:0]STATE;
parameter PREAMBLE = 4'b0000,
			 SFD = 4'b0001,
			 DEST_MAC = 4'b0010,
			 SRC_MAC = 4'b0011,
			 ETHER_TYPE = 4'b0100,
			 IP_HEADER = 4'b0101,
			 UDP_HEADER = 4'b0110,
			 FCS = 4'b0111,
			 WAIT_IPG = 4'b1000,
			 IDLE = 4'b1001;
			 
	 
	 
initial begin
    STATE = IDLE;
    counter = 0;
    validPreamble = 0;
    validSFD = 0;
    // ... initialize other valid signals ...
    final_data_valid = 0;
    data_valid = 0;
    reset = 1;
end


always@(posedge clock)
begin
if (reset_pin) begin
        STATE <= IDLE;
        counter <= 0;
        final_data_valid <= 0;
end
else begin
case(STATE)

IDLE :	begin
				counter<=0;
				final_data_valid<=0; 
				data_valid<=0;
				reset<=1;
				validPreamble<=0;
				validSFD<=0;
				validDEST_MAC<=0;
				validSRC_MAC<=0;
				validETHER_TYPE<=0;
				validIP_HEADER<=0;
				validUDP_HEADER<=0;
				validFCS<=0;
				if(udpEnvelopeValid_wire)
				begin
					STATE<=PREAMBLE;
				end
			end
		
PREAMBLE : begin
					final_data_valid<=1;
					if(counter<14)
					begin
						data_out<=preamble_reg[3:0];
						counter <= counter + 1;
					end
					else if(counter==14)
					begin
						STATE<=SFD;
						validPreamble<=1;
						counter<=0;
					end
					else final_data_valid<=0;
			  end
			  
SFD : begin
			if(validPreamble==1)
			begin
				if(counter<2)
				begin
					data_out<=sfd[counter*4 +: 4];
					counter<=counter+1;
					final_data_valid<=1;
				end		
				else if(counter==2)
				begin
					validSFD<=1;
					STATE<=DEST_MAC;
					counter<=0;
					data_valid<=1;
					reset <=0;
				end
			end
			else
			begin
				STATE<=IDLE;
				final_data_valid<=0;
				data_valid<=0;
			end
		end

DEST_MAC : begin
					if(validSFD==1)
					begin
						if(counter<12)
						begin
							data_out<=dest_mac[((5-(counter/2))*8) + (counter[0]*4) +: 4];
							data_in_reg<=dest_mac[((5-(counter/2))*8) + (counter[0]*4) +: 4];
							counter<=counter+1;
							final_data_valid<=1;
						end
						else if(counter == 12)
						begin
							validDEST_MAC<=1;
							STATE<=SRC_MAC;
							counter<=0;
						end
					end
					else
					begin
						STATE<=IDLE;
						final_data_valid<=0;
						data_valid<=0;
						reset <=1;
					end
				end

SRC_MAC : begin
				if(validDEST_MAC==1)
				begin
					if(counter<12)
					begin
						data_out<=src_mac[((5-(counter/2))*8) + (counter[0]*4) +: 4];
						data_in_reg<=src_mac[((5-(counter/2))*8) + (counter[0]*4) +: 4];
						counter<=counter+1;
						final_data_valid<=1;
					end
					else if(counter == 12)
					begin
						validSRC_MAC<=1;
						STATE<=ETHER_TYPE;
						counter<=0;
					end
				end
				else
					begin
					STATE<=IDLE;
					final_data_valid<=0;
					data_valid<=0;
					reset<=1;
				end
		   end
			
ETHER_TYPE : begin
					if(validSRC_MAC==1)
					begin
						if(counter<4)
						begin
							data_out<=ether_type[((1-(counter/2))*8) + (counter[0]*4) +: 4];
							data_in_reg<=ether_type[((1-(counter/2))*8) + (counter[0]*4) +: 4];
							counter<=counter+1;
							final_data_valid<=1;
						end
						else if(counter == 4)
						begin
							validETHER_TYPE<=1;
							STATE<=IP_HEADER;
							counter<=0;
						end
					end
					else
					begin
						STATE<=IDLE;
						final_data_valid<=0;
						data_valid<=0;
						reset<=1;
					end
				end
			
IP_HEADER : begin
					if(validETHER_TYPE==1)
					begin
						if(counter<40)
						begin
							data_out<=ipEnvelope_data_out_wire[((19-(counter/2))*8) + (counter[0]*4) +: 4];
							data_in_reg<=ipEnvelope_data_out_wire[((19-(counter/2))*8) + (counter[0]*4) +: 4];
							counter<=counter+1;
							final_data_valid<=1;
						end
						else if(counter == 40)
						begin
							validIP_HEADER<=1;
							STATE<=UDP_HEADER;
							counter<=0;	
						end
					end
					else
					begin
						STATE<=IDLE;
						final_data_valid<=0;
						data_valid<=0;
						reset<=1;
					end
				end
			
UDP_HEADER : begin
					if(validIP_HEADER==1)
					begin
						if(counter<16)
						begin
							data_out<=envelope_udp_wire[((7-(counter/2))*8) + (counter[0]*4) +: 4];
							data_in_reg<=envelope_udp_wire[((7-(counter/2))*8) + (counter[0]*4) +: 4];
							counter<=counter+1;
							final_data_valid<=1;
						end
						else if(counter == 16)
						begin
							validUDP_HEADER<=1;
							STATE<=FCS;
							counter<=0;
						end
					end
					else
					begin
						STATE<=IDLE;
						final_data_valid<=0;
						data_valid<=0;
						reset<=1;
					end
				end
				
FCS : begin
			if(validIP_HEADER==1)
			begin
				if(counter<8)
				begin
					data_out<=crc_out[counter*4+:4];
					counter<=counter+1;
					final_data_valid<=1;
				end
				
				else if(counter == 8)
				begin
					validFCS<=1;
					STATE<=WAIT_IPG;
					counter<=0;
					reset<=1;
					data_valid<=0;
					final_data_valid<=0;
				end
			end
			else
			begin
				STATE<=IDLE;
			end
			
		end
		
WAIT_IPG: begin
            if(validFCS)
            begin
            final_data_valid <= 0; // Ensure line is silent
            if(counter < 24) begin // Wait 12 bytes (24 nibbles)
                counter <= counter + 1;
            end
            else begin
                STATE   <= IDLE;
                counter <= 0;
            end
            end
            
        end

default : begin STATE<=IDLE;counter<=0;final_data_valid<=0;data_valid<=0;end
endcase
end
end
endmodule