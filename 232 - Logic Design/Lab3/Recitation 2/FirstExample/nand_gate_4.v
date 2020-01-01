`timescale 1ns / 1ps

module nand_gate_4(
    output x,
    input a,
    input b,
    input c,
    input d
    );

	assign x = ~(a&b&c&d);

endmodule
