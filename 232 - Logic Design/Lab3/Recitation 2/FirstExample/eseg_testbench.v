
module testBench;
	wire w1, w2, w3, w4, w5;

	binary_to_eseg device(w1, w2, w3, w4, w5);
	test_bToESeg tester(w1, w2, w3, w4, w5);

endmodule

module test_bToESeg (
		output reg A,B,C,D,
		input eSeg);

	initial
		begin
			$monitor($time,,,
				"A=%b B=%b C=%b D=%b eSeg=%b",
				A,B,C,D,eSeg);

			// waveform for simulating binaryToESeg driver
			#10;
			$display("Setting all inputs to 0");
			A=0; B=0; C=0; D=0;

			#10;
			$display("Setting D to 1");
			D=1;
			
			#10;
			$display("Setting C to 1, D to 0");
			C=1; D=0;
			
			#10;
			$display("Ending simulation");
			$finish;
		end
endmodule


