module crc32_4bit (
    input clk,
    input reset,      // Reset to 1'b1 to initialize CRC
    input data_valid,  // Pulse high when feeding a nibble
    input [3:0] data_in,
    output [31:0] crc_out
);

    reg [31:0] crc_reg;

    // Ethernet CRC32 initialization value is all 1's
    initial crc_reg = 32'hFFFFFFFF;

    always @(posedge clk) begin
        if (reset) begin
            crc_reg <= 32'hFFFFFFFF;
        end else if (data_valid) begin
            // 4-bit parallel CRC logic
            crc_reg <= next_crc32_nibble(crc_reg, data_in);
        end
    end

    // The result must be bit-inverted for the final FCS
     assign crc_out = ~crc_reg;

    // Function to calculate the next CRC state based on 4 bits
    function [31:0] next_crc32_nibble;
        input [31:0] current_crc;
        input [3:0] data;
        reg [31:0] crc;
        begin
            crc = current_crc;
            // Process 4 bits one by one (this synthesizes into combinational logic)
            repeat(4) begin
                if ((crc[31] ^ data[0]) == 1'b1)
                    crc = {crc[30:0], 1'b0} ^ 32'h04C11DB7;
                else
                    crc = {crc[30:0], 1'b0};
                data = data >> 1;
            end
            next_crc32_nibble = crc;
        end
    endfunction

endmodule