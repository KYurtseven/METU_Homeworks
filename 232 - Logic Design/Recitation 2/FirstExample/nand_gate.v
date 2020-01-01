`timescale 1ns / 1ps

module nand_gate_2(
    output x,
    input a,
    input b
    );
	 
 	assign x = ~(a&b);

endmodule
