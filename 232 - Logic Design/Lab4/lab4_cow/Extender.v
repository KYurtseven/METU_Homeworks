`timescale 1ns / 1ps
module Extender(
input [31:0] X_in,
input ZE_SE,
output reg [31:0] X_out
    );

localparam Ext_delay= 0.5; //500 ps

//
//Write your code below
//
always@(*)
begin
	if(ZE_SE)
		begin
			if(X_in[15] == 1)
				begin
					X_out[31:16] <= 1;
					X_out[15:0] <=#Ext_delay X_in[15:0];
				end
			else
				begin
					X_out[31:16] <= 0;
					X_out[15:0] <=#Ext_delay X_in[15:0];
				end
		end
	else
		begin
			X_out[31:16] <= 0;
			X_out[15:0] <=#Ext_delay X_in[15:0];
		end
end

endmodule
