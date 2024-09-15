// -------------------------
// Guia_0604.v - Mapa Veitch-Karnaugh - MAXTERMOS
// Nome: Rayssa Mell de SouZa Silva
// Matricula: 860210
// -------------------------

// -------------------------
module f6a ( output s, input X, input Y, input W, input Z);
    // descrever por eXpressao
    assign s = (~Y | ~Z) & (X | ~W | Z)  & (~X | ~W | ~Z); 
endmodule // f6a

module test_f6;
// ------------------------- definir dados
    reg X;
    reg Y;
    reg W;
    reg Z;
    wire s;
    
    f6a moduloA (s, X, Y, W, Z); 

// ------------------------- parte principal
   initial
   begin : main
    $display("Guia_0604 - Rayssa Mell de Souza Silva - 860210");
    $display("Test module");
    $display("   X    Y    W    Z    s");
    // projetar testes do modulo
    $monitor("%4b %4b %4b %4b %4b", X, Y, W, Z, s);
       X = 1'b0; Y = 1'b0; W = 1'b0; Z = 1'b0; 
    #1 X = 1'b0; Y = 1'b0; W = 1'b0; Z = 1'b1;
    #1 X = 1'b0; Y = 1'b0; W = 1'b1; Z = 1'b0;
    #1 X = 1'b0; Y = 1'b0; W = 1'b1; Z = 1'b1;

    #1 X = 1'b0; Y = 1'b1; W = 1'b0; Z = 1'b0;
    #1 X = 1'b0; Y = 1'b1; W = 1'b0; Z = 1'b1;
    #1 X = 1'b0; Y = 1'b1; W = 1'b1; Z = 1'b0;
    #1 X = 1'b0; Y = 1'b1; W = 1'b1; Z = 1'b1;
    
    #1 X = 1'b1; Y = 1'b0; W = 1'b0; Z = 1'b0;
    #1 X = 1'b1; Y = 1'b0; W = 1'b0; Z = 1'b1;
    #1 X = 1'b1; Y = 1'b0; W = 1'b1; Z = 1'b0;
    #1 X = 1'b1; Y = 1'b0; W = 1'b1; Z = 1'b1;
    
    #1 X = 1'b1; Y = 1'b1; W = 1'b0; Z = 1'b0;
    #1 X = 1'b1; Y = 1'b1; W = 1'b0; Z = 1'b1;
    #1 X = 1'b1; Y = 1'b1; W = 1'b1; Z = 1'b0;
    #1 X = 1'b1; Y = 1'b1; W = 1'b1; Z = 1'b1;
end
endmodule // test_f6

/* Registro de Resultado 

a) F (X,Y,W,Z) = π M ( 2, 6, 7, 14 ) => assign s =  (X | ~W | Z) & (X | ~Y | ~W) & (~Y | ~W | Z); 
Tabela Verdade: X    Y    W    Z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    0
                0    0    1    1    1
                0    1    0    0    1
                0    1    0    1    1
                0    1    1    0    0
                0    1    1    1    0
                1    0    0    0    1
                1    0    0    1    1
                1    0    1    0    1
                1    0    1    1    1
                1    1    0    0    1
                1    1    0    1    1
                1    1    1    0    0
                1    1    1    1    1

b) F (X,Y,W,Z) = π M ( 4, 5, 9, 13, 14 ) => assign s =  (X | ~Y | W) & (~X | W | ~Z) & (~X | ~Y | ~W | Z)  ;
Tabela Verdade: X    Y    W    Z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    1
                0    0    1    1    1
                0    1    0    0    0
                0    1    0    1    0
                0    1    1    0    1
                0    1    1    1    1
                1    0    0    0    1
                1    0    0    1    0
                1    0    1    0    1
                1    0    1    1    1
                1    1    0    0    1
                1    1    0    1    0
                1    1    1    0    0
                1    1    1    1    1
                
c) F (X,Y,W,Z) = π M ( 4, 7, 8, 13, 15 ) => assign s =  (~Y | ~W | ~Z) & (~X | ~Y | ~Z) & (X | ~Y | W | Z) & (~X | Y | W | Z) ; 
Tabela Verdade: X    Y    W    Z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    1
                0    0    1    1    1
                0    1    0    0    0
                0    1    0    1    1
                0    1    1    0    1
                0    1    1    1    0
                1    0    0    0    0
                1    0    0    1    1
                1    0    1    0    1
                1    0    1    1    1
                1    1    0    0    1
                1    1    0    1    0
                1    1    1    0    1
                1    1    1    1    0

d) F (X,Y,W,Z) = π M ( 1, 5, 9, 11, 14, 15 ) => assign s =  (X | W | ~Z) & (~X | Y | ~Z) &  (~X | ~Y | ~W); 
Tabela Verdade: X    Y    W    Z    s
                0    0    0    0    1
                0    0    0    1    0
                0    0    1    0    1
                0    0    1    1    1
                0    1    0    0    1
                0    1    0    1    0
                0    1    1    0    1
                0    1    1    1    1
                1    0    0    0    1
                1    0    0    1    0
                1    0    1    0    1
                1    0    1    1    0
                1    1    0    0    1
                1    1    0    1    1
                1    1    1    0    0
                1    1    1    1    0

e) F (X,Y,W,Z) = π M ( 2, 5, 6, 7, 11, 13, 15 ) => assign s = (~Y | ~Z) & (X | ~W | Z)  & (~X | ~W | ~Z)  ; 
Tabela Verdade: X    Y    W    Z    s
                0    0    0    0    1
                0    0    0    1    1
                0    0    1    0    0
                0    0    1    1    1
                0    1    0    0    1
                0    1    0    1    0
                0    1    1    0    0
                0    1    1    1    0
                1    0    0    0    1
                1    0    0    1    1
                1    0    1    0    1
                1    0    1    1    0
                1    1    0    0    1
                1    1    0    1    0
                1    1    1    0    1
                1    1    1    1    0

*/