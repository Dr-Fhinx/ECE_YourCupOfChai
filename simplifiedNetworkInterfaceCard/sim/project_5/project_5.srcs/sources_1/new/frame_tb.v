module frame_tb();
integer i;
reg clock,reset,hps_uart_rx;
wire fvalid;
wire [3:0]data_out;
reg [39:0] hps_uart_rx_reg = {
        1'b1, 8'hDE, 1'b0, // Byte 4
        1'b1, 8'h56, 1'b0, // Byte 3
        1'b1, 8'h01, 1'b0, // Byte 2
        1'b1, 8'hAB, 1'b0  // Byte 1
    };
frame uut(.clock(clock),.hps_uart_rx(hps_uart_rx),.reset_pin(reset),
.data_out(data_out),.final_data_valid(fvalid));

always #5 clock = ~clock;

initial 
begin
clock = 0;
reset = 1;
#200;
reset = 0;
for(i = 0; i < 40; i = i + 1) begin
            hps_uart_rx = hps_uart_rx_reg[i];
            
 #8680;
end
#1000;
$finish;
end
endmodule