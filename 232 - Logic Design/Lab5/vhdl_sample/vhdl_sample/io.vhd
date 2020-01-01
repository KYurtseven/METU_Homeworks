  LIBRARY ieee;
  USE ieee.std_logic_1164.all;
  USE WORK.comp_pkg.ALL;
  ENTITY IO IS
    PORT (Addr    : IN     IOAddrT  ; -- I/O address bus
          Length  : IN     STD_LOGIC; -- byte/word control
          Rd, Wr  : IN     STD_LOGIC; -- I/O access control
          Enable  : IN     STD_LOGIC; -- I/O enable control
          Rdy     : OUT    STD_LOGIC; -- I/O completion signal
          Data    : INOUT  WordT   ); -- I/O data bus
  END IO;