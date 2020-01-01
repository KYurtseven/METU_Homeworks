  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.std_logic_unsigned.ALL;
  USE WORK.comp_pkg.ALL;

  ENTITY Reg_File IS
    PORT(AddrA, AddrB, AddrC : IN  STD_LOGIC_VECTOR(4 DOWNTO 0);
         DataA, DataB        : OUT WordT;
         DataC               : IN  WordT;
         WrC                 : IN  STD_LOGIC ;
         Reset, Clk          : IN  STD_LOGIC);
  END Reg_File;

  ARCHITECTURE behavioral OF Reg_File IS
    TYPE     RegFileT IS ARRAY(0 to 31) OF WordT;
    SIGNAL   GPR : RegFileT    ;
  BEGIN
    PROCESS(AddrA,AddrB)           -- output function
      CONSTANT RF_delay   : TIME := 4 ns;
    BEGIN
      DataA <= GPR(CONV_INTEGER(AddrA)) AFTER RF_delay;
      DataB <= GPR(CONV_INTEGER(AddrB)) AFTER RF_delay;
    END PROCESS;

    PROCESS(Reset,Clk)             -- transition function
    BEGIN
      IF (Reset'EVENT and (Reset = '1')) THEN
        FOR i IN 0 TO 31 LOOP
          GPR(i) <= (OTHERS => '0');
        END LOOP;
      END IF;

      IF (Clk'EVENT AND Clk = '1' AND WrC  = '1') THEN
          GPR(CONV_INTEGER(AddrC)) <= DataC;
      END IF;
    END PROCESS;
  END behavioral;
