/*
 Guia_0302.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0302;
// define data
 reg [5:0] a = 8'b0011_1001 ; // binary
 reg [7:0] b = 8'hb2 ; // hexadecimal
 reg [5:0] c = 8'b0010_1101; // binary
 reg [9:0] d = 9'o146 ; // octal    
 reg [7:0] e = 8'h6f ; // hexadecimal
 reg [5:0] f = 0 ; // binary
 reg [7:0] g = 0 ; // binary
 reg [5:0] h = 0 ; // binary
 reg [9:0] i = 0 ; // binary
 reg [7:0] j = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0302 - Tests" );
 f = ~a+1;
 $display ( "a = %8b -> C1(a) = %6b -> C2(a) = %8b", a, ~a, f );
 g = ~b+1;
 $display ( "b = %8b -> C1(b) = %8b -> C2(b) = %7b", b, ~b, g );
 h = ~c+1;
 $display ( "c = %8b -> C1(c) = %8b -> C2(c) = %6b", c, ~c, h );
 i = ~d+1;
 $display ( "d = %9b -> C1(d) = %9b -> C2(d) = %9b", d, ~d, i );
 j = ~e+1;
 $display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, ~e, j );
 end // main
endmodule // Guia_0302

/* Registro de Resultados

02a.)
a.) C1,6 (321(4)) = X(2) => Saída: C1(a) = 000110
b.) C1,8 (B2(16)) = X(2) => Saída: C1(b) = 01001101
c.) C2,6 (231(4)) = X(2) => Saída: C2(c) = 010011
d.) C2,10 (146(8))= X(2) => Saída: C2(d) = 1110011010
e.) C2,8 (6F(16)) = X(2) => Saída: C2(e) = 10010001

*/