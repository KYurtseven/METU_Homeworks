  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;

  ENTITY Switch IS
    PORT(A    : INOUT STD_LOGIC_VECTOR;
         B_out: OUT   STD_LOGIC_VECTOR;
         C_in : IN    STD_LOGIC_VECTOR;
         Sel  : IN    STD_LOGIC      );
  END Switch;

  ARCHITECTURE behavioral OF Switch IS
  BEGIN
    PROCESS(A, C_in, Sel)
      CONSTANT Switch_delay: TIME := 500 ps;
      CONSTANT dataZ: STD_LOGIC_VECTOR(A'RANGE):= (OTHERS => 'Z');
    BEGIN
      IF (Sel = '0') THEN
         B_out <= A AFTER Switch_delay;
         A     <= dataZ;
      ELSE
         A     <= C_in AFTER Switch_delay;
      END IF;
    END PROCESS;
  END behavioral;