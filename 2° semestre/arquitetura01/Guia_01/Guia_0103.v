/*
 Guia_0103.v
 860210 - Rayssa Mell de Souza Silva
*/
module Guia_0103;
// define data
 integer a = 0, c = 0, d = 0, e = 0, f = 0; // decimal
 reg [7:0] b = 0; // binary
// actions
 initial
 begin : main
 $display ( "Guia_0103 - Tests" );

// a.) 61(10) = X(4)
 a = 61;
 $display ( "a = %d" , a );
 $display ( "b = %8b", b );
 b = a;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

 //b.) 53(10) = X(8)
 c = 53;
 $display ( "c = %d" , c );
 $display ( "b = %8b", b );
 b = c;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

//c.) 77(10) = X(16)
 d = 77;
 $display ( "d = %d" , d );
 $display ( "b = %8b", b );
 b = d;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

//d.) 153(10) = X(16)
 e = 153;
 $display ( "e = %d" , e );
 $display ( "b = %8b", b );
 b = e;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

//e.) 753(10) = X(16)
 f = 753;
 $display ( "f = %d" , f );
 $display ( "b = %8b", b );
 b = f;
 $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b );

 end // main
endmodule // Guia_0103