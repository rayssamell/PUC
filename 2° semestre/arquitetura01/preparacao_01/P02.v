// -------------------------
// Preparacao_01 - Truth Table
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// Modulo F
//------------------
module f ( output s, input x, input y );
    wire w1, w2, w3, w4, w5;
    // com portas
    not NOT_1 (w1, x);
    not NOT_2 (w2, y);
    and OR__1 (w3, y, w1);
    or OR__2 (w4, w2, x);
    not NOT_3 (w5, w4);
    and AND_1 (s, w3, w5);
endmodule // s = f (x,y)

//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg x, y;
    wire s;

    //instancia
    f test(s, x, y);

    // valores iniciais
    initial begin: start
    x=1'bx; y=1'bx;  // indefinidos
    end

    //------ parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade ");
    // monitoramento
    $display("x  y  =  s  ");
    $monitor("%2b %2b = %2b", x, y, s);
    // sinalizacao
    x=0; y=0; 
    #1 x=0; y=1;
    #1 x=1; y=0;
    #1 x=1; y=1;
    end
endmodule //Preparacao_01

/* Registro de Resultado

Tabela da Verdade 
 x  y =  s
 0  0 =  0
 0  1 =  1
 1  0 =  0
 1  1 =  0


*/