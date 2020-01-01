`timescale 1ns / 1ps

module binary_to_eseg(
    input A,
    input B,
    input C,
    input D,
    output eSeg
    );

	 wire p1, p2, p3, p4;
	 
	 nand_gate_2 g1(p1, C, ~D);
	 nand_gate_2 g2(p2, A, B);
	 nand_gate_2 g3(p3, ~B, ~D);
	 nand_gate_2 g4(p4, A, C);
	 nand_gate_4 g5(eSeg, p1, p2, p3, p4);

endmodule
