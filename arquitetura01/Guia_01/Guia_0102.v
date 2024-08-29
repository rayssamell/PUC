/*
 Guia_0102.v
 860210 - Rayssa Mell de Souza Silva
*/

module Guia_0102;
// define data
 integer x = 0; // decimal
 reg [7:0] b = 0; // binary (bits - little endian)
// actions
 initial
 begin : main
 $display ( "Guia_0102 - Tests" );
 
 // a.) 10101(2) = X(10)
 x = 8'b0010101;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );

// b.) 11011(2) = X(10)
 x = 8'b0011011;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
// c.) 10010(2) = X(10)
 x = 8'b0010010;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
// d.) 101011(2) = X(10))
 x = 8'b0101011;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
//  e.) 110111(2) = X(10)
 x = 8'b0110111;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );

 end // main
endmodule // Guia_0102