module ALU (X,
            Y,
            Z,
            Sign,
            Zero,
            Carry,
            Parity,
            Overflow);
    input [15:0] X, Y;
    output [15:0] Z;
    output Sign, Zero, Carry, Parity, Overflow;
    
    assign {Carry, Z} = X + Y; // 16-bit addition!
    assign Sign       = Z[15];
    assign Zero       = ~|Z;
    assign Parity     = ~^Z;
    assign Overflow   = (X[15] & Y[15] & ~Z[15]) |(~X[15] & ~Y[15] & Z[15]);
    
endmodule
