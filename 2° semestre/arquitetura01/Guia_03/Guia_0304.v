/*
 Guia_0304.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0304;
// define data
 reg signed [11:0] a = 11'b011111_010010; // binary
 reg signed [11:0] b = 11'b101001_010001 ; // binary
 reg signed [5:0] c = 8'b0001_10 ; // binary
 reg signed [11:0] d = 0 ; // binary
 reg signed [6:0] e = 0 ; // binary
 reg signed [5:0] f = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0304 - Tests" );
 $display ( "a = %8b = %d", a, a );
 $display ( "b = %8b = %d", b, b );
 $display ( "c = %8b = %d", c, c );
 d = a-b;
 $display ( "d = a-b = %11b-%11b = %11b = %d", a, b, d, d );
 d = b-a;
 $display ( "d = b-a = %8b-%8b = %8b = %d", b, a, d, d );
 d = a-c;
 $display ( "d = a-c = %8b-%8b = %8b = %d", a, c, d, d );
 d = c-a;
 $display ( "d = c-a = %8b-%8b = %8b = %d", c, a, d, d );
 end // main
endmodule // Guia_0304


/* Registro de Resultados

04a.)
a) 11001(2) - 1101(2) = X(2)       -> Resultado: 00001100 
b) 101,1101(2) - 10,01(2) = X(2)   -> Resultado: 00111001
c) 312(4) - 231(4) = X(4) -> Resultado: 00001001
d) 376(8) - 267(8) = X(8) -> Resultado: 01000111
e) 7D2(16) - A51(16) = X(16) -> Resultado: 010110000001 

*/