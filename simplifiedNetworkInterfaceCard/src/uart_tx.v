module uart_tx (
    input  clk,         
    input  [7:0] tx_byte,
    input  tx_en,
    output reg  tx_line, 
    output reg  tx_busy  
);

    parameter CLKS_PER_BIT = 868; // 50MHz / 115200

    reg [2:0]  state;
    reg [15:0] clock_count;
    reg [2:0]  bit_index;
    reg [7:0]  tx_data;

    parameter IDLE  = 3'b000,
              START = 3'b001,
              DATA  = 3'b010,
              STOP  = 3'b011;

    initial begin
        tx_line <= 1'b1; // UART Idle is always High
        tx_busy <= 1'b0;
       state = IDLE;
    end

    always @(posedge clk) begin
        case (state)
            IDLE : begin
                tx_busy<=0;
                tx_line <= 1'b1;
                clock_count <= 0;
                bit_index   <= 0;
                if (tx_en) begin
                    tx_data <= tx_byte;
                    tx_busy <= 1'b1;
                    state   <= START;
                end else begin
                    tx_busy <= 1'b0;
                end
            end

            START : begin
                tx_line <= 1'b0; // Start bit is Low
                if (clock_count < CLKS_PER_BIT-1) begin
                    clock_count <= clock_count + 1'b1;
                end else begin
                    clock_count <= 0;
                    state       <= DATA;
                end
            end

            DATA : begin
                tx_line <= tx_data[bit_index]; // Send bits 0 to 7
                if (clock_count < CLKS_PER_BIT-1) begin
                    clock_count <= clock_count + 1'b1;
                end else begin
                    clock_count <= 0;
                    if (bit_index < 7) begin
                        bit_index <= bit_index + 1'b1;
                    end else begin
                    clock_count<=0;
                        state <= STOP;
                    end
                end
            end

            STOP : begin
            tx_data<=7'bxxxxxxxx;
                tx_line <= 1'b1; // Stop bit is High
                if (clock_count < CLKS_PER_BIT-1) begin
                    clock_count <= clock_count + 1'b1;
                end else begin
                    clock_count<=0;
                    state <= IDLE;
                    
                end
            end
        endcase
    end
endmodule