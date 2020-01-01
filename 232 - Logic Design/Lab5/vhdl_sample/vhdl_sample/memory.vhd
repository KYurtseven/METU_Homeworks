  LIBRARY ieee;
  USE ieee.std_logic_1164.all;
  USE WORK.comp_pkg.ALL;
  ENTITY Memory IS
    PORT (Addr     : IN     MAddrT   ; -- memory address bus
          Length   : IN     STD_LOGIC; -- byte/word operand
          Rd, Wr   : IN     STD_LOGIC; -- access control signals
          Enable   : IN     STD_LOGIC; -- enable signal
          Rdy      : OUT    STD_LOGIC; -- access completion signal
          Data     : INOUT  WordT   ); -- memory data bus
  END Memory;


  LIBRARY ieee;
  USE ieee.std_logic_unsigned.ALL;

  ARCHITECTURE behavioral OF Memory IS
    CONSTANT Tmem  : TIME :=   8 ns;   -- nanoseconds
    CONSTANT Td    : TIME := 200 ps;   -- picoseconds
    CONSTANT Tsu   : TIME := 200 ps;   -- picoseconds
  BEGIN
  PROCESS (Rd, Wr, Enable)
    CONSTANT byte_l: STD_LOGIC:= '0';  -- constant declarations
    CONSTANT word_l: STD_LOGIC:= '1';
                                       -- memory declaration
    CONSTANT MaxMem   : NATURAL := 16#FFFFFF#;  -- 2**24 bytes
    TYPE     MemArrayT IS ARRAY(0 TO MaxMem-1) OF ByteT;
    VARIABLE Mem  : MemArrayT;
                                       -- working variables
    VARIABLE tAddr : NATURAL;
    VARIABLE tData : WordT  ;
    VARIABLE tCtrls: STD_LOGIC_VECTOR(2 DOWNTO 0);
    
    BEGIN
      tCtrls:= Rd & Wr & Enable; -- group signals for simpler decoding
      CASE tCtrls IS
                                             -- output to tri-state
        WHEN "000" => Data <= (OTHERS => 'Z') AFTER Td;
                         
        WHEN "011" =>                        -- write access; 
                                             -- indicate module busy
              Rdy <= '0' AFTER Td, '1' AFTER Tmem;
              IF (Length = byte_l) THEN      -- read address
                tAddr:= CONV_INTEGER(Addr);  -- bit-vector to integer
                                             -- from pkg std_logic_unsigned
              ELSE
                tAddr:= CONV_INTEGER(Addr(23 DOWNTO 2) & "00");
              END IF;
              CASE Length IS
                WHEN byte_l => Mem(tAddr)  := (Data( 7 DOWNTO  0));
                WHEN word_l => Mem(tAddr)  := (Data( 7 DOWNTO  0));
                               Mem(tAddr+1):= (Data(15 DOWNTO  8));
                               Mem(tAddr+2):= (Data(23 DOWNTO 16));
                               Mem(tAddr+3):= (Data(31 DOWNTO 24));
                WHEN OTHERS => NULL;
              END CASE;

        WHEN "101" =>                        -- read access
                                             -- indicate module busy
              Rdy <= '0' AFTER Td, '1' AFTER Tmem;
              IF (Length = byte_l) THEN      -- read address
                tAddr:= CONV_INTEGER(Addr);  -- bit-vector to integer
              ELSE
                tAddr:= CONV_INTEGER(Addr(23 DOWNTO 2) & "00");
              END IF;
              CASE Length IS
                WHEN byte_l => tData( 7 DOWNTO  0):= (Mem(tAddr));
                WHEN word_l => tData( 7 DOWNTO  0):= (Mem(tAddr));
                               tData(15 DOWNTO  8):= (Mem(tAddr+1));
                               tData(23 DOWNTO 16):= (Mem(tAddr+2));
                               tData(31 DOWNTO 24):= (Mem(tAddr+3));
                WHEN OTHERS => NULL;
              END CASE;
              Data <= tData AFTER Tmem; -- deliver data

        WHEN OTHERS => NULL;           -- memory not enabled
      END CASE;
    END PROCESS;

                                       -- timing verifications
    ASSERT NOT (Rd'EVENT AND Rd='1' AND NOT Addr'STABLE(Tsu))
       REPORT "Read address setup time violation";

    ASSERT NOT (Rd'EVENT AND Rd='1' AND NOT Enable'STABLE(Tsu))
       REPORT "Read enable setup time violation";

    ASSERT NOT (Wr'EVENT AND Wr='1' AND NOT Addr'STABLE(Tsu))
       REPORT "Write address setup time violation";

    ASSERT NOT (Wr'EVENT AND Wr='1' AND NOT Enable'STABLE(Tsu))
       REPORT "Write enable setup time violation";

  END behavioral;
