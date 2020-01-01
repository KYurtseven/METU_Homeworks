  LIBRARY ieee;
  USE ieee.std_logic_1164.all;
  USE WORK.comp_pkg.ALL;

  ENTITY processor IS
    PORT (MemAddr  : OUT    MAddrT   ;  -- memory address bus
          MemData  : INOUT  WordT    ;  -- data bus to/from memory 
          MemLength: OUT    STD_LOGIC;  -- memory operand length
          MemRd    : OUT    STD_LOGIC;  -- memory read control signal
          MemWr    : OUT    STD_LOGIC;  -- memory write control signal
          MemEnable: OUT    STD_LOGIC;  -- memory enable signal
          MemRdy   : IN     STD_LOGIC;  -- memory completion signal
          IOAddr   : OUT    IOAddrT  ;  -- I/O address bus
          IOData   : INOUT  WordT    ;  -- data bus to/from I/O
          IOLength : OUT    STD_LOGIC;  -- I/O operand length
          IORd     : OUT    STD_LOGIC;  -- I/O read control signal
          IOWr     : OUT    STD_LOGIC;  -- I/O write control signal
          IOEnable : OUT    STD_LOGIC;  -- memory enable signal
          IORdy    : IN     STD_LOGIC;  -- I/O completion signal
          Status   : OUT    StatusT  ;  -- processor status signal
          Reset    : IN     STD_LOGIC;  -- reset signal
          Clk      : IN     STD_LOGIC); -- clock signal
  END processor;
