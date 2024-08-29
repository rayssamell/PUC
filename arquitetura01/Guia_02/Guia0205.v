/*
 Guia_0205.v
  860210 - Rayssa Mell de Souza Silva
*/
module Guia_0205;
// define data
 reg [7:0] a = 8'b101_1100; // 101.1100(2)
 reg [7:0] b = 8'b010_0110; // 010.0110(2)
 reg [7:0] c;
// actions
 initial
 begin : main
 $display ( "Guia_0205 - Tests" );
 $display ( "a = %8b", a );
 $display ( "b = %8b", b );
 c = a+b;
 $display ( "c = a+b = %8b", c );
 c = a-b;
 $display ( "c = a-b = %8b", c );
 c = b-a;
 $display ( "c = b-a = %8b", c );
 c = a*b;
 $display ( "c = a*b = %8b", c );
 c = b/a;
 $display ( "c = b/a = %8b", c );
 c = b%a;
 $display ( "c = b%%a = %8b", c );
 end // main
endmodule // Guia_0205