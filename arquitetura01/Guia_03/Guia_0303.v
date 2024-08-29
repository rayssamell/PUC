/*
 Guia_0303.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0303;
// define data
 reg signed [4:0] a = 8'b0001_0110; // binary
 reg signed [5:0] b = 8'b0011_0011 ; // binary
 reg signed [5:0] c = 8'b0010_0100 ; // binary
 reg signed [6:0] d = 8'b0101_1011 ; // binary
 reg signed [6:0] e = 8'b0111_0011 ; // binary
 reg signed [7:0] f = 0 ; // binary
 reg signed [6:0] g = 0 ; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0303 - Tests" );
 f = ~a+1;
 g = ~(a-1);
 $display ( "a = %8b -> C1(a) = %8b -> C2(a) = %4b = %d = %d", a, ~a, f, f, g );
 f = ~b+1;
 g = ~(b-1);
 $display ( "b = %7b -> C1(b) = %7b -> C2(b) = %5b = %d = %d", b, ~b, f, f, g );
 f = ~c+1;
 g = ~(c-1);
 $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %5b = %d = %d", c, ~c, f, f, g );
 f = ~d+1;
 g = ~(d-1);
 $display ( "d = %6b -> C1(c) = %6b -> C2(d) = %5b = %d = %d", d, ~d, f, f, g );
 f = ~e+1;
 g = ~(e-1);
 $display ( "e = %6b -> C1(c) = %6b -> C2(e) = %7b = %d = %d", e, ~e, f, f, g );
 end // main end // main
endmodule // Guia_0303

/* Registro de Resultados

03a.)
a) 10110   -> C2(a) = 00001010 =  10
b) 110011  -> C2(b) = 00001101 =  13
c) 100100  -> C2(c) = 00011100 
d) 1011011 -> C2(d) = 00100101 
e) 1110011 -> C2(e) = 00001101 

*/