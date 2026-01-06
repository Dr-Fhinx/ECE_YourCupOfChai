`timescale 1ns/1ps

module tb_parser;

    reg clock;
    reg [7:0] data_in;
    reg data_in_valid;
    wire [7:0] real_data_out;
    wire real_data_out_valid;

    // Instantiate the parser
    parser uut (
        .clock(clock),
        .data_in(data_in),
        .data_in_valid(data_in_valid),
        .real_data_out(real_data_out),
        .real_data_out_valid(real_data_out_valid)
    );

    // Clock generation: 10ns period
    initial clock = 0;
    always #5 clock = ~clock;

    // Test data: define a frame
    reg [7:0] frame [0:33]; // Example: SFD + Dest MAC + Src MAC + Type + IP + UDP + Payload

    initial begin
        // Initialize signals
        data_in = 0;
        data_in_valid = 0;

        // Wait for reset
        #10;

        // Example frame:
        // SFD = 0xD5
        // Dest MAC = AABBCCDDEEFF
        // Src MAC = 112233445566
        // Type = 0x0800 (IPv4)
        // IP header 20 bytes (dummy)
        // UDP header 8 bytes (dummy)
        // Payload 4 bytes (0xDE 0xAD 0xBE 0xEF)
        
        frame[0]  = 8'hD5; // SFD

        // Dest MAC (AABBCCDDEEFF)
        frame[1]  = 8'hAA;
        frame[2]  = 8'hBB;
        frame[3]  = 8'hCC;
        frame[4]  = 8'hDD;
        frame[5]  = 8'hEE;
        frame[6]  = 8'hFF;

        // Src MAC (112233445566)
        frame[7]  = 8'h11;
        frame[8]  = 8'h22;
        frame[9]  = 8'h33;
        frame[10] = 8'h44;
        frame[11] = 8'h55;
        frame[12] = 8'h66;

        // Type field = 0x0800
        frame[13] = 8'h08;
        frame[14] = 8'h00;

        // IP header (dummy 20 bytes)
        frame[15] = 8'h45; frame[16] = 8'h00; frame[17] = 8'h00; frame[18] = 8'h28;
        frame[19] = 8'h12; frame[20] = 8'h34; frame[21] = 8'h00; frame[22] = 8'h00;
        frame[23] = 8'h40; frame[24] = 8'h11; frame[25] = 8'hA6; frame[26] = 8'hBC;
        frame[27] = 8'hC0; frame[28] = 8'hA8; frame[29] = 8'h01; frame[30] = 8'h01;
        frame[31] = 8'hC0; frame[32] = 8'hA8; frame[33] = 8'h01; frame[34] = 8'h02;

        // UDP header 8 bytes
        frame[35] = 8'h1F; frame[36] = 8'h90; frame[37] = 8'h1F; frame[38] = 8'h90;
        frame[39] = 8'h00; frame[40] = 8'h08; frame[41] = 8'h00; frame[42] = 8'h00;

        // Payload 4 bytes
        frame[43] = 8'hDE; frame[44] = 8'hAD; frame[45] = 8'hBE; frame[46] = 8'hEF;

        // Feed the frame byte by byte
        integer i;
        for (i = 0; i <= 46; i = i + 1) begin
            @(posedge clock);
            data_in <= frame[i];
            data_in_valid <= 1;
        end

        // Stop sending data
        @(posedge clock);
        data_in_valid <= 0;

        // Wait a few cycles to capture payload
        #50;

        $finish;
    end

    // Monitor outputs
    initial begin
        $display("Time\tdata_in\tdata_valid\treal_data_out\treal_data_out_valid");
        $monitor("%0t\t%h\t%b\t\t%h
