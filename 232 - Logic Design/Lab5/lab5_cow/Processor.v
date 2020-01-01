`timescale 1ns / 1ps
module Processor(
output  [23:0] MemAddr  , // memory address bus
input [31:0] fromMemData  , // data bus from memory 
output  [31:0] toMemData, // data bus to memory 
output  MemLength, // memory operand length
output  MemRd, // memory read control signal
output  MemWr, // memory write control signal
output  MemEnable, // memory enable signal
input MemRdy, // memory completion signal
output  [2:0] Status, // processor status signal 0:p_reset, 1:fetch, 2:execute, 3:memop
input Reset , // reset signal
input Clk // clock signal
    );

//
//Write your code below
//
wire [31:0] Instryedek;
wire zeyedek;
wire ngyedek;
wire cyyedek;
wire ovyedek;
wire [4:0] AddrAyedek;
wire [4:0] AddrByedek;
wire [4:0] AddrCyedek;
wire [4:0] ALUOpyedek;
wire [3:0] WRyedekler;
wire [5:0] Digeryedekler;

assign WrC_yedek = WRyedekler[0];  
assign WrPC_yedek = WRyedekler[1];
assign WrCR_yedek = WRyedekler[2];  
assign WrIR_yedek = WRyedekler[3];

assign Mem_ALU_yedek = Digeryedekler[0];
assign PC_RA_yedek = Digeryedekler[1];
assign IR_RB_yedek = Digeryedekler[2];
assign ALU_PC_yedek = Digeryedekler[3];
assign ZE_SE_yedek = Digeryedekler[4];
assign Sin_Sout_yedek = Digeryedekler[5];

Ctrl_Subsystem ControlSubsytem(
.Instr(Instryedek),
.ZE(zeyedek),
.NG(ngyedek),
.CY(cyyedek),
.OV(ovyedek),
.AddrA(AddrAyedek), 
.AddrB(AddrByedek), 
.AddrC(AddrCyedek),
.ALUOp(ALUOpyedek),
.WrC(WrC_yedek), 
.WrPC(WrPC_yedek), 
.WrCR(WrCR_yedek), 
.WrIR(WrIR_yedek),
.Mem_ALU(Mem_ALU_yedek), 
.PC_RA(PC_RA_yedek), 
.IR_RB(IR_RB_yedek),
.ALU_PC(ALU_PC_yedek), 
.ZE_SE(ZE_SE_yedek), 
.Sin_Sout(Sin_Sout_yedek),
.MemRd(MemRd),
.MemWr(MemWr),
.MemLength(MemLength),
.MemEnable(MemEnable),
.MemRdy(MemRdy),
.Status(Status), // 0:p_reset, 1:fetch, 2:execute, 3:memop
.Clk(Clk),
.Reset(Reset),
);

Data_Subsystem DataSubystem(
.fromMemData(fromMemData),
.toMemData(toMemData),
.Instr(Instryedek),
.ZE(zeyedek),
.NG(ngyedek),
.CY(cyyedek),
.OV(ovyedek),
.AddrA(AddrAyedek), 
.AddrB(AddrByedek), 
.AddrC(AddrCyedek),
.ALUOp(ALUOpyedek),
.WrC(WrC_yedek), 
.WrPC(WrPC_yedek), 
.WrCR(WrCR_yedek), 
.WrIR(WrIR_yedek),
.Mem_ALU(Mem_ALU_yedek), 
.PC_RA(PC_RA_yedek), 
.IR_RB(IR_RB_yedek),
.ALU_PC(ALU_PC_yedek), 
.ZE_SE(ZE_SE_yedek), 
.Sin_Sout(Sin_Sout_yedek),
.Clk(Clk),
.Reset(Reset),
);

endmodule
