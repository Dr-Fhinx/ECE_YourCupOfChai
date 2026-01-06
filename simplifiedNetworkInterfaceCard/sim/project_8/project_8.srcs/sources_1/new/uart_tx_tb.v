`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 26.12.2025 14:12:48
// Design Name: 
// Module Name: uart_tx_tb
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


module uart_tx_tb();

reg clk, tx_en;
reg [7:0]tx_byte;
reg [7:0]tx_byte_reg = 8'b01110010;
wire tx_line;
wire tx_busy;
uart_tx uut(
  .clk(clk),         
  .tx_byte(tx_byte),
  .tx_en(tx_en),
  .tx_line(tx_line), 
  .tx_busy(tx_busy)
  );  
  
  always #5 clk = ~clk;
  
  initial
  begin
  clk = 0;
  tx_en = 0;
  #100;
  tx_byte = tx_byte_reg;
  #10;
  tx_en = 1;
  #100000;
  tx_en = 0;
  #100000;
  $finish;
  end
endmodule
