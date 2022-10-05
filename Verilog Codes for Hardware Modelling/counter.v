module N_bit_sync_counter(x,ud,clk,clr,q,y);

parameter N = 4;

input x,ud,clk,clr;

output reg [N-1:0] q;
output reg y;

always @ (negedge clk,posedge clr)
if (clr==1) 
  begin
  q<=0;
  y<=0;
  end
else
if (x == 1) 
  if (ud==1) {y,q} <= q + 1'b1;
  else
  {y,q} <= q - 1'b1;
endmodule