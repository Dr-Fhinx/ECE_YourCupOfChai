`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 25.12.2025 16:10:48
// Design Name: 
// Module Name: uart_data_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module udp_envelope_tb();
integer i;
reg [13:0]hps_uart_rx_wire = 13'b1101011000111;
reg hps_uart_rx_reg;
reg clock;
wire [63:0] data_out;
wire valid, invalid;
udp_envelope uut (
        .hps_uart_rx(hps_uart_rx_reg), 
        .clock(clock), 
        .envelope(data_out), 
        .invalid(invalid), 
        .valid(valid) 
    );
    
    always #5 clock = ~clock;
 initial
 begin
 clock = 0;
 hps_uart_rx_reg = 0;
        #100;
 for(i =0;i<13;i=i+1)
 begin
    hps_uart_rx_reg=hps_uart_rx_wire[12-i];
    #8680;
 end

 #1000;
 $finish;
  end
endmodule
