library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity clkdiv is
    generic(n:integer:=50000000);
    port(clk_50MHZ:in std_logic;
         clk_1HZ:out std_logic);
end clkdiv;

architecture behavior of clkdiv is
 signal count:integer range n-1 downto 0:=n-1;
begin
  process(clk_50MHZ)
  begin
    if(clk_50MHZ'event and clk_50MHZ='1'and clk_50MHZ'last_value='0') then
      count<=count-1;
       if count>=n/2 then
          clk_1HZ<='0';
       else
          clk_1HZ<='1';
       end if;
       if count<=0 then
          count<=n-1;
       end if;
     end if;
   end process;
end behavior;
