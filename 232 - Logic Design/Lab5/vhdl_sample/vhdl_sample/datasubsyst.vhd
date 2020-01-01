  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE WORK.comp_pkg.ALL, WORK.ALL;
  ENTITY Data_Subsystem IS
    PORT(MemAddr                : OUT   MAddrT    ;
         MemData                : INOUT WordT     ;
         IOAddr                 : OUT   IOAddrT   ;
         IOData                 : INOUT WordT     ;
         Instr                  : OUT   WordT     ;
         ZE, NG, CY, OV         : OUT   STD_LOGIC ;
         AddrA, AddrB, AddrC    : IN    STD_LOGIC_VECTOR(4 DOWNTO 0);
         ALUOp                  : IN    STD_LOGIC_VECTOR(3 DOWNTO 0);
         WrC, WrPC, WrCR, WrIR  : IN    STD_LOGIC ;
         Mem_ALU, PC_RA, IR_RB  : IN    STD_LOGIC ;
         ALU_PC, ZE_SE, Sin_Sout: IN    STD_LOGIC ;
         Clk, Reset             : IN    STD_LOGIC);
  END Data_Subsystem;

  ARCHITECTURE structural OF Data_Subsystem IS
    SIGNAL DataA, DataB, DataC : WordT     ;
    SIGNAL Ain  , Bin          : WordT     ;
    SIGNAL ALUdata, IRdata     : WordT     ;
    SIGNAL tMemdata            : WordT     ;
    SIGNAL Cond, CRout         : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL IRreg, IRext        : WordT     ;
    SIGNAL PCout               : WordT:= (OTHERS => '0');

  BEGIN
    ALU1: ENTITY ALU
         PORT MAP(Ain,Bin,ALUop,ALUdata,Cond);
    GPR: ENTITY Reg_File
         PORT MAP(AddrA,AddrB,AddrC,DataA,DataB,DataC,
                                        WrC,Reset,Clk);
    PC:  ENTITY Reg
         PORT MAP(ALUdata(23 DOWNTO 0),PCout(23 DOWNTO 0),
                                       WrPC,Reset,Clk);
    CR:  ENTITY Reg
         PORT MAP(Cond,CRout,WrCR,Reset,Clk);

         ZE <= CRout(0);  CY <= CRout(1);
         NG <= CRout(2);  OV <= CRout(3);

    IR:  ENTITY Reg
         PORT MAP(tMemData,IRReg,WrIR,Reset,Clk);

         Instr <= IRReg;

    MX1: ENTITY Mux
         PORT MAP(tMemData,ALUdata,Mem_ALU,DataC);
    MX2: ENTITY Mux
         PORT MAP(PCout,DataA,PC_RA,Ain);
    ZSE: ENTITY Extender
         PORT MAP(IRreg,ZE_SE,IRext);
    MX3: ENTITY Mux
         PORT MAP(IRext,DataB,IR_RB,Bin);
    MX4: ENTITY Mux
         PORT MAP(ALUdata(23 DOWNTO 0),PCout(23 DOWNTO 0),
                                       ALU_PC,MemAddr);
    SL : ENTITY Switch
         PORT MAP(MemData,tMemData,DataB,Sin_Sout);
  END structural;
