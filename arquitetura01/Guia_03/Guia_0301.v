/*
 Guia_0301.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0301;
// define data
 reg [5:0] a = 8'b0000_1010 ; // binary
 reg [7:0] b = 8'b0000_1101 ; // binary
 reg [5:0] c = 8'b0010_1001; // binary
 reg [6:0] d = 8'b0010_1111 ; // binary   
 reg [7:0] e = 8'b0011_0100 ; // binary
 reg [5:0] f = 0 ; // binary
 reg [7:0] g = 0 ; // binary
 reg [5:0] h = 0 ; // binary
 reg [6:0] i = 0 ; // binary
 reg [7:0] j = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0301 - Tests" );
 f = ~a+1;
 $display ( "a = %8b -> C1(a) = %6b -> C2(a) = %8b", a, ~a, f );
 g = ~b+1;
 $display ( "b = %8b -> C1(b) = %8b -> C2(b) = %7b", b, ~b, g );
 h = ~c+1;
 $display ( "c = %8b -> C1(c) = %8b -> C2(c) = %6b", c, ~c, h );
 i = ~d+1;
 $display ( "d = %8b -> C1(d) = %8b -> C2(d) = %7b", d, ~d, i );
 j = ~e+1;
 $display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, ~e, j );
 end // main
endmodule // Guia_0301

/* Registro de Resultados

01a.)
a) C1,6 (1010(2))   = X(2) => Saída: C1(a) = 110101
b) C1,8 (1101(2))   = X(2) => Saída: C1(b) = 11110011 
c) C2,6 (101001(2)) = X(2) => Saída: C2(c) = 010111
d) C2,7 (101111(2)) = X(2) => Saída: C2(d) = 1010001
e) C2,8 (110100(2)) = X(2) => Saída: C2(e) = 11001100

*/