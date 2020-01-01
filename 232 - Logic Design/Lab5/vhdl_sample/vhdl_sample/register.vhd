  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;

  ENTITY Reg IS
    PORT(Data_in : IN  STD_LOGIC_VECTOR;
         Data_out: OUT STD_LOGIC_VECTOR;
         Wr      : IN  STD_LOGIC ;
         Reset   : IN  STD_LOGIC ;
         Clk     : IN  STD_LOGIC);
  END Reg;

  ARCHITECTURE behavioral OF Reg IS
  BEGIN
    PROCESS(Wr,Reset,Clk)
      CONSTANT Reg_delay: TIME := 2 ns;
      VARIABLE BVZero: STD_LOGIC_VECTOR(Data_in'RANGE):= (OTHERS => '0');
    BEGIN
      IF (Reset = '1') THEN
         Data_out <= BVZero AFTER Reg_delay;
      END IF;

      IF (Clk'EVENT AND Clk = '1' AND Wr = '1') THEN
         Data_out <= Data_in AFTER Reg_delay;
      END IF;
    END PROCESS;
  END behavioral;
