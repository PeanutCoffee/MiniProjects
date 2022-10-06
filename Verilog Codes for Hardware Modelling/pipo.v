module PIPO_shift_register(number,p2,md,clk,result,ovr);

input [7:0] number;
input [1:0] p2;
input md,clk;

output reg [7:0] result;
output reg ovr;

initial ovr =1'b0;

always @ (posedge clk)
begin
if (md==1)
{ovr,result} <= number << p2;
else 
result <= number >> p2;
end

endmodule