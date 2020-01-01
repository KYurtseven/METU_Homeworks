`timescale 1ns / 1ps
module Computer(
input Reset, 
input Clk
);


wire [2:0] Status; // processor status signal 0:p_reset, 1:fetch, 2:execute, 3:memop

//
//Write your code below
//

wire [31:0] MemData1; // from memdata
wire [31:0] MemData2; // to memdata
wire [23:0] Addryedek;
wire [4:0] Yedekler;

assign Length_yedek = Yedekler[0];
assign Rd_yedek = Yedekler[1];
assign Wr_yedek = Yedekler[2];
assign Enable_yedek = Yedekler[3];
assign Rdy_yedek = Yedekler[4];

Memory MyMemory(
.Addr(Addryedek),
.Length(Length_yedek),
.Rd(Rd_yedek),
.Wr(Wr_yedek),
.Enable(Enable_yedek),
.Rdy(Rdy_yedek),
.DataIn(MemData2), 
.DataOut(MemData1)
);


Processor MyProcessor(
.MemAddr(Addryedek)  , // memory address bus
.fromMemData(MemData1) , // data bus from memory 
.toMemData(MemData2), // data bus to memory 
.MemLength(Length_yedek), // memory operand length
.MemRd(Rd_yedek), // memory read control signal
.MemWr(Wr_yedek), // memory write control signal
.MemEnable(Enable_yedek), // memory enable signal
.MemRdy(Rdy_yedek), // memory completion signal
.Status(Status), // processor status signal 0:p_reset, 1:fetch, 2:execute, 3:memop
.Reset(Reset), // reset signal
.Clk(Clk)// clock signal
);
endmodule