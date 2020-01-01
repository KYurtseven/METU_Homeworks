  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;

  ENTITY Mux IS
    PORT(A_in,B_in: IN  STD_LOGIC_VECTOR;
         Sel      : IN  STD_LOGIC       ;
         Data_out : OUT STD_LOGIC_VECTOR);
  END Mux;

  ARCHITECTURE behavioral OF Mux IS
  BEGIN
    PROCESS(A_in, B_in, Sel)
      CONSTANT Mux_delay: TIME := 500 ps;
    BEGIN
      IF (Sel = '0') THEN
         Data_out <= A_in AFTER Mux_delay;
      ELSE
         Data_out <= B_in AFTER Mux_delay;
      END IF;
    END PROCESS;
  END behavioral;
