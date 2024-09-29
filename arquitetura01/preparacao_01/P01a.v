// -------------------------
// Preparacao_01 - SoP Canônica 
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// SoP Canonica - 1.) a
//------------------
module SoP_Canonica (output s, input a, input b, input c, input d);
    // m (a, b, c, d)
    assign s = (a & ~b & c & ~d) | (a & ~b & c & d) | (a & b & ~c & ~d) | (a & b & ~c & d);
endmodule

//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg x, y, w, z;
    wire s;
    integer m;

    //instancias
    SoP_Canonica sop (s, x, y, w, z);

    // valores iniciais
    initial begin: start
    x=1'bx; y=1'bx; w=1'bx; z=1'bx; m =0; // indefinidos
    end

    //------ parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade - SoP Canonica ");
    // monitoramento
    $display("          m  x  y  w  z  = s");
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

Tabela da Verdade - SoP Canonica
          m  x  y  w  z  = s 
          0  0  0  0  0 =  0
          1  0  0  0  1 =  0
          2  0  0  1  0 =  0
          3  0  0  1  1 =  0
          4  0  1  0  0 =  0
          5  0  1  0  1 =  0
          6  0  1  1  0 =  0
          7  0  1  1  1 =  0
          8  1  0  0  0 =  0
          9  1  0  0  1 =  0
         10  1  0  1  0 =  1
         11  1  0  1  1 =  1
         12  1  1  0  0 =  1
         13  1  1  0  1 =  1
         14  1  1  1  0 =  0
         15  1  1  1  1 =  0


*/
