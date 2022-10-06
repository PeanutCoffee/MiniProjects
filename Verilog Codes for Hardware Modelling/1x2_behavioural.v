module demux1x2(i,s,y);
  
  input i;
  input s;
  output reg [1:0] y;

  always@(i,s)
    case(s)
      1'b0: begin
        		y[0] = i;
        		y[1] = 0;
      		end
      1'b1: begin
       			y[0] = 0;
        		y[1] = i;
      		end
    endcase
endmodule