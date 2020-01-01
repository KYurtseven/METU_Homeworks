`timescale 1ns / 1ps

module Reg_File(
input [4:0] AddrA, 
input [4:0] AddrB, 
input [4:0] AddrC, 
output reg [31:0] DataA, 
output reg [31:0] DataB, 
input [31:0] DataC, 
input WrC,
input Reset,
input Clk
    );

localparam RF_delay = 4; //4 ns

reg [31:0] my_register [31:0];
integer i;
always@(posedge Clk or posedge Reset)
begin
	if (Reset)
		begin
			for(i = 0; i<32; i = i + 1)
				my_register[i] <= 0;
		end
	else
		begin
			DataA <=#RF_delay my_register[AddrA];
			DataB <=#RF_delay my_register[AddrB];
			if (WrC)
				begin
					my_register[AddrC] <=#RF_delay DataC;
				end
		end
end
//
//Write your code below
//

endmodule
