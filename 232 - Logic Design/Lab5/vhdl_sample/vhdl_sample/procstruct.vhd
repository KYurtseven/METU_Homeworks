  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE WORK.comp_pkg.ALL, WORK.ALL;

  ARCHITECTURE structural OF Processor IS
    SIGNAL Instr                 : WordT;  
    SIGNAL ZE, NG, CY, OV        : STD_LOGIC;
    SIGNAL AddrA, AddrB, AddrC   : STD_LOGIC_VECTOR(4 DOWNTO 0);
    SIGNAL ALUOp                 : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL WrC, WrPC, WrCR, WrIR : STD_LOGIC;
    SIGNAL Mem_ALU, PC_RA, IR_RB : STD_LOGIC;
    SIGNAL ALU_PC, ZE_SE, SinSout: STD_LOGIC;

  BEGIN
    P1: ENTITY Data_Subsystem
        PORT MAP (MemAddr, MemData, IOAddr, IOData,
                  Instr, ZE, NG, CY, OV, AddrA, AddrB, AddrC, ALUOp,
                  WrC, WrPC, WrCR, WrIR, Mem_ALU, PC_RA, IR_RB, ALU_PC,
                  ZE_SE, SinSout, Clk, Reset);

    P2: ENTITY Ctrl_Subsystem
        PORT MAP (Instr, ZE, NG, CY, OV, AddrA, AddrB, AddrC, ALUOp,
                  WrC, WrPC, WrCR, WrIR, Mem_ALU, PC_RA, IR_RB, ALU_PC,
                  ZE_SE, SinSout, MemRd, MemWr, MemLength, MemEnable,
                  MemRdy, IORd, IOWr, IOLength, IOEnable, IORdy, Status, 
                  Clk, Reset);
  END structural;
