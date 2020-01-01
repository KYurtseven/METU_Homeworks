  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE WORK.ALL, WORK.comp_pkg.ALL;

  ENTITY Computer IS
    PORT (Reset, Clk : IN STD_LOGIC);
  END Computer;

  ARCHITECTURE structural OF Computer IS
    SIGNAL MemAddr          : MAddrT   ;  -- memory address bus 
    SIGNAL MemLength, MemRd : STD_LOGIC;  -- memory control signals
    SIGNAL MemWr, MemEnable : STD_LOGIC;  
    SIGNAL MemRdy           : STD_LOGIC;  -- memory status signal
    SIGNAL MemData          : WordT    ;  -- memory data bus

    SIGNAL IOAddr           : IOAddrT  ;  -- I/O address bus
    SIGNAL IOLength, IORd   : STD_LOGIC;  -- I/O control signals
    SIGNAL IOWr, IOEnable   : STD_LOGIC;  
    SIGNAL IORdy            : STD_LOGIC;  -- I/O status signal
    SIGNAL IOData           : WordT    ;  -- I/O data bus

    SIGNAL Status           : StatusT;

  BEGIN
    U1: ENTITY Memory
        PORT MAP (MemAddr, MemLength, MemRd, MemWr, MemEnable,
                  MemRdy, MemData);

    U2: ENTITY IO
        PORT MAP (IOAddr, IOLength, IORd, IOWr, IOEnable,
                  IORdy, IOData);

    U3: ENTITY Processor
        PORT MAP (MemAddr, MemData, MemLength, MemRd, MemWr, 
                  MemEnable, MemRdy,  
                  IOAddr,  IOData,  IOLength,  IORd,  IOWr,  
                  IOEnable, IORdy, 
                  Status, Reset, Clk);
  END structural;
