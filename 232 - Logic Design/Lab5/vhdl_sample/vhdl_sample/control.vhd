  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE WORK.comp_pkg.ALL;

  ENTITY Ctrl_Subsystem IS
    PORT(Instr                  : IN    WordT      ;
         ZE, NG, CY, OV         : IN    STD_LOGIC  ;
         AddrA, AddrB, AddrC    : OUT   STD_LOGIC_VECTOR(4 DOWNTO 0);
         ALUOp                  : OUT   STD_LOGIC_VECTOR(3 DOWNTO 0);
         WrC, WrPC, WrCR, WrIR  : OUT   STD_LOGIC  ;
         Mem_ALU, PC_RA, IR_RB  : OUT   STD_LOGIC  ;
         ALU_PC, ZE_SE, Sin_Sout: OUT   STD_LOGIC  ;
         MemRd,MemWr            : OUT   STD_LOGIC  ;
         MemLength              : OUT   STD_LOGIC  ;
         MemEnable              : OUT   STD_LOGIC  ;
         MemRdy                 : IN    STD_LOGIC  ;
         IORd, IOWr             : OUT   STD_LOGIC  ;
         IOLength               : OUT   STD_LOGIC  ;
         IOEnable               : OUT   STD_LOGIC  ;
         IORdy                  : IN    STD_LOGIC  ;
         Status                 : OUT   StatusT    ;
         Clk, Reset             : IN    STD_LOGIC );
  END Ctrl_Subsystem;
  
  LIBRARY ieee;
  USE ieee.std_logic_signed.ALL;

  ARCHITECTURE behavioral OF Ctrl_Subsystem IS
      SIGNAL State: StatusT;
  BEGIN
  PROCESS                                       -- transition function
      ALIAS    Opcode : STD_LOGIC_VECTOR(5 DOWNTO 0) IS Instr(31 DOWNTO 26);
      CONSTANT Reset_delay: TIME:= 500 ps ;
      CONSTANT Ctrl_delay : TIME:= 500 ps ;
  BEGIN
    WAIT ON Clk,Reset;
    IF (Reset'EVENT AND Reset = '1') THEN
        State  <= p_reset AFTER Reset_delay;
        Status <= p_reset AFTER Reset_delay;
        WAIT UNTIL Clk = '1';
    END IF;
      
    IF (Clk'EVENT) AND (Clk = '1') THEN   
       CASE State IS
       WHEN p_reset      => Status <= fetch   AFTER Ctrl_delay;
                            State  <= fetch   AFTER Ctrl_delay;
       WHEN fetch        => Status <= execute AFTER Ctrl_delay;
                            State  <= execute AFTER Ctrl_delay;
       WHEN execute      => CASE Opcode IS
          WHEN "100000" | "100001" => State  <= memop AFTER Ctrl_delay;
                                      Status <= memop AFTER Ctrl_delay;
          WHEN "100010" | "100011" => State  <= memop AFTER Ctrl_delay;
                                      Status <= memop AFTER Ctrl_delay;
          WHEN OTHERS              => State  <= fetch AFTER Ctrl_delay;
                                      Status <= fetch AFTER Ctrl_delay;
                            END CASE;
       WHEN memop | ioop => Status <= fetch   AFTER Ctrl_delay;
                            State  <= fetch   AFTER Ctrl_delay;
       WHEN undef        => NULL;
       END CASE;
    END IF;
  END PROCESS;

  PROCESS(State,Instr,MemRdy)                   -- output function
      ALIAS    Opcode : STD_LOGIC_VECTOR( 5 DOWNTO 0) IS Instr(31 DOWNTO 26);
      ALIAS    Imm    : STD_LOGIC_VECTOR(15 DOWNTO 0) IS Instr(15 DOWNTO  0);
      ALIAS    D      : STD_LOGIC_VECTOR(15 DOWNTO 0) IS Instr(15 DOWNTO  0);
      ALIAS    PN     : STD_LOGIC_VECTOR(10 DOWNTO 0) IS Instr(10 DOWNTO  0);
    
      CONSTANT Dec_delay  : TIME:=    3 ns;
      CONSTANT Ctrl_delay : TIME:=  500 ps;
      CONSTANT MemRd_delay: TIME:= 2500 ps;
      CONSTANT MemRd_pulse: TIME:= MemRd_delay + 3 ns ;
      CONSTANT MemWr_delay: TIME:= 2500 ps;
      CONSTANT MemWr_pulse: TIME:= MemWr_delay + 3 ns ;
      
      TYPE     Ctrl_LineT IS
        RECORD
          MemOp, WrMem    : STD_LOGIC;
          RS_RB, IR_RB    : STD_LOGIC;
          WrC, WrPC, WrCR : STD_LOGIC;
          ZE_SE           : STD_LOGIC;
          ALUop           : STD_LOGIC_VECTOR(3 DOWNTO 0);
        END RECORD;

      VARIABLE Ctrl_Line  : Ctrl_LineT;

      TYPE     Ctrl_TableT IS ARRAY(NATURAL RANGE 0 TO 63) OF Ctrl_LineT;

      CONSTANT Ctrl_Table: Ctrl_TableT:=
       --     Mem   Wr   RS   IR   Wr   Wr   Wr   ZE   ALU
       --     Op    Mem  RB   RB   C    PC   CR   SE   op
       (0 => ('0', '0', '1', '1', '0', '0', '0', '0', "0000"), -- nop
        2 => ('0', '0', '1', '1', '1', '0', '1', '0', "1111"), -- not
        4 => ('0', '0', '1', '1', '1', '0', '1', '0', "1010"), -- lsh
        6 => ('0', '0', '1', '1', '1', '0', '1', '0', "1011"), -- rsh
        8 => ('0', '0', '1', '1', '1', '0', '1', '0', "1100"), -- lrt
        10=> ('0', '0', '1', '1', '1', '0', '1', '0', "1101"), -- rrt

        16=> ('0', '0', '1', '1', '1', '0', '1', '0', "0001"), -- add
        17=> ('0', '0', '1', '0', '1', '0', '1', '1', "0001"), -- adi
        18=> ('0', '0', '1', '1', '1', '0', '1', '0', "0010"), -- sub
        19=> ('0', '0', '1', '0', '1', '0', '1', '1', "0010"), -- sbi
        20=> ('0', '0', '1', '1', '1', '0', '1', '0', "0100"), -- and
        21=> ('0', '0', '1', '0', '1', '0', '1', '0', "0100"), -- ani
        22=> ('0', '0', '1', '1', '1', '0', '1', '0', "0101"), -- or
        23=> ('0', '0', '1', '0', '1', '0', '1', '0', "0101"), -- ori
        24=> ('0', '0', '1', '1', '1', '0', '1', '0', "0110"), -- xor
        25=> ('0', '0', '1', '0', '1', '0', '1', '0', "0110"), -- xri

        32=> ('1', '0', '0', '0', '1', '0', '0', '1', "0001"), -- ldb
        33=> ('1', '0', '0', '0', '1', '0', '0', '1', "0001"), -- ldw
        34=> ('1', '1', '0', '0', '0', '0', '0', '1', "0001"), -- stb
        35=> ('1', '1', '0', '0', '0', '0', '0', '1', "0001"), -- stw
        36=> ('1', '0', '0', '1', '1', '0', '0', '0', "1001"), -- irb
        37=> ('1', '0', '0', '1', '1', '0', '0', '0', "1001"), -- irw
        38=> ('1', '1', '0', '1', '0', '0', '0', '0', "1001"), -- iwb
        39=> ('1', '1', '0', '1', '0', '0', '0', '0', "1001"), -- iww

        56=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- br
        57=> ('0', '0', '1', '0', '0', '1', '0', '1', "1000"), -- bri
        48=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- brp
        49=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- brn
        50=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- bnz
        51=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- brz
        52=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- bnc
        53=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- brc
        54=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- bnv
        55=> ('0', '0', '1', '0', '0', '1', '0', '1', "0001"), -- brv
   OTHERS => ('0', '0', '1', '1', '0', '0', '0', '1', "0000")
       );

    BEGIN
    IF (State'EVENT) THEN
       CASE State IS
       WHEN undef     => NULL;
       WHEN p_reset   => ALUOp  <= "0000";
                         MemRd  <= '0';    MemWr <= '0'; 
                         MemEnable <= '0'; MemLength <= '0';
                         IORd  <= '0';     IOWr <= '0'; 
                         IOEnable <= '0';  IOLength <= '0';
       WHEN fetch     => 
                -- disable write signals from previous cycle
                WrCR     <= '0' AFTER Ctrl_delay;
                WrC      <= '0' AFTER Ctrl_delay;

                -- fetch instruction
                ALU_PC   <= '1' AFTER Ctrl_delay;
                MemLength<= '1' AFTER Ctrl_delay;
                MemEnable<= '1' AFTER Ctrl_delay;
                MemRd    <= '1' AFTER MemRd_delay, '0' AFTER MemRd_pulse;
                Sin_Sout <= '0' AFTER Ctrl_delay;            -- switch in

                -- increment PC 
                PC_RA    <= '0' AFTER Ctrl_delay;
                ALUop    <= "1110" AFTER Ctrl_delay;         -- PC + 4
                WrIR     <= '1' AFTER Ctrl_delay;
                WrPC     <= '1' AFTER Ctrl_delay;

       WHEN execute  => 
                -- disable signals from fetch cycle
                WrIR     <= '0' AFTER Ctrl_delay;
                WrPC     <= '0' AFTER Ctrl_delay;
                MemEnable<= '0' AFTER Ctrl_delay;

                -- other actions done by Instr'EVENT

       WHEN memop | ioop   => 
                -- initiate memory access
                ALU_PC   <= '0' AFTER Ctrl_delay;       -- address to memory
                MemEnable<= '1' AFTER Ctrl_delay;
                MemLength<= Opcode(0) AFTER Ctrl_delay; -- operand length
                WrC      <= Ctrl_Line.WrC AFTER Ctrl_delay;
                IF (Ctrl_Line.WrMem = '0') THEN
                  MemRd     <= '1' AFTER MemRd_delay, '0' AFTER MemRd_pulse;
                  Mem_ALU   <= '0' AFTER Ctrl_delay;
                ELSE
                  MemWr     <= '1' AFTER MemWr_delay, '0' AFTER MemWr_pulse;
                  Sin_Sout  <= '1' AFTER Ctrl_delay;
                END IF;
        END CASE;
    END IF;

    IF (Instr'EVENT) THEN
       -- decode opcode
       Ctrl_Line:= Ctrl_Table(CONV_INTEGER('0' & Opcode));

       -- decode registers
       AddrA   <= Instr(20 DOWNTO 16) AFTER Dec_delay;
       IF (Ctrl_Line.RS_RB = '0') THEN
         AddrB <= Instr(25 DOWNTO 21) AFTER Dec_delay;
       ELSE
         AddrB <= Instr(15 DOWNTO 11) AFTER Dec_delay;
       END IF;
       AddrC   <= Instr(25 DOWNTO 21) AFTER Dec_delay;

       -- decode control signals
       PC_RA   <= not(Ctrl_Line.WrPC) AFTER Ctrl_delay;
       ZE_SE   <= Ctrl_Line.ZE_SE AFTER Ctrl_delay;
       IR_RB   <= Ctrl_Line.IR_RB AFTER Ctrl_delay;
       ALUOp   <= Ctrl_Line.ALUop AFTER Ctrl_delay;
       WrPC    <= Ctrl_Line.WrPC  AFTER Ctrl_delay;
       WrCR    <= Ctrl_Line.WrCR  AFTER Ctrl_delay;

       IF (Ctrl_Line.MemOp = '0') THEN
         WrC     <= Ctrl_Line.WrC AFTER Ctrl_delay;
         Mem_ALU <= '1' AFTER Ctrl_delay;
       END IF;
    END IF;

    IF (MemRdy'EVENT AND MemRdy='1') THEN
        CASE State IS
          WHEN memop  => IF (Ctrl_Line.WrMem = '1') THEN
                                    -- deactivate data bus
                           Sin_Sout <= '0' AFTER Ctrl_delay;
                         END IF;
          WHEN OTHERS => NULL;
        END CASE;
    END IF;
    END PROCESS;
  END behavioral;
