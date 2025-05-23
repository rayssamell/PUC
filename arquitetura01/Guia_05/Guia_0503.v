// -------------------------
// Guia_0503.v - GATES
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------
// -------------------------
// f5_gate
// m a b s
// 0 0 0 0
// 1 0 1 0 
// 2 1 0 1
// 3 1 1 0
//
// -------------------------
module f5a ( output s, input a, input b );
    // definir dado local
    wire not_a;
    // descrever por portas
    nor NOR1 (not_a, a, a);
    nor NOR2 (s, not_a, b);
endmodule // f5a
// -------------------------
// f5_gate
// m a b s
// 0 0 0 0
// 1 0 1 0 
// 2 1 0 1
// 3 1 1 0
//
// -------------------------
module f5b ( output s, input a, input b );
    // descrever por expressao
    assign s = ~(~a | b);
endmodule // f5b

module test_f5;
// ------------------------- definir dados
    reg x;
    reg y;
    wire a, b;
    f5a moduloA ( a, x, y );
    f5b moduloB ( b, x, y );

// ------------------------- parte principal
   initial
   begin : main
    $display("Guia_0500 - Rayssa Mell de Souza Silva - 860210");
    $display("Test module");
    $display("   x    y    a    b");
    // projetar testes do modulo
    $monitor("%4b %4b %4b %4b", x, y, a, b);
       x = 1'b0; y = 1'b0;
    #1 x = 1'b0; y = 1'b1;
    #1 x = 1'b1; y = 1'b0;
    #1 x = 1'b1; y = 1'b1;
end
endmodule // test_f5

/* Registro de Resultado 

expressão (a | ~b) =>
Saída ==> 
Test module
    x    y    a    b
    0    0    0    0
    0    1    0    0
    1    0    1    1
    1    1    0    0
*/