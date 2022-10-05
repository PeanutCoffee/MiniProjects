module cyclic_lamp (clock,
                    light);
    input clk;
    output reg [0:2] light;
    parameter S0  = 0, S1  = 1, S2  = 2;
    parameter RED = 3’b100, GREEN = 3’b010, YELLOW = 3’b001;
    reg [0:1] state;
    always @(posedge clk)
        case (state)
            S0: state      <= S1;
            S1: state      <= S2;
            S2: state      <= S0;
            default: state <= S0;
        endcase
        always @(state)
            case (state)
                S0: light      = RED;
                S1: light      = GREEN;
                S2: light      = YELLOW;
                default: light = RED;
            endcase
        endmodule
