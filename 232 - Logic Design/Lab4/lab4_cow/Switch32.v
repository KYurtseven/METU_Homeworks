`timescale 1ns / 1ps

module Switch32(
input [31:0] A_in,
output reg [31:0] A_out,
output reg [31:0] B_out,
input [31:0] C_in,
input Sel
    );
	 
localparam Switch_delay= 0.5; //500 ps	 

//
//Write your code below
//
always@(*)
begin
	if(Sel)
		A_out <=#Switch_delay C_in;
	else
		B_out <=#Switch_delay A_in;
end
    
endmodule
