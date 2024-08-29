// ---------------------
// TRUTH TABLE
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
//  Guia_0403.v
// ---------------------
// -- expression
// ---------------------

module SoP (output s, input x, input y, input w, input z); // mintermos
   // m  ( 0, 2, 5, 7, 8, 11 )
   assign s = (~x & ~y & ~w & ~z)| (~x & ~y & w & ~z) | (~x & y & ~w & z) | (~x & y & w & z) | (x & ~y & ~w & ~z) | (x & ~y & w & z) ;
endmodule

module Guia_0403;
    reg x, y, w, z;
    wire s;
    integer m;

    // instancias
    SoP sop (s, x, y, w, z);

    // valores iniciais
    initial begin: start
    x=1'bx; y=1'bx; w=1'bx; z=1'bx; m =0; // indefinidos
    end
    // parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade");
    // monitoramento
    $display("  m  x  y  w  z  = s");
    $monitor("%d %2b %2b %2b %2b = %2b", m, x, y, w, z, s);
    // sinalizacao
    #1 m=0; x=0; y=0; w=0 ; z=0;
    #1 m=1; x=0; y=0; w=0 ; z=1; 
    #1 m=2; x=0; y=0; w=1 ; z=0;
    #1 m=3; x=0; y=0; w=1 ; z=1;
    #1 m=4; x=0; y=1; w=0 ; z=0;
    #1 m=5; x=0; y=1; w=0 ; z=1;
    #1 m=6; x=0; y=1; w=1 ; z=0;
    #1 m=7; x=0; y=1; w=1 ; z=1;
    #1 m=8; x=1; y=0; w=0 ; z=0;
    #1 m=9; x=1; y=0; w=0 ; z=1;
    #1 m=10; x=1; y=0; w=1 ; z=0;
    #1 m=11; x=1; y=0; w=1 ; z=1;
    #1 m=12; x=1; y=1; w=0 ; z=0;
    #1 m=13; x=1; y=1; w=0 ; z=1;
    #1 m=14; x=1; y=1; w=1 ; z=0;
    #1 m=15; x=1; y=1; w=1 ; z=1;
    end
endmodule // Guia_0403


/* Registro de Resultados 

03.) Tabela da Verdade
a.) f (x,y,z) = ∑ m ( 1, 5, 6, 7 )
Saída:    m  x  y  z  = s
          0  0  0  0 =  0
          1  0  0  1 =  1
          2  0  1  0 =  0
          3  0  1  1 =  0
          4  1  0  0 =  0
          5  1  0  1 =  1
          6  1  1  0 =  1
          7  1  1  1 =  1

b.) f (x,y,z) = ∑ m ( 2, 5, 6, 7 )
Saída:    m  x  y  z  = s
          0  0  0  0 =  0
          1  0  0  1 =  0
          2  0  1  0 =  1
          3  0  1  1 =  0
          4  1  0  0 =  0
          5  1  0  1 =  1
          6  1  1  0 =  1
          7  1  1  1 =  1

c.) f (x,y,w,z) = ∑ m ( 1, 2, 3, 6, 7, 11, 15 )
Saída:    m  x  y  w  z  = s
          0  0  0  0  0 =  0
          1  0  0  0  1 =  1
          2  0  0  1  0 =  1
          3  0  0  1  1 =  1
          4  0  1  0  0 =  0
          5  0  1  0  1 =  0
          6  0  1  1  0 =  1
          7  0  1  1  1 =  1
          8  1  0  0  0 =  0
          9  1  0  0  1 =  0
         10  1  0  1  0 =  0
         11  1  0  1  1 =  1
         12  1  1  0  0 =  0
         13  1  1  0  1 =  0
         14  1  1  1  0 =  0
         15  1  1  1  1 =  1

d.) f (x,y,w,z) = ∑ m ( 1, 2, 6, 8, 10, 12, 14 )
Saída:    m  x  y  w  z  = s
          0  0  0  0  0 =  0
          1  0  0  0  1 =  1
          2  0  0  1  0 =  1
          3  0  0  1  1 =  0
          4  0  1  0  0 =  0
          5  0  1  0  1 =  0
          6  0  1  1  0 =  1
          7  0  1  1  1 =  0
          8  1  0  0  0 =  1
          9  1  0  0  1 =  0
         10  1  0  1  0 =  1
         11  1  0  1  1 =  0
         12  1  1  0  0 =  1
         13  1  1  0  1 =  0
         14  1  1  1  0 =  1
         15  1  1  1  1 =  0

e.) f (x,y,w,z) = ∑ m ( 0, 2, 5, 7, 8, 11 )
Saída:    m  x  y  w  z  = s
          0  0  0  0  0 =  1
          1  0  0  0  1 =  0
          2  0  0  1  0 =  1
          3  0  0  1  1 =  0
          4  0  1  0  0 =  0
          5  0  1  0  1 =  1
          6  0  1  1  0 =  0
          7  0  1  1  1 =  1
          8  1  0  0  0 =  1
          9  1  0  0  1 =  0
         10  1  0  1  0 =  0
         11  1  0  1  1 =  1
         12  1  1  0  0 =  0
         13  1  1  0  1 =  0
         14  1  1  1  0 =  0
         15  1  1  1  1 =  0
*/