// -------------------------
// Guia_0602.v - Mapa Veitch-Karnaugh - MAXTERMOS
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

// -------------------------
module f6a ( output s, input X, input Y, input Z );
    // descrever por expressao
    assign s = (~Y | Z) & (~Y | ~Z);

endmodule // f6a

module test_f6;
// ------------------------- definir dados
    reg X;
    reg Y;
    reg Z;
    wire s;
    
    f6a moduloA (s, X, Y, Z); 

// ------------------------- parte principal
   initial
   begin : main
    $display("Guia_0602 - Rayssa Mell de Souza Silva - 860210");
    $display("Test module");
    $display("   X    Y    Z    s");
    // projetar testes do modulo
    $monitor("%4b %4b %4b %4b", X, Y, Z, s);
       X = 1'b0; Y = 1'b0; Z = 1'b0; 
    #1 X = 1'b0; Y = 1'b0; Z = 1'b1;
    #1 X = 1'b0; Y = 1'b1; Z = 1'b0;
    #1 X = 1'b0; Y = 1'b1; Z = 1'b1;
    #1 X = 1'b1; Y = 1'b0; Z = 1'b0;
    #1 X = 1'b1; Y = 1'b0; Z = 1'b1;
    #1 X = 1'b1; Y = 1'b1; Z = 1'b0;
    #1 X = 1'b1; Y = 1'b1; Z = 1'b1;
end
endmodule // test_f6

/* Registro de Resultado 

a) F (X,Y,Z) = π M ( 1, 5, 7 ) => assign s =  (Y | ~Z) & (~X | ~Z);
Tabela Verdade: X    Y    Z    s
                0    0    0    1
                0    0    1    0
                0    1    0    1
                0    1    1    1
                1    0    0    1
                1    0    1    0
                1    1    0    1
                1    1    1    0

b) F (X,Y,Z) = π M ( 0, 4, 6 )
Tabela Verdade: X    Y    Z    s
                0    0    0    0
                0    0    1    1
                0    1    0    1
                0    1    1    1
                1    0    0    0
                1    0    1    1
                1    1    0    0
                1    1    1    1

c) F (X,Y,Z) = π M ( 1, 2, 3, 5 ) =>  assign s = (X | ~Y) & (Y | ~Z) ;
Tabela Verdade: X    Y    Z    s
                0    0    0    1
                0    0    1    0
                0    1    0    0
                0    1    1    0
                1    0    0    1
                1    0    1    0
                1    1    0    1
                1    1    1    1

d) F (X,Y,Z) = π M ( 0, 3, 4, 7 ) =>  assign s = (Y | Z) &  (~Y | ~Z);
Tabela Verdade: X    Y    Z    s
                0    0    0    0
                0    0    1    1
                0    1    0    1
                0    1    1    0
                1    0    0    0
                1    0    1    1
                1    1    0    1
                1    1    1    0

e) F (X,Y,Z) = π M ( 2, 3, 6, 7 ) => assign s = (~Y | Z) & (~Y | ~Z);
Tabela Verdade: X    Y    Z    s
                0    0    0    1
                0    0    1    1
                0    1    0    0
                0    1    1    0
                1    0    0    1
                1    0    1    1
                1    1    0    0
                1    1    1    0
*/