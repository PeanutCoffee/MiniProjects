`timescale 1ns / 1ps

module SIPO_shift_register_tb;
	
reg x;
reg clk;
wire [0:3] q;

SIPO_shift_register UUT(x,clk,q);

initial begin
clk = 0;
forever 
#5 clk = ~clk ;
end

initial begin

 #5 x = 1'b0;
#10 x = 1'b1;
#10 x = 1'b0;
#10 x = 1'b1;
#10 x = 1'b1;

end
	
initial  
begin
$display("\ttime,\tx,\tq"); 
$monitor("\t%d,\t%b,\t%b",$time,x,q); 
end   
      
endmodule