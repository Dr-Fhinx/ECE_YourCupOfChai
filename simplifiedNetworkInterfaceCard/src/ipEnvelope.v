module ipEnvelope(
input udpEnvelopeValid, clock,
output reg [159:0]ipEnvelope_data_out,
output reg validipEnvelope
);

always@(posedge clock)
begin
if(udpEnvelopeValid)
begin
ipEnvelope_data_out <= {4'b0100,4'b0101,8'b0,16'd29,
								16'b1,3'b010,13'b0,
								8'b01000000,8'b10001,16'h0,
								32'hC0A80132,
								32'HC0A8010A
								};
validipEnvelope<=1;
end
else validipEnvelope<=0;
end
endmodule