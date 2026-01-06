`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 26.12.2025 13:10:13
// Design Name: 
// Module Name: nibble_stitcher_tb
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


module nibble_stitcher_tb();
reg clock,rx_data_valid;
reg [7:0]data_in_reg = 8'b11001111;
reg [3:0]data_in;
wire [7:0]data_out;
wire data_out_valid;
nibble_stitcher uut(
.clock(clock),
.rx_data_valid(rx_data_valid), // Data Valid from PHY
.data_in(data_in), // 4-bit data from PHY
.data_out(data_out),
.dout_data_valid(data_out_valid)
);

always #5 clock = ~clock;

initial begin
    clock = 0;
    rx_data_valid = 0;
    #200;
    rx_data_valid = 1;
    data_in = data_in_reg[3:0];
    #10;
    data_in = data_in_reg[7:4];
    #10;
    rx_data_valid = 0;
    
    #1000;
    $finish;
end
endmodule
