`timescale 1ns / 1ps
module testbench_REGISTER(
    );

reg [31:0] Data_in;
wire [31:0] Data_out;
reg Wr;
reg Reset;
reg Clk;


initial Clk =0;
always #5 Clk = ~Clk;

Register32 INS(Data_in, Data_out,Wr, Reset, Clk);

initial 
begin
	$display("Starting Testbehch");
	Reset=0;
	Wr=1'b0;
	Data_in=32'b01010101010101010101010101010101;
	#1; //1
	Wr=1'b1;
	#6; //7
	if(Data_out==Data_in) $display("time:%0d, PASSED",$time);
	else $display("time:%0d, ERROR in Data_out value. The value should be %b",$time,Data_in);
	
	#10;//17
	$display("Testbench Finished");
	$finish;
end
endmodule
