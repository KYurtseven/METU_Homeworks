`timescale 1ns / 1ps
module Data_Subsystem(
output  [23:0] MemAddr,
input [31:0] fromMemData,
output  [31:0] toMemData,
output  [31:0] Instr,
output  ZE,
output  NG,
output  CY,
output  OV,
input [4:0] AddrA,
input [4:0] AddrB,
input [4:0] AddrC,
input [3:0] ALUop,
input WrC,
input WrPC,
input WrCR,
input WrIR,
input Mem_ALU,
input PC_RA,
input IR_RB,
input ALU_PC,
input ZE_SE,
input Sin_Sout,
input Clk,
input Reset
    );
	
//
//Write your code below
//PS:Interconnections between all data subsystem components should be given below: 

wire [31:0] B_out_temp;
wire [31:0] Extndr_temp;
wire [31:0] Data_A_temp;
wire [31:0] Data_B_temp;
wire [31:0] Data_C_temp;
wire [23:0] PCout_temp;
wire [31:0] Ain_temp;
wire [31:0] Bin_temp;
wire [31:0] ALUdata_temp;
wire [3:0] Cond_temp; 
//Switch
Switch32 Switch(
.A_in(fromMemData),
.A_out(toMemData),
.B_out(B_out_temp),
.C_in(Data_B_temp),
.Sel(Sin_Sout)
);

//Register IR
Register32 RegisterIR(
.Data_in(B_out_temp),
.Data_out(Instr),
.Wr(WrIR),
.Reset(Reset), 
.Clk(Clk)
);

//Extender
Extender Extender(
.X_in(Instr),
.ZE_SE(ZE_SE),
.X_out(Extndr_temp)
);

//MUX1
Mux32 Mux1(
.A_in(B_out_temp),
.B_in(ALUdata_temp),
.Sel(Mem_ALU),
.Data_out(Data_C_temp) 
);
//MUX2
Mux32 Mux2(
.A_in({8'b00000000,PCout_temp}),
.B_in(Data_A_temp),
.Sel(PC_RA),
.Data_out(Ain_temp) 
);
//MUX3
Mux32 Mux3(
.A_in(Extndr_temp),
.B_in(Data_B_temp),
.Sel(IR_RB),
.Data_out(Bin_temp) 
);
//MUX4
Mux24 Mux4(
.A_in(ALUdata_temp[23:0]),
.B_in(PCout_temp),
.Sel(ALU_PC),
.Data_out(MemAddr)
);
//Register File
Reg_File Reg_File(
.AddrA(AddrA), 
.AddrB(AddrB), 
.AddrC(AddrC), 
.DataA(Data_A_temp), 
.DataB(Data_B_temp), 
.DataC(Data_C_temp), 
.WrC(WrC),
.Reset(Reset),
.Clk(Clk)
);
//Register4 ZNCV
Register4 ZNCV(
.Data_in(Cond_temp),
.Data_out({ZE,NG,CY,OV}),
.Wr(WrCR), 
.Reset(Reset), 
.Clk(Clk)
);
//PC
Register24 PC(
.Data_in(ALUdata_temp[23:0]),
.Data_out(PCout_temp),
.Wr(WrPC), 
.Reset(Reset), 
.Clk(Clk)
);

ALU ALU(
.A(Ain_temp),
.B(Bin_temp),
.ALUop(ALUop),
.C(ALUdata_temp),
.Cond(Cond_temp) 
);


endmodule
