module m4x1 (x,s,y);

input [3:0] x;
input [1:0] s;
output y;

wire w2,w4,w5,w6,w7,w8,w9,w10;

or g5(y,w7,w8,w9,w10);
and g1(w7,x[0],w2,w4);
and g2(w8,x[1],w2,s[1]);
and g3(w9,x[2],s[0],w4);
and g4(w10,x[3],s[0],s[1]);
not g7(w2,s[0]);
not g6(w4,s[1]);
    
endmodule