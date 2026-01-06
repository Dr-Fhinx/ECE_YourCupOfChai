`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 25.12.2025 19:29:04
// Design Name: 
// Module Name: CRC32_4bit_tb
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


module CRC32_4bit_tb();
reg clk,reset,data_valid;
reg [3:0]data_in;
wire [31:0]crc_out;

crc32_4bit uut (
.clk(clk),
.reset(reset),
.data_valid(data_valid),
.data_in(data_in),
.crc_out(crc_out)
);

always #5 clk = ~clk;

initial
begin
    clk = 0;
    reset = 0;
    #100;
    data_valid = 0;
    #100;
    data_in = 4'b0101;
    data_valid = 1;
    #500;
    reset = 1;
    #200;
    reset = 0;
    data_in = 4'b1010;
    data_valid = 1;
    #1000;
    $finish;
end
endmodule
