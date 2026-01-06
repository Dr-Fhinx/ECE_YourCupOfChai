module exec_nic(
input	RX_CLK,
input	TX_CLK,
input	[3:0] RX_DATA,
input	RX_DV,
output [3:0] TX_DATA,
output TX_EN,
input  UART_RX,
output UART_TX
);

wire [7:0] rx_byte;
wire       rx_byte_valid;
wire [7:0] final_extracted_data;
wire       final_data_ready;

nibble_stitcher rx_stich(
        .clock(RX_CLK),
        .rx_data_valid(RX_DV),
        .data_in(RX_DATA),
        .data_out(rx_byte),
        .dout_data_valid(rx_byte_valid)
    );
	
parser rx_parser(
        .clock(RX_CLK),
        .data_in(rx_byte),
        .data_in_valid(rx_byte_valid),
        .real_data_out(final_extracted_data),
        .real_data_out_valid(final_data_ready)
    );
	 
frame tx(
        .clock(TX_CLK),
        .hps_uart_rx(UART_RX),
        .data_out(TX_DATA),
        .final_data_valid(TX_EN)
    );
	 
uart_tx pc_display_inst (
        .clk(MAX10_CLK1_50), 
        .tx_byte(final_extracted_data), 
        .tx_en(final_data_ready),       
        .tx_line(UART_TX),              
        .tx_busy() // Leave empty if not needed
    );
	 
	 
endmodule