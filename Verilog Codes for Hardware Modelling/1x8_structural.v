`include "1x2_dataflow.v"
module demux1x8(i,s,y);
  
  input i;
  input [2:0]s;
  output [7:0] y;
  
  wire [5:0]w;

  demux1x2 D1 (i,   s[2],w[1:0]);
  demux1x2 D2 (w[0],s[1],w[3:2]);
  demux1x2 D3 (w[1],s[1],w[5:4]);
  demux1x2 D4 (w[2],s[0],y[1:0]);
  demux1x2 D5 (w[3],s[0],y[3:2]);
  demux1x2 D6 (w[4],s[0],y[5:4]);
  demux1x2 D7 (w[5],s[0],y[7:6]);
  
endmodule