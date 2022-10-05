module demux1x2(i,s,y);
  
  input i;
  input s;
  output [1:0] y;

  wire w;
  
  not g1(w,s);
  and g2(y[0],i,w);
  and g3(y[1],i,s);
  
endmodule