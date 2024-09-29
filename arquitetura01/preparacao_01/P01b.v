// -------------------------
// Preparacao_01 - PoS Canônica
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// PoS Canonica - 1.) b
//------------------
module PoS_Canonica(output S, input A, input B, input C, input D);
    // M (A, B, C, D)
    assign S = (~A | B | ~C | D) & (~A | B | ~C | ~D) & (~A | ~B | C | D) & (~A | ~B | C | ~D);
endmodule

//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg X, Y, W, Z;
    wire S, S1, S2;
    integer M;

    //instancias
    PoS_Canonica pos(S, X, Y, W, Z);

    // valores iniciais
    initial begin: start
    X=1'bx; Y=1'bx; W=1'bx; Z=1'bx; M=0; // indefinidos
    end

    //------ parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade - PoS Canonica");
    // monitoramento
    $display("          M  X  Y  W  Z  = S ");
    $monitor("%d %2b %2b %2b %2b = %2b ", M, X, Y, W, Z, S);
    // sinalizacao
    M=0; X=0; Y=0; W=0; Z=0;
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
endmodule

/* Registro de Resultado 

Tabela da Verdade - PoS Canonica 
          M  X  Y  W  Z  = S
          0  0  0  0  0 =  1
          1  0  0  0  1 =  1
          2  0  0  1  0 =  1
          3  0  0  1  1 =  1
          4  0  1  0  0 =  1
          5  0  1  0  1 =  1
          6  0  1  1  0 =  1
          7  0  1  1  1 =  1
          8  1  0  0  0 =  1
          9  1  0  0  1 =  1
         10  1  0  1  0 =  0
         11  1  0  1  1 =  0
         12  1  1  0  0 =  0
         13  1  1  0  1 =  0
         14  1  1  1  0 =  1
         15  1  1  1  1 =  1

*/