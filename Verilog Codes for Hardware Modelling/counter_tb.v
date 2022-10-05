`timescale 1ns / 1ps

module N_bit_sync_counter_tb;

parameter N = 4; 

reg x,ud,clk,clr;
wire [N-1:0] q;
wire y;

N_bit_sync_counter UUT(x,ud,clk,clr,q,y);

initial begin
clk = 0;
forever 
#5 clk = ~clk ;
end

initial begin

#5 clr = 1'b1;
#5 clr = 1'b0;
   ud=1'b0;

x = 1'b1; 
end
	
initial  
begin
$display("\ttime,\tq,\ty"); 
$monitor("\t%d,\t%b,\t%b",$time,q,y); 
end   
      
endmodule