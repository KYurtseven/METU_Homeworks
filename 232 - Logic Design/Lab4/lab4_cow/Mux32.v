`timescale 1ns / 1ps
module Mux32(
input [31:0] A_in,
input [31:0] B_in,
input Sel,
output reg [31:0]Data_out 
    );


/*  DO NOT EDIT THIS FILE   */

localparam Mux_delay= 0.5; //500 ps

always @(A_in or B_in or Sel)
begin
	if (Sel ==1'b0) Data_out <=#Mux_delay A_in;
	else Data_out <=#Mux_delay B_in;
end

endmodule
