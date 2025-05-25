/*
 Guia_0203.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0203;
// define data
 real x = 0; // decimal  
 reg [7:0] b = 8'b0_00000000; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0203 - Tests" );
 $display ( "x = %f" , x );
 $display ( "b = 0.%8b", b );
 $display ( "b = 0.%x%x (16)", b[7:4],b[3:0] );
 $display ( "b = 0.%o%o%o (8) ", b[7:6],b[5:3],b[2:0] );
 integer q [3:0];
 q[3] = b[7:6];
 q[2] = b[5:4];
 q[1] = b[3:2];
 q[0] = b[1:0];
 $display ( "q = 0.%2d %2d %2d %2d (4)", q[3] ,q[2] ,q[1] ,q[0] );
 end // main
endmodule // Guia_0203


/* Registro de Resultados

a) 0,011110(2)=> Saída: 0.132 (4)
b) 0,101001(2) => Saída:  0.051 (8)
c) 0,100110(2) => Saída:  0.98 (16)
d) 1,111011(2) => Saída:  0.173 (8)
e) 1101,1001(2) => Saída:  0.d9 (16)
*/