`timescale 1ns / 1ps
module float_point_adder_tb;

reg clk;
reg add;
reg [15:0] number1;
reg [15:0] number2;
wire [15:0] result;
wire ready;

floating_point_adder UUT(clk, add, number1, number2, result, ready);

initial begin
clk = 0;
forever
#5 clk = ~clk;
end

initial begin
add=0;
number1=0;
number2=0;

#1000;
add = 1;
number1= 16'b0100101100010000;
number2= 16'b0101000011101100;
#100;
add = 0;

#1000;
add = 1;
number1= 16'b1100101100010000;
number2= 16'b0101000011101100;
#100;
add = 0;

#1000;
add = 1;
number1= 16'b0100101100010000;
number2= 16'b1101000011101100;
#100;
add = 0;

#1000;
add = 1;
number1= 16'b1100101100010000;
number2= 16'b1101000011101100;
#100;
add = 0;

#1000;
add = 1;
number1= 16'b0011100000000000;
number2= 16'b0011100000000000;
#100;
add = 0;

end
endmodule
