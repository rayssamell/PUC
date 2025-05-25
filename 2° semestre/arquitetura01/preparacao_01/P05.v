// -------------------------
// Preparacao_01 - Expressao mintermos
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// SoP - mintermos
//------------------
module SoP (output s, input a, input b);
    // m (0, 1, 2, 3)
    assign s = ~((a ^ b) & ~(~a | ~b)); 
endmodule

//-------------------
// SoP com portas
//------------------
module SoP_portas (output s, input a, input b);
    wire w1, w2;
    
    xor XOR1(w1, a, b);
    nor NOR1(w2, ~a, ~b);
    nand NAND1(s, w1, w2);

endmodule

//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg x, y;
    wire s, s1;
    integer m;

    //instancias
    SoP sop (s, x, y);
    SoP_portas sopPortas(s1, x, y);

    // valores iniciais
    initial begin: start
    x=1'bx; y=1'bx; m =0; // indefinidos
    end

    //------ parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade - SoP ");
    // monitoramento
    $display("          m  x  y  = s  s1 ");
    $monitor("%d %2b %2b = %2b  %2b ", m, x, y, s, s1);
    // sinalizacao
    m=0; x=0; y=0;
    #1 m=1; x=0; y=1;
    #1 m=2; x=1; y=0;
    #1 m=3; x=1; y=1; 
    end
endmodule //Preparacao_01

/* Registro de Resultado:

Tabela da Verdade - SoP 
          m  x  y  = s  s1
          0  0  0 =  1   1
          1  0  1 =  1   1
          2  1  0 =  1   1
          3  1  1 =  1   1
*/
