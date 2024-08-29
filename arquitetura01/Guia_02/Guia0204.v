/*
 Guia_0204.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0204;
// define data
 real x = 0; // decimal
 reg [7:0] b = 8'b0_001111010010 ; // binary
 integer q [3:0];
// actions
 initial
 begin : main
 $display ( "Guia_0204 - Tests" );
 $display ( "x = %f" , x );
 $display ( "b = 0.%8b", b );
 $display ( "b = 0.%x%x (16)", b[7:4],b[3:0] );
 $display ( "b = 0.%o%o%o (8) ", b[7:6],b[5:3],b[2:0] );
 q[3] = b[7:6];
 q[2] = b[5:4];
 q[1] = b[3:2];
 q[0] = b[1:0];
 $display ( "b = 0.%2b %2b %2b %2b (2)", b[7:6],b[5:4],b[3:2],b[1:0] );
 $display ( "q = 0.%2d %2d %2d %2d (4)", q[3] ,q[2] ,q[1] ,q[0] );
 end // main
endmodule // Guia_0204

/* Registro de Resultados

- Para conferir utilizei os resultados que obtive e comparei com as base 4, 8 e 16 dada pela questão

a) 0,111001 (2) => Saída: 0.3210 (4)
b) 0,001111010010 (2) =>  Saída: 0. 3  1  0  2 (4)
c) 0,111101001 (2) =>  
d) 13,03211 (4) =>  Saída: 0.345 (8)
e) F,A5E(16) => Saída: 0.1132 (4)