module tb;
  
  reg i;
  reg [2:0]s;
  wire [7:0]y;
  
  demux1x8 dut (i,s,y);
  
  initial begin
    $monitor("i=%b,s=%b,y=%b",i,s,y);
    i = 1; s = 3'b000; #5
    s = 3'b001; #5
    s = 3'b010; #5
    s = 3'b011; #5
    s = 3'b100; #5
    s = 3'b101; #5
    s = 3'b110; #5
    s = 3'b111;
    #5
    $finish;
  end
  
endmodule