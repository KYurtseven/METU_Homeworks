`timescale 1ns / 1ps
module Register32(
input [31:0] Data_in,
output reg[31:0] Data_out,
input Wr, //Sync.
input Reset, //Async.
input Clk
    );

//
//Write your code below
//
always@(posedge Clk or posedge Reset)
begin
	if(Reset)
		Data_out = 0;
	else
		if(Wr)
			Data_out = Data_in;
end
	
endmodule
