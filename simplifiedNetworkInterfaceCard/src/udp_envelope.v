module udp_envelope(
input [7:0]hps_uart_unpacked,
input clock,
output reg [63:0]envelope,
input valid,
output reg udpEnvelopeValid
);

always@(posedge clock)
begin
	if(valid)
	begin
		envelope<={16'd5000,16'd12345,16'd64,hps_uart_unpacked,8'b00000000};
		udpEnvelopeValid<=1;
	end
	else udpEnvelopeValid <=0;
end
endmodule