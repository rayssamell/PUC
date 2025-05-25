// -------------------------
// Guia_0603.v - Mapa Veitch-Karnaugh - Mintermos
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

// -------------------------
module f6a ( output s, input x, input y, input w, input z);
    // descrever por expressao
    assign s =  (~x & ~y & ~w) | (~x & w & z) | (x & ~y & ~w) | (~y & w & z) | (x & ~w & z); 
endmodule // f6a

module test_f6;
// ------------------------- definir dados
    reg x;
    reg y;
    reg w;
    reg z;
    wire s;
    
    f6a moduloA (s, x, y, w, z); 

// ------------------------- parte principal
   initial
   begin : main
    $display("Guia_0603 - Rayssa Mell de Souza Silva - 860210");
    $display("Test module");
    $display("   x    y    w    z    s");
    // projetar testes do modulo
    $monitor("%4b %4b %4b %4b %4b", x, y, w, z, s);
       x = 1'b0; y = 1'b0; w = 1'b0; z = 1'b0; 
    #1 x = 1'b0; y = 1'b0; w = 1'b0; z = 1'b1;
    #1 x = 1'b0; y = 1'b0; w = 1'b1; z = 1'b0;
    #1 x = 1'b0; y = 1'b0; w = 1'b1; z = 1'b1;

    #1 x = 1'b0; y = 1'b1; w = 1'b0; z = 1'b0;
    #1 x = 1'b0; y = 1'b1; w = 1'b0; z = 1'b1;
    #1 x = 1'b0; y = 1'b1; w = 1'b1; z = 1'b0;
    #1 x = 1'b0; y = 1'b1; w = 1'b1; z = 1'b1;
    
    #1 x = 1'b1; y = 1'b0; w = 1'b0; z = 1'b0;
    #1 x = 1'b1; y = 1'b0; w = 1'b0; z = 1'b1;
    #1 x = 1'b1; y = 1'b0; w = 1'b1; z = 1'b0;
    #1 x = 1'b1; y = 1'b0; w = 1'b1; z = 1'b1;
    
    #1 x = 1'b1; y = 1'b1; w = 1'b0; z = 1'b0;
    #1 x = 1'b1; y = 1'b1; w = 1'b0; z = 1'b1;
    #1 x = 1'b1; y = 1'b1; w = 1'b1; z = 1'b0;
    #1 x = 1'b1; y = 1'b1; w = 1'b1; z = 1'b1;
end
endmodule // test_f6

/* Registro de Resultado 

a) f (x,y,w,z) = ∑ m ( 1, 2, 5, 8, 12, 13 )
Tabela Verdade: x    y    w    z    s
                0    0    0    0    0
                0    0    0    1    1
                0    0    1    0    1
                0    0    1    1    0
                0    1    0    0    0
                0    1    0    1    1
                0    1    1    0    0
                0    1    1    1    0
                1    0    0    0    1
                1    0    0    1    0
                1    0    1    0    0
                1    0    1    1    0
                1    1    0    0    1
                1    1    0    1    1
                1    1    1    0    0
                1    1    1    1    0

b) f (x,y,w,z) = ∑ m ( 0, 1, 3, 5, 7, 13, 15 ) => assign s =  (~x & ~y & ~w) | (~x & z) | (y & z);
Tabela Verdade: x    y    w    z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    0
                0    0    1    1    1
                0    1    0    0    0
                0    1    0    1    1
                0    1    1    0    0
                0    1    1    1    1
                1    0    0    0    0
                1    0    0    1    0
                1    0    1    0    0
                1    0    1    1    0
                1    1    0    0    0
                1    1    0    1    1
                1    1    1    0    0
                1    1    1    1    1

c) f (x,y,w,z) = ∑ m ( 0, 1, 2, 6, 7, 10, 14, 15 ) => assign s =  (~x & ~y & ~w) | (y &  w) |(w & ~z); 
Tabela Verdade: x    y    w    z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    1
                0    0    1    1    0
                0    1    0    0    0
                0    1    0    1    0
                0    1    1    0    1
                0    1    1    1    1
                1    0    0    0    0
                1    0    0    1    0
                1    0    1    0    1
                1    0    1    1    0
                1    1    0    0    0
                1    1    0    1    0
                1    1    1    0    1
                1    1    1    1    1

d) f (x,y,w,z) = ∑ m ( 2, 4, 6, 7, 10, 13, 14 ) => assign s =  (w & ~z) | (~x & y & ~z) | (~x & y & w) | (x & y & ~w & z); 
Tabela Verdade: x    y    w    z    s
                0    0    0    0    0
                0    0    0    1    0
                0    0    1    0    1
                0    0    1    1    0
                0    1    0    0    1
                0    1    0    1    0
                0    1    1    0    1
                0    1    1    1    1
                1    0    0    0    0
                1    0    0    1    0
                1    0    1    0    1
                1    0    1    1    0
                1    1    0    0    0
                1    1    0    1    1
                1    1    1    0    1
                1    1    1    1    0

e) f (x,y,w,z) = ∑ m ( 0, 1, 3, 7, 8, 9, 11, 13 ) => assign s =  (~x & ~y & ~w) | (~x & w & z) | (x & ~y & ~w) | (~y & w & z) | (x & ~w & z); 
Tabela Verdade: x    y    w    z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    0
                0    0    1    1    1
                0    1    0    0    0
                0    1    0    1    0
                0    1    1    0    0
                0    1    1    1    1
                1    0    0    0    1
                1    0    0    1    1
                1    0    1    0    0
                1    0    1    1    1
                1    1    0    0    0
                1    1    0    1    1
                1    1    1    0    0
                1    1    1    1    0

*/