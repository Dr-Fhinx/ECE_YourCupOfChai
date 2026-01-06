module nibble_stitcher (
    input  clock,
    input  rx_data_valid, // Data Valid from PHY
    input  [3:0] data_in, // 4-bit data from PHY
    output reg [7:0] data_out,
    output reg	dout_data_valid
);

reg nibble_select; // 0 = Low, 1 = High
always @(posedge clock) 
begin
	if (!rx_data_valid) 
	begin
		nibble_select <= 0;
		dout_data_valid <= 0;
	end 
	else 
	begin
		if (nibble_select == 0)
		begin
			data_out[3:0] <= data_in;   
			dout_data_valid <= 0;
			nibble_select <= 1;
		end 
		else 
		begin
			data_out[7:4] <= data_in;   
			dout_data_valid <= 1;       
			nibble_select <= 0;
		end
   end
end
endmodule