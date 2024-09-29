// -------------------------
// Preparacao_01 - SoP
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// SoP com Portas NAND - 1.) e
//------------------
module SoP_NAND(output s, input a, input b, input c, input d);
    wire an, bn, cn, dn;
    wire w1, w2, w3, w4, w5, w6, w7, w8;
    //descrever com portas
    nand NAND1 (an, a, a);
    nand NAND2 (bn, b, b);
    nand NAND3 (cn, c, c);
    nand NAND4 (dn, d, d);

    nand NAND5 (w1, b, cn, dn);
    nand NAND6 (w2, an, bn, c, dn);
    nand NAND7 (w3, an, b, c, d);
    nand NAND8 (w4, a, bn, c, d);

    nand NAND9 (w5, w1, w2);
    nand NAND10 (w6, w3, w4);

    nand NAND11 (w7, w5, w5);
    nand NAND12 (w8, w6, w6);

    nand NAND13(s, w7, w8);
endmodule
//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg x, y, w, z;
    wire s;
    integer m;

    //instancia
    SoP_NAND sopNand (s, x, y, w, z);

    // valores iniciais
    initial begin: start
    x=1'bx; y=1'bx; w=1'bx; z=1'bx; m =0; // indefinidos
    end

    //------ parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade - SoP ");
    // monitoramento
    $display("          m  x  y  w  z  = s ");
    $monitor("%d %2b %2b %2b %2b = %2b", m, x, y, w, z, s);
    // sinalizacao
    m=0; x=0; y=0; w=0 ; z=0;
    #1 m=1; x=0; y=0; w=0 ; z=1; 
    #1 m=2; x=0; y=0; w=1 ; z=0;
    #1 m=3; x=0; y=0; w=1 ; z=1;
    #1 m=4; x=0; y=1; w=0 ; z=0;
    #1 m=5; x=0; y=1; w=0 ; z=1;
    #1 m=6; x=0; y=1; w=1 ; z=0;
    #1 m=7; x=0; y=1; w=1 ; z=1;
    #1 m=8; x=1; y=0; w=0 ; z=0;
    #1 m=9; x=1; y=0; w=0 ; z=1;
    #1 m=10; x=1; y=0; w=1 ; z=0; //A
    #1 m=11; x=1; y=0; w=1 ; z=1; //B
    #1 m=12; x=1; y=1; w=0 ; z=0; //C
    #1 m=13; x=1; y=1; w=0 ; z=1; //D
    #1 m=14; x=1; y=1; w=1 ; z=0; //E
    #1 m=15; x=1; y=1; w=1 ; z=1; //F
    end
endmodule //Preparacao_01

/* Registro de Resultado:

Tabela da Verdade - SoP 
           m  x  y  w  z  = s
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
