library ieee;
use ieee.std_logic_1164.all;

entity Additional is
  port (
    A : in std_logic_vector(7 downto 0);
    B : in std_logic_vector(7 downto 0);
    sw : in std_logic_vector(3 downto 0);
    F : out std_logic_vector(7 downto 0)
  );
end entity Additional;

architecture Behavioral of Additional is
begin
  process(A, B, sw)
  begin
    CASE sw IS
      WHEN "0000" =>
        F <= not A;
      WHEN "0001" =>
        F <= not B;
      WHEN "0010" =>
        F <= A;
      WHEN "0011" =>
        F <= B;
      WHEN "0100" =>
        F <= A or B;
      WHEN "0101" =>
        F <= A and B;
      WHEN "0110" =>
        F <= A xor B;
      WHEN "0111" =>
        F <= "11111111";
      WHEN others =>
        F <= "00000000";
    END CASE;
  end process;
end architecture Behavioral;