// ---------------------
// TRUTH TABLE
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
//  Guia_0404.v
// ---------------------
// -- expression
// ---------------------

module PoS (output S, input X, input Y, input W, input Z); // MAXTERMOS
    //  F (X,Y,W,Z) = π M ( 1, 2, 4, 7, 8, 9, 15 ) 
    assign S = (X| Y| W| ~Z) & (X| Y| ~W| Z) & ( X| ~Y| W| Z) & ( X| ~Y| ~W| ~Z) & 
               (~X| Y| W| Z) & ( ~X| Y| W| ~Z) & (~X| ~Y|~W| ~Z);
endmodule // PoS

module Guia_0404;
    reg X, Y, W, Z;
    wire S;
    integer M;

    // instancias
    PoS pos (S, X, Y, W, Z);

    // valores iniciais
    initial begin: start
    X=1'bx; Y=1'bx; W=1'bx; Z=1'bx; M=0; // indefinidos
    end
    // parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade");
    // monitoramento
    $display("M  X  Y  W  Z  = S");
    $monitor("%d %2b %2b %2b %2b = %2b", M, X, Y, W, Z, S);
    // sinalizacao
    #1 M=0; X=0; Y=0; W=0; Z=0;
    #1 M=1; X=0; Y=0; W=0; Z=1;
    #1 M=2; X=0; Y=0; W=1; Z=0;
    #1 M=3; X=0; Y=0; W=1; Z=1;
    #1 M=4; X=0; Y=1; W=0; Z=0;
    #1 M=5; X=0; Y=1; W=0; Z=1; 
    #1 M=6; X=0; Y=1; W=1; Z=0;
    #1 M=7; X=0; Y=1; W=1; Z=1;
    #1 M=8; X=1; Y=0; W=0; Z=0;
    #1 M=9; X=1; Y=0; W=0; Z=1;
    #1 M=10; X=1; Y=0; W=1; Z=0;
    #1 M=11; X=1; Y=0; W=1; Z=1;
    #1 M=12; X=1; Y=1; W=0; Z=0;
    #1 M=13; X=1; Y=1; W=0; Z=1;
    #1 M=14; X=1; Y=1; W=1; Z=0;
    #1 M=15; X=1; Y=1; W=1; Z=1;
    end
endmodule // Guia_0404


/* Registro de Resultados 

04.) Tabela da Verdade
a.) F (X,Y,Z) = π M ( 1, 2, 6, 7 )
Saída:  M  X  Y  Z = S
        0  0  0  0 = 1
        1  0  0  1 = 0
        2  0  1  0 = 0
        3  0  1  1 = 1
        4  1  0  0 = 1
        5  1  0  1 = 1
        6  1  1  0 = 0
        7  1  1  1 = 0

b.) F (X,Y,Z) = π M ( 0, 3, 4, 7 )
Saída:  M  X  Y  Z =  S
        0  0  0  0 =  0
        1  0  0  1 =  1
        2  0  1  0 =  1
        3  0  1  1 =  0
        4  1  0  0 =  0
        5  1  0  1 =  1
        6  1  1  0 =  1
        7  1  1  1 =  0

c.)  F (X,Y,W,Z) = π M ( 0, 1, 2, 4, 6, 8, 11, 12 ) 
Saída:    M  X  Y  W  Z =  S
          0  0  0  0  0 =  0
          1  0  0  0  1 =  0
          2  0  0  1  0 =  0
          3  0  0  1  1 =  1
          4  0  1  0  0 =  0
          5  0  1  0  1 =  1
          6  0  1  1  0 =  0
          7  0  1  1  1 =  1
          8  1  0  0  0 =  0
          9  1  0  0  1 =  1
         10  1  0  1  0 =  1
         11  1  0  1  1 =  0
         12  1  1  0  0 =  0
         13  1  1  0  1 =  1
         14  1  1  1  0 =  1
         15  1  1  1  1 =  1

d.) F (X,Y,W,Z) = π M ( 1, 2, 4, 7, 8, 9, 15 ) 
Saída:   M  X  Y  W  Z =  S
         0  0  0  0  0 =  1
         1  0  0  0  1 =  0
         2  0  0  1  0 =  0
         3  0  0  1  1 =  1
         4  0  1  0  0 =  0
         5  0  1  0  1 =  1
         6  0  1  1  0 =  1
         7  0  1  1  1 =  0
         8  1  0  0  0 =  0
         9  1  0  0  1 =  0
        10  1  0  1  0 =  1
        11  1  0  1  1 =  1
        12  1  1  0  0 =  1
        13  1  1  0  1 =  1
        14  1  1  1  0 =  1
        15  1  1  1  1 =  0

e.) F (X,Y,W,Z) = π M ( 0, 1, 2, 4, 5, 10, 13 )
Saída:    M  X  Y  W  Z =  S
          0  0  0  0  0 =  0
          1  0  0  0  1 =  0
          2  0  0  1  0 =  0
          3  0  0  1  1 =  1
          4  0  1  0  0 =  0
          5  0  1  0  1 =  0
          6  0  1  1  0 =  1
          7  0  1  1  1 =  1
          8  1  0  0  0 =  1
          9  1  0  0  1 =  1
         10  1  0  1  0 =  0
         11  1  0  1  1 =  1
         12  1  1  0  0 =  1
         13  1  1  0  1 =  0
         14  1  1  1  0 =  1
         15  1  1  1  1 =  1
*/