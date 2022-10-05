module tb;
  
  reg i;
  reg s;
  wire [1:0]y;
  
  demux1x2 dut (i,s,y);
  
  initial begin
    $monitor("i=%b,s=%b,y=%b",i,s,y);
    i = 1; s = 0; #5
    s = 1; #5
    #5
    $finish;
  end
  
endmodule