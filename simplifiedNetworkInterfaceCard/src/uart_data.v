module uart_data(
input hps_uart_rx,
input clock,
output reg [7:0]data_out,
output reg invalid,valid
);

reg hps_uart_rx_reg;
reg [15:0]counter;
reg [4:0]increment;
reg [1:0]STATE;

parameter START = 2'b00,
			 WORK = 2'b01,
			 DONE = 2'b10;
			 
always@(posedge clock)
begin
	hps_uart_rx_reg<=hps_uart_rx;
	case(STATE)
		START: begin
            
            counter <= 0;
            increment <= 0;
            // The "Opener" waits for the falling edge trigger
            if(hps_uart_rx_reg == 1 && hps_uart_rx == 0) begin
                STATE <= WORK;
                invalid <= 0;
            end
				else invalid <= 1;
        end
		WORK:begin
					valid <= 0;
					if(increment<=8)
						begin
						if(counter<=868)
						begin
							if(counter==434)
							begin
								data_out[increment-1]<=hps_uart_rx;
							end
						counter<=counter+1;
						end
						else
							begin
								increment <=increment+1;
								counter<=0;
						end
					end
					else
					begin
						if({hps_uart_rx_reg,hps_uart_rx} == 2'b11 || {hps_uart_rx_reg,hps_uart_rx} == 2'b01) STATE<=DONE;
						else invalid<=1;
					end
			  end
		DONE:begin
					valid<=1;
					STATE<=START;
					increment<=0;
			  end
		default: begin STATE<=START; counter<=0; increment<=0;end
	endcase
end
endmodule	 