/*
 Guia_0201.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0201;
// define data
 real x = 3 ; // decimal
 real power2 = 1.0; // power of 2
 integer y = 7 ; // counter
 reg [7:0] b = 8'b11001000; // binary (only fraction part, Big Endian)
// actions
 initial
 begin : main
 $display ( "Guia_0201 - Tests" );

 $display ( "x = %f" , x );
 $display ( "b = 0.%8b", b );

 while ( y >= 0 )
 begin
 power2 = power2 / 2.0;
 if ( b[y] == 1 )
 begin
 x = x + power2;
 end
 $display ( "x = %f", x );
 y=y-1;
 end // end while
 end // main
endmodule // Guia_0201

/* Registro de Resultados 
a) 0,00011(2) => Saída obtida: 0.093750
b) 0,01001(2) => Saída obtida: 0.28125
c) 0,10101(2) => Saída obtida: 0.656250
d) 1,11101(2) => Saída obtida: 1.906250
e) 11,11001(2) => Saída obtida: 3.781250
*/