// -------------------------
// Preparacao_01 - PoS 
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// PoS com Portas NOR - 1.) f
//------------------
module PoS_NOR(output S, input A, input B, input C, input D);
    wire AN, BN, CN, DN;
    wire w1, w2, w3, w4, w5, w6, w7, w8;

    nor NOR1 (AN, A, A); // ~A
    nor NOR2 (BN, B, B); // ~B
    nor NOR3 (CN, C, C); // ~C
    nor NOR4 (DN, D, D); // ~D

    nor NOR5 (w1, C, DN);       
    nor NOR6 (w2, A, B, C);    
    nor NOR7 (w3, AN, B, C);     
    nor NOR8 (w4, AN, BN, CN);    
    nor NOR9 (w5, AN, CN, D);   
    nor NOR10 (w6, A, B, DN);    
    nor NOR11 (w7, AN, BN, DN);    
    nor NOR12 (w8, BN, CN, D); 

    nor NOR13(S, w1, w2, w3, w4, w5, w6, w7, w8); 
endmodule

//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg X, Y, W, Z;
    wire S;
    integer M;

    //instancias
    PoS_NOR pos(S, X, Y, W, Z);

    // valores iniciais
    initial begin: start
    X=1'bx; Y=1'bx; W=1'bx; Z=1'bx; M=0; // indefinidos
    end

    //------ parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade - PoS");
    // monitoramento
    $display("          M  X  Y  W  Z  = S");
    $monitor("%d %2b %2b %2b %2b = %2b", M, X, Y, W, Z, S);
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

Tabela da Verdade - PoS 
          M  X  Y  W  Z  = S
          0  0  0  0  0 =  0
          1  0  0  0  1 =  0
          2  0  0  1  0 =  1
          3  0  0  1  1 =  0
          4  0  1  0  0 =  1
          5  0  1  0  1 =  0
          6  0  1  1  0 =  0
          7  0  1  1  1 =  1
          8  1  0  0  0 =  0
          9  1  0  0  1 =  0
         10  1  0  1  0 =  0
         11  1  0  1  1 =  1
         12  1  1  0  0 =  1
         13  1  1  0  1 =  0
         14  1  1  1  0 =  0
         15  1  1  1  1 =  0

*/