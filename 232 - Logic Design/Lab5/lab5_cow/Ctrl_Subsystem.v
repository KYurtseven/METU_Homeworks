`timescale 1ns / 1ps
module Ctrl_Subsystem(
	input [31:0] Instr,
	input ZE, NG, CY, OV ,
	output reg [4:0] AddrA, AddrB, AddrC,
	output reg [3:0] ALUOp,
	output reg WrC, WrPC, WrCR, WrIR,
	output reg Mem_ALU, PC_RA, IR_RB,
	output reg ALU_PC, ZE_SE, Sin_Sout,
	output reg MemRd,MemWr,
	output reg MemLength,
	output reg MemEnable,
	input MemRdy,
	output reg [2:0] Status, // 0:p_reset, 1:fetch, 2:execute, 3:memop 00 01 10 11
	input Clk, Reset
    );
	
	localparam p_reset = 3'b00;
	localparam fetch   = 3'b01;
	localparam execute = 3'b10;
	localparam memop   = 3'b11;
	
	localparam Ctrl_delay= 0.5; //500 ps
	localparam Reset_delay= 0.5; //500 ps
	localparam Dec_delay= 3; //3 ns
	localparam MemRd_delay= 2.5; //2500 ps
	localparam MemRd_pulse= MemRd_delay + 3 ; //5500 ps
	localparam MemWr_delay= 2.5; //2500 ps
	localparam MemWr_pulse= MemWr_delay + 3 ; //5500 ps

//
//Write your code below
//

always@(Rst)
begin
	Status <=#Reset_delay p_reset;
end

always@(Clk)
begin
	if(Status == fetch) //begin fetch
	begin
		WrCR <=#Ctrl_delay 0;
		WrC <=#Ctrl_delay 0;
		
		ALU_PC <=#Ctrl_delay 1;
		MemLength <=#Ctrl_delay 1;
		MemEnable <=#Ctrl_delay 1;
		MemRd <=#MemRd_delay 1;
		Sin_Sout <=#Ctrl_delay 0;
		MemRd <=#MemRd_pulse 0;
		
		PC_RA <=#Ctrl_delay 0;
		ALUop <=#Ctrl_delay 1110;
		WrIR <=#Ctrl_delay 1;
		WrPC <=#Ctrl_delay 1;
		
		Status <=#Ctrl_delay 2;
		
	end
	if(Status == execute) //begin execute
		WrIR <=#Ctrl_delay 0;
		WrPC <=#Ctrl_delay 0;
		MemEnable <=#Ctrl_delay 0;
		
		AddrA <=#Dec_delay Instr[20:16];
		
		case(Instr[31:26])
		6'b011000 : // XOR
			begin
				AddrB <=#Dec_delay Instr[15:11];
				PC_RA <=#Ctrl_delay 1;
				ZE_SE <=#Ctrl_delay 0;
				IR_PB <=#Ctrl_delay 1;
				ALUOp <=#Ctrl_delay 0110;
				WrPC <=#Ctrl_delay 0;
				WrCR <=#Ctrl_delay 1;
				WrC <=#Ctrl_delay 1;
				Mem_ALU <=#Ctrl_delay 1;
				Status <=#Ctrl_delay 1;
			end
		6'b010001 : // ADDI
			begin
				AddrB <=#Dec_delay Instr[15:11];
				PC_RA <=#Ctrl_delay 1;
				ZE_SE <=#Ctrl_delay 1;
				IR_PB <=#Ctrl_delay 0;
				ALUOp <=#Ctrl_delay 0001;
				WrPC <=#Ctrl_delay 0;
				WrCR <=#Ctrl_delay 1;
				WrC <=#Ctrl_delay 1;
				Mem_ALU <=#Ctrl_delay 1;
				Status <=#Ctrl_delay 1;
			end
		6'b100001 : //LOADW
			begin
				AddrB <=#Dec_delay Instr[25:21];
				PC_RA <=#Ctrl_delay 1;
				ZE_SE <=#Ctrl_delay 1;
				IR_PB <=#Ctrl_delay 0;
				ALUOp <=#Ctrl_delay 0001;
				WrPC <=#Ctrl_delay 0;
				WrCR <=#Ctrl_delay 0;
				Status <=#Ctrl_delay 3;
			end
		6'b100010 : //STRB
			begin
				AddrB <=#Dec_delay Instr[25:21];
				PC_RA <=#Ctrl_delay 1;
				ZE_SE <=#Ctrl_delay 1;
				IR_PB <=#Ctrl_delay 0;
				ALUOp <=#Ctrl_delay 0001;
				WrPC <=#Ctrl_delay 0;
				WrCR <=#Ctrl_delay 0;
				Status <=#Ctrl_delay 3;
			end
		default:
			begin
				Status <=#Ctrl_delay 1;
			end
		endcase
		
		AddrC <=#Dec_delay Instr[25:21];
		
	begin
	end
	if(Status == memop) //begin memop
	begin
		AlU_PC <=#Ctrl_delay 0;
		MemEnable <=#Ctrl_delay 1;
		MemLength <=#Ctrl_delay Instr[26];
		case(Instr[31:26])
			6'b100001 : //LOADW
			begin
				WrC <=#Ctrl_delay 1;
				MemRd <=#MemRd_delay 1;
				MemRd <=#MemRd_pulse 0;
				Mem_ALU <=#Ctrl_delay 0;
			end
			6'b100010 : //STRB
			begin
				WrC <=#Ctrl_delay 0;
				MemWr <=#Ctrl_delay 1;
				MemWr <=#MemWr_delay 1;
				MemWr <=#MemWr_pulse 0;
				if(MemRdy)
				begin
					Sin_Sout <=#Ctrl_delay 0;
				end
				else
				begin
					Sin_Sout <=#Ctrl_delay 1;
				end
			end
			default:
			begin
			end
		endcase
		Status <=#Ctrl_delay 1;
	end
	
	else	//begin reset
	begin
		ALUOp  <= 0000;
		MemRd  <= 0;
		MemWr <= 0;
		MemEnable <= 0;
		MemLength <= 0;
		Status <=#Ctrl_delay 1;
	end
end
endmodule
