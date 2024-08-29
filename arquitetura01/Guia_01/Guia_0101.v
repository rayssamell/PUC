/*
 Guia_0101.v
 860210 - Rayssa Mell de Souza Silva
*/

module Guia_0101;
// define data
 integer x; // decimal
 reg [7:0] b = 0; // binary (bits - little endian)
// actions
 initial
 begin : main
 $display ( "Guia_0101 - Tests" );
 
// a) 26(10) = X(2)
 x = 26;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );

// b) 53(10) = X(2)
 x = 53;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
// c) 713(10) = X(2)
 x = 713;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
// d) 213(10) = X(2)
 x = 213;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
// e) 365(10) = X(2)
 x = 365;
 b = x;
 $display ( "x = %d" , x );
 $display ( "b = %8b\n", b );
 
 end // main
endmodule // Guia_0101