`timescale 1ns / 1ps
module PIPO_shift_register_tb;

reg [7:0] number;
reg [1:0] p2;
reg md;
reg clk;
wire [7:0] result;
wire ovr;

PIPO_shift_register UUT(number,p2,md,clk,result,ovr);

initial begin
clk = 0;
forever 
#5 clk = ~clk ;
end

initial begin

#5 number = 8'b01101001;
   p2=2'b10;
   md=1'b1;

end
	
initial  
begin
$display("\ttime,\tnumber,\tovr,\tresult"); 
$monitor("\t%d,\t%b,\t%b,\t%b,",$time,number,ovr,result); 
end   
      
endmodule