module demux1x2(i,s,y);
  
  input i;
  input s;
  output [1:0] y;

  assign y[0] = i&~s;
  assign y[1] = i&s;
  
endmodule