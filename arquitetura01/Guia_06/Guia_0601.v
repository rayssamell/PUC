// -------------------------
// Guia_0601.v - Mapa Veitch-Karnaugh - Mintermos
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

// -------------------------
module f6a ( output s, input x, input y, input z );
    // descrever por expressao
    assign s =  (x & y) | (y & z) | (~x & ~y & ~z);
endmodule // f6a

module test_f6;
// ------------------------- definir dados
    reg x;
    reg y;
    reg z;
    wire s;
    
    f6a moduloA (s, x, y, z); 

// ------------------------- parte principal
   initial
   begin : main
    $display("Guia_0601 - Rayssa Mell de Souza Silva - 860210");
    $display("Test module");
    $display("   x    y    z    s");
    // projetar testes do modulo
    $monitor("%4b %4b %4b %4b", x, y, z, s);
       x = 1'b0; y = 1'b0; z = 1'b0; 
    #1 x = 1'b0; y = 1'b0; z = 1'b1;
    #1 x = 1'b0; y = 1'b1; z = 1'b0;
    #1 x = 1'b0; y = 1'b1; z = 1'b1;
    #1 x = 1'b1; y = 1'b0; z = 1'b0;
    #1 x = 1'b1; y = 1'b0; z = 1'b1;
    #1 x = 1'b1; y = 1'b1; z = 1'b0;
    #1 x = 1'b1; y = 1'b1; z = 1'b1;
end
endmodule // test_f6

/* Registro de Resultado 

a) f (x,y,z) = ∑ m ( 1, 6, 7 ) => assign s = (~x & ~y & z) | ( x & y);
Tabela verdade:     x    y    z    s
                    0    0    0    0
                    0    0    1    1
                    0    1    0    0
                    0    1    1    0
                    1    0    0    0
                    1    0    1    0
                    1    1    0    1
                    1    1    1    1

b) f (x,y,z) = ∑ m ( 2, 4, 6 ) => assign s = (y & ~z)  | (x & ~z);   
Tabela verdade:     x    y    z    s
                    0    0    0    0
                    0    0    1    0
                    0    1    0    1
                    0    1    1    0
                    1    0    0    1
                    1    0    1    0
                    1    1    0    1
                    1    1    1    0

c) f (x,y,z) = ∑ m ( 1, 2, 5, 6 ) => assign s = (~y & z)  | (y & ~z);
Tabela Verdade:     x    y    z    s
                    0    0    0    0
                    0    0    1    1
                    0    1    0    1
                    0    1    1    0
                    1    0    0    0
                    1    0    1    1
                    1    1    0    1
                    1    1    1    0

d) f (x,y,z) = ∑ m ( 1, 2, 4, 5 ) => assign s =  (~y & z) | (x & ~y) | (~x & y & ~z);
Tabela verdade:     x    y    z    s
                    0    0    0    0
                    0    0    1    1
                    0    1    0    1
                    0    1    1    0
                    1    0    0    1
                    1    0    1    1
                    1    1    0    0
                    1    1    1    0

e) f (x,y,z) = ∑ m ( 0, 3, 6, 7 ) => assign s =  (x & y) | (y & z) | (~x & ~y & ~z);
Tabela verdade:    x    y    z    s
                   0    0    0    1
                   0    0    1    0
                   0    1    0    0
                   0    1    1    1
                   1    0    0    0
                   1    0    1    0
                   1    1    0    1
                   1    1    1    1
*/