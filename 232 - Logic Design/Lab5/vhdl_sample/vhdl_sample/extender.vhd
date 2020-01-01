  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;

  ENTITY Extender IS
    PORT(X_in  : IN  STD_LOGIC_VECTOR(31 DOWNTO 0);
         ZE_SE : IN  STD_LOGIC                    ;
         X_out : OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
  END Extender;

  ARCHITECTURE behavioral OF Extender IS
  BEGIN
    PROCESS(X_in, ZE_SE)
      CONSTANT Ext_delay: TIME := 500 ps;
    BEGIN
      IF (ZE_SE = '0') THEN
         X_out(31 DOWNTO 16) <= (OTHERS => '0') AFTER Ext_delay;
         X_out(15 DOWNTO  0) <= X_in(15 DOWNTO 0) AFTER Ext_delay;
      ELSE
         X_out(31 DOWNTO 16) <= (OTHERS => X_in(15)) AFTER Ext_delay;
         X_out(15 DOWNTO  0) <= X_in(15 DOWNTO 0) AFTER Ext_delay;
      END IF;
    END PROCESS;
  END behavioral;
