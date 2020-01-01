`timescale 1ns / 1ps

module Board232 (
	input mclk,
	input [3:0] btn,
	input [7:0] sw,
	output [7:0] led,
	output reg [6:0] seg,
	output reg [3:0] an,
	output dp,
	output [2:1] OutBlue,
	output [2:0] OutGreen,
	output [2:0] OutRed,
	output HS,
	output VS
    );
   assign dp = 1'b1;
	assign led[3:0]=0;
	initial begin
		an[3:0]  = 4'b1111;
   end
 
  // You can change this value
  parameter _B = 4'b1111;
  
  
	// adjust board clock
   reg [26:0] mclk_counter;
	initial mclk_counter<= 0;
	always @(posedge mclk) mclk_counter = mclk_counter+1;

	
	wire [3:0] Cond; 
	reg [7:0] tmp_digit;
	
	ALU INSTANCE(
	sw[7:4],//A,
	_B,
	sw[3:0], //ALUop
	led[7:4], //C
	Cond // Z,N,C,V
	);


   always @(mclk_counter[18:17])
	begin
		case (mclk_counter[18:17])
			2'b00:
				begin
					an = 4'b1110;
					tmp_digit = Cond[0];
				end
			2'b01:
				begin
					an = 4'b1101;
					tmp_digit = Cond[1];
				end
			2'b10:
				begin
					an = 4'b1011;
					tmp_digit = Cond[2];
				end
			default:
				begin
					an = 4'b0111;
					tmp_digit = Cond[3];
				end
		endcase	
		case (tmp_digit)
			4'd0: seg <= ~7'h3F;
			4'd1: seg <= ~7'h06;
			4'd2: seg <= ~7'h5B;
			4'd3: seg <= ~7'h4F;
			4'd4: seg <= ~7'h66;
			4'd5: seg <= ~7'h6D;
			4'd6: seg <= ~7'h7D;
			4'd7: seg <= ~7'h07;
			4'd8: seg <= ~7'h7F;
			4'd9: seg <= ~7'h6F;
			4'd10: seg <= ~7'h77;
			4'd11: seg <= ~7'h7C;
			4'd12: seg <= ~7'h39;
			4'd13: seg <= ~7'h5E;
			4'd14: seg <= ~7'h79;
			4'd15: seg <= ~7'h71;
			default: seg <= ~7'b0000000;
		endcase

	end
	// VGA
	assign OutBlue = 0;
	assign OutGreen = 0;
	assign OutRed = 0;
	assign HS = 0;
	assign VS = 0;
endmodule