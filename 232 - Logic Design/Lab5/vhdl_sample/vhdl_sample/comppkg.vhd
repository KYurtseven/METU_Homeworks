  LIBRARY ieee;
  USE ieee.std_logic_1164.all;

  PACKAGE comp_pkg IS
    SUBTYPE WordT   IS STD_LOGIC_VECTOR(31 DOWNTO 0);
    SUBTYPE MAddrT  IS STD_LOGIC_VECTOR(23 DOWNTO 0);
    SUBTYPE IOAddrT IS STD_LOGIC_VECTOR(10 DOWNTO 0);
    SUBTYPE ByteT   IS STD_LOGIC_VECTOR( 7 DOWNTO 0);
    TYPE    StatusT IS (undef, p_reset, fetch, execute, memop, ioop);

    FUNCTION get_carry(RA_Data,RB_Data,Imm,Opcode: STD_LOGIC_VECTOR)
             RETURN STD_LOGIC;
    FUNCTION get_ovf (RA_Data,RB_Data,Imm,Opcode: STD_LOGIC_VECTOR)
             RETURN STD_LOGIC;
    FUNCTION get_cc (RA_Data,RB_Data,Opcode: STD_LOGIC_VECTOR)
             RETURN STD_LOGIC_VECTOR;
  END comp_pkg;

  PACKAGE BODY comp_pkg IS
    FUNCTION get_carry(RA_Data,RB_Data,Imm,Opcode: STD_LOGIC_VECTOR)
             RETURN STD_LOGIC
    IS
      VARIABLE cy: STD_LOGIC:= '0';
    BEGIN
        -- description of carry generation included here
        RETURN(cy);
    END get_carry;

    FUNCTION get_ovf (RA_Data,RB_Data,Imm,Opcode: STD_LOGIC_VECTOR)
             RETURN STD_LOGIC
    IS
        VARIABLE ovf: STD_LOGIC:= '0';
    BEGIN
        -- description of overflow generation included here
        RETURN(ovf);
    END get_ovf;

    FUNCTION get_cc (RA_Data,RB_Data,Opcode: STD_LOGIC_VECTOR)
             RETURN STD_LOGIC_VECTOR
    IS
        VARIABLE cc: STD_LOGIC_VECTOR(3 DOWNTO 0):= "0000";
    BEGIN
        -- description of cc generation included here
        RETURN(cc);
    END get_cc;
  END comp_pkg;
