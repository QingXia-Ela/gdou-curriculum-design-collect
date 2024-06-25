module bcd_to_7seg(
    input [3:0] bcd,
    output reg [6:0] seg  // Assuming that '0' is LED on and '1' is LED off
);
    always @(bcd)
    begin
        case(bcd)
            // gfe_dcba - segments
            4'b0000: seg = 7'b1000000; // '0'
            4'b0001: seg = 7'b1111001; // '1'
            4'b0010: seg = 7'b0100100; // '2'
            4'b0011: seg = 7'b0110000; // '3'
            4'b0100: seg = 7'b0011001; // '4'
            4'b0101: seg = 7'b0010010; // '5'
            4'b0110: seg = 7'b0000010; // '6'
            4'b0111: seg = 7'b1111000; // '7'
            4'b1000: seg = 7'b0000000; // '8'
            4'b1001: seg = 7'b0010000; // '9'
            default: seg = 7'b1111111; // Off
        endcase
    end
endmodule