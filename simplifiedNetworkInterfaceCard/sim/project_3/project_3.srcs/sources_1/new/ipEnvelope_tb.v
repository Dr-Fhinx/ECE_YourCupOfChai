`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 25.12.2025 17:31:53
// Design Name: 
// Module Name: ipEnvelope_tb
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


module ipEnvelope_tb();

reg udpEnvelopeValid, clock;
wire [159:0]ipEnvelope_data_out;
wire validipEnvelope;

ipEnvelope uut (
    .udpEnvelopeValid(udpEnvelopeValid),
    .clock(clock),
    .ipEnvelope_data_out(ipEnvelope_data_out),
    .validipEnvelope(validipEnvelope)
);
always #5 clock = ~clock;
initial
begin
    clock=0;
    #100;
    udpEnvelopeValid = 0;
    #200;
    udpEnvelopeValid = 1;
    #1000;
    $finish;
end
endmodule
