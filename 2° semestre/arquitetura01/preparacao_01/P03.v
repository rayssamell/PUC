// -------------------------
// Preparacao_01 - Multiplexador
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

//-------------------
// Modulo mux: MUX ( MUX(b,a,c), MUX(NOT(a),NOT(b),c), NOT(c) )
//------------------
module Multiplexador ( output s, input a, input b, input sel);
    wire w1, w2;
    //com portas
    and AND1(w1, a, ~sel);
    and AND2(w2, sel, b);
    
    or OR1(s, w1, w2);

endmodule // s = f (x,y)

//-----------------
// Modulo P03
//-----------------
module p03 (output s, input a, input b, input c);
    wire not_a, not_b, not_c;
    wire mux1_out, mux2_out;

    //descrevendo com portas
    not NOT1(not_a, a);
    not NOT2(not_b, b);
    not NOT3(not_c, c);

    // seleciona entre b e a com a chave c
    Multiplexador mux1(mux1_out, b, a, c);

    // seleciona entre NOT(a) e NOT(b) com a chave c
    Multiplexador mux2(mux2_out, not_a, not_b, c);

    // MUX final: Seleciona entre MUX 1 e MUX 2 com o seletor NOT(c)
    Multiplexador mux_final(s, mux1_out, mux2_out, not_c);
endmodule

//-------------------
// Modulo Principal
//------------------
module Preparacao_01;
    reg a, b, c;
    wire s;

    // instancia
    p03 uut (s, a, b, c);

    //------ parte principal
    initial begin: main
        // identificacao
        $display("Tabela da Verdade ");
        // monitoramento
        $display(" a   b   c =  s  ");
        $monitor("%2b  %2b  %2b = %2b", a, b, c, s);

        a = 0; b = 0; c = 0;
        #1 a = 0; b = 0; c = 1; 
        #1 a = 0; b = 1; c = 0; 
        #1 a = 0; b = 1; c = 1; 
        #1 a = 1; b = 0; c = 1;
        #1 a = 1; b = 0; c = 0; 
    end
endmodule //Preparacao_01

/* Registro de Resultado

Tabela da Verdade 
 a   b   c =  s
 0   0   0 =  1
 0   0   1 =  0
 0   1   0 =  1
 0   1   1 =  0
 1   0   1 =  1
 1   0   0 =  0

*/