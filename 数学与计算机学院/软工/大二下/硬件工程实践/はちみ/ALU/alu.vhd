library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;
entity ALU is
    port (
        oper: in std_logic_vector(3 downto 0);
        a, b: in std_logic_vector(7 downto 0);
        Co: out std_logic_vector(7 downto 0);
        OV, CY: out std_logic
    );
end entity ALU;
architecture arc of ALU is
    signal f_tmp, Co_tmp: std_logic_vector(7 downto 0);
    signal OV_tmp, CY_tmp: std_logic;
begin
    process (oper, a, b)
    begin
        case oper is
            when "0000" =>
                f_tmp <= a - b;
                Co_tmp <= f_tmp(7 downto 0);
            when "0001" =>
                f_tmp <= a + b;
                Co_tmp <= f_tmp(7 downto 0);
            when "0010" =>
                Co_tmp <= a and b;
            when "0011" =>
                Co_tmp <= a or b;
            when "0100" =>
                Co_tmp <= not a;
            when "0101" =>
                Co_tmp <= a xor b;
            when "0110" =>
                Co_tmp <= a nand b;
            when "0111" =>
                Co_tmp <= a nor b;
            when others =>
                f_tmp <= (others => '0');
                Co_tmp <= (others => '0');
        end case;
		-- 检查是否发生了溢出
        if (oper = "0000") then -- 如果是减法
            if (a(7) = '0' and b(7) = '1' and f_tmp(7) = '1') then
                OV_tmp <= '1'; -- 真溢出
            else
                OV_tmp <= '0'; -- 假溢出
            end if;
        elsif (oper = "0001") then -- 如果是加法
            if (a(7) = b(7) and f_tmp(7) /= a(7)) then
                OV_tmp <= '1'; -- 真溢出
            else
                OV_tmp <= '0'; -- 假溢出
            end if;
        else
            OV_tmp <= '0';
        end if;
        -- 检查是否发生了进位
        if (oper = "0001") then -- 如果是加法
            if (f_tmp(7) = '1') then
                CY_tmp <= '1'; -- 真进位
            else
                CY_tmp <= '0'; -- 假进位
            end if;
        else
            CY_tmp <= '0';
        end if;
    end process;
    Co <= Co_tmp;
    OV <= OV_tmp;
    CY <= CY_tmp;
end arc;