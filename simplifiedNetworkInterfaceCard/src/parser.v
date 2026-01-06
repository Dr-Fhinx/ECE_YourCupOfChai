module parser(
input clock,
input [7:0]data_in,
input data_in_valid,
output reg [7:0]real_data_out,
output reg real_data_out_valid
);

reg [47:0]dest_mac_add =  48'h112233445566,src_mac_add = 48'hAABBCCDDEEFF, dest_mac_reg, src_mac_reg;
reg [15:0] type_field_reg;
reg [2:0]STATE;
reg [4:0]counter;
reg dest_mac_valid,src_mac_valid,type_field_valid;
parameter	IDLE = 3'b000,
				CHCK_SFD = 3'b001,
				CHCK_DEST_MAC = 3'b010,
				CHCK_SRC_MAC = 3'b011,
				CHCK_TYPE_FIELD = 3'b100,
				CHCK_IP_HEADER = 3'b101,
				CHCK_UDP_HEADER = 3'b110,
				CHCK_PAYLOAD = 3'b111;
				
always@(posedge clock)
begin
	if(data_in_valid)
	begin
		case(STATE)
			IDLE	:	begin
			                 dest_mac_valid<=0;
			                 src_mac_valid<=0;
			                 type_field_valid<=0;
							real_data_out_valid <=0;
							counter<=0;
							STATE<=CHCK_SFD;
						end
			
			CHCK_SFD	:	begin
								if(data_in == 8'hd5)
								begin
									STATE<=CHCK_DEST_MAC;
								end
							end
			
			CHCK_DEST_MAC : begin
									dest_mac_reg[(5-counter)*8 +: 8] <= data_in;
									if (counter < 5) 
									begin
										counter <= counter + 1'b1;
									end 
									else 
									begin
										counter <= 0;
										if ({data_in, dest_mac_reg[39:0]} == src_mac_add) 
										begin
											dest_mac_valid<=1;
											STATE <= CHCK_SRC_MAC;
										end
										else 
										begin
											dest_mac_valid<=0;
											STATE <= IDLE;
										end
									end
								end
								
			CHCK_SRC_MAC : begin
									if(dest_mac_valid)
									begin
									src_mac_reg[(5-counter)*8 +: 8] <= data_in;
									if (counter < 5) 
									begin
										counter <= counter + 1'b1;
									end 
									else 
									begin
										counter <= 0;
										if ({data_in, src_mac_reg[39:0]} == dest_mac_add) 
										begin
											src_mac_valid<=1;
											STATE <= CHCK_TYPE_FIELD;
										end
										else 
										begin
											src_mac_valid<=0;
											STATE <= IDLE;
										end
									end
									end
								end
									
            CHCK_TYPE_FIELD: begin
                               if(src_mac_valid) begin
                               type_field_reg[counter*8 +: 8] <= data_in;
                                 counter <= counter + 1;

                                  if(counter == 1) begin  // After receiving 2nd byte
                                      if(type_field_reg == 16'h0800) begin
                                      counter <= 0;
                                         type_field_valid <= 1;
                                         STATE <= CHCK_IP_HEADER;
                                         end else begin
                                               counter <= 0;
                                            type_field_valid <= 0;
                                           STATE <= IDLE; // go back if type mismatch
                                         end
                                         end
                                          end
                               end

									
			CHCK_IP_HEADER	:	begin
										if(type_field_valid == 1)
										begin
											if(counter<19)
											begin
												counter <= counter+1;
											end
											else
											begin
												counter<=0;
												STATE<=CHCK_UDP_HEADER;
											end
										end
									end
									
			CHCK_UDP_HEADER	:	begin
										if(counter<7)
										begin
											counter <= counter+1;
										end
										else
										begin
											counter<=0;
											STATE<=CHCK_PAYLOAD;
										end
									end
									
            CHCK_PAYLOAD :      begin
                                    if (data_in_valid) 
                                    begin
                                        real_data_out <= data_in;
                                        real_data_out_valid <= 1;
                                    end
                                    else 
                                    begin
                                        real_data_out_valid <= 0;
                                        STATE <= IDLE;
                                    end
                                end
									
			default	:	begin counter<=0; real_data_out_valid<=0;type_field_valid<=0;src_mac_valid<=0;dest_mac_valid<=0; end
		endcase
	end


end
endmodule			

