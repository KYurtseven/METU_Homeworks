  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.std_logic_signed.ALL;
  USE WORK.comp_pkg.ALL;

  ENTITY ALU IS
    PORT(A, B: IN  STD_LOGIC_VECTOR(31 DOWNTO 0);
         Op  : IN  STD_LOGIC_VECTOR( 3 DOWNTO 0);
         C   : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
         Cond: OUT STD_LOGIC_VECTOR( 3 DOWNTO 0));
  END ALU;

  ARCHITECTURE behavioral OF ALU IS
  BEGIN
    PROCESS(A,B,Op)
      CONSTANT ALU_delay  : TIME := 6 ns;
    BEGIN
      CASE Op IS
        WHEN "0000" => C <= (OTHERS => '0') AFTER ALU_delay;
        WHEN "0001" => C <= A + B           AFTER ALU_delay;
        WHEN "0010" => C <= A - B           AFTER ALU_delay;
        WHEN "0011" => C <= (OTHERS => '0') AFTER ALU_delay;
        WHEN "0100" => C <= A and B         AFTER ALU_delay;
        WHEN "0101" => C <= A or  B         AFTER ALU_delay;
        WHEN "0110" => C <= A xor B         AFTER ALU_delay;
        WHEN "0111" => C <= (OTHERS => '0') AFTER ALU_delay;
        WHEN "1000" => C <= A               AFTER ALU_delay;
        WHEN "1001" => C <= B               AFTER ALU_delay;
        WHEN "1010" => C <= A(30 DOWNTO 0) & '0'   AFTER ALU_delay;
        WHEN "1011" => C <= '0' & A(31 DOWNTO 1)   AFTER ALU_delay;
        WHEN "1100" => C <= A(30 DOWNTO 0) & A(31) AFTER ALU_delay;
        WHEN "1101" => C <= A(0) & A(31 DOWNTO 1)  AFTER ALU_delay;
        WHEN "1110" => C <= A + 4           AFTER ALU_delay;
        WHEN "1111" => C <= not(A)          AFTER ALU_delay;
        WHEN OTHERS => NULL;
      END CASE;
      Cond <= get_cc(A,B,Op) AFTER ALU_delay;
    END PROCESS;
  END behavioral;
