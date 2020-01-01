`timescale 1ns / 1ps

module MemoryTest ();

reg [23:0] addr;
reg length, rd, wr, enable;
wire rdy;
reg [31:0] in;
wire [31:0] out;

Memory memory(addr, length, rd, wr, enable, rdy, in, out);

initial begin
    addr = 24'b0;
    length = 0;
    rd = 0;
    wr = 0;
    enable = 0;
    in = 32'b00000000000000000000000000000000;
end

initial begin
$monitor("%4d t | %h: %h", $time, addr, out);

$dumpfile("Memory.vcd");
$dumpvars;

enable = 1;

// ----------------------------------------------------------------------------
// (a) Writing bytes
// ----------------------------------------------------------------------------
#10 addr = 24'hFFFFF0; in = 8'hE0;
#1 wr = 1; #1 wr = 0;
#10 addr = 24'hFFFFF1; in = 8'hC0;
#1 wr = 1; #1 wr = 0;

#10 addr = 24'hFFFFF2; in = 8'hAD;
#1 wr = 1; #1 wr = 0;

#10 addr = 24'hFFFFF3; in = 8'hDE;
#1 wr = 1; #1 wr = 0;

// ----------------------------------------------------------------------------
// (b) Reading bytes
// ----------------------------------------------------------------------------
length = 1;

#10 addr = 24'b000000000000111111110000;
#1 rd = 1; #1 rd = 0;

#10 addr = 24'hFFFFF0;
#1 rd = 1; #1 rd = 0;

// ----------------------------------------------------------------------------
// (c) Writing words
// ----------------------------------------------------------------------------
length = 1;

#10 addr = 24'hCAFEF; in = 32'h DEADBEEF;
#1 wr = 1; #1 wr = 0;

#10 addr = 24'hBABEF; in = 32'hB16B00B5;
#1 wr = 1; #1 wr = 0;

// ----------------------------------------------------------------------------
// (d) Reading words
// ----------------------------------------------------------------------------
#10 addr = 24'hFFFFF0;
#1 rd = 1; #1 rd = 0;

#10 addr = 24'hCAFEF;
#1 rd = 1; #1 rd = 0;

#10 addr = 24'hBABEF;
#1 rd = 1; #1 rd = 0;

#30 $finish;
end

endmodule