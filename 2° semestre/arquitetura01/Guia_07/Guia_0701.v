// -------------------------
// Guia_0701 - GATES
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------
// -------------------------
// f7_gate
// -------------------------
module f7 ( output s, input a, input b);
  and AND1  (s, a, b);      // Operacao AND
  nand NAND1 (s, a, b);   // Operacao NAND
endmodule // f7
// -------------------------
// multiplexer
// -------------------------
module mux ( output s,
    input a,
    input b,
    input select );
    // definir dados locais
    wire sel;
    wire sa;
    wire sb;
    // descrever por portas
    nand NAND1 ( sel, select, select);
    and AND1 ( sa, a, sel );
    and AND2 ( sb, b, select );
    or OR1 ( s , sa, sb );
endmodule // mux

module test_f7;
// ------------------------- definir dados
 reg x;
 reg y;
 reg s;
 wire w;
 wire z;
 f7 modulo ( w, x, y );
 mux MUX1 ( z, x, y, s );
// ------------------------- parte principal
 initial
 begin : main
 $display("Guia_0701 - Rayssa Mell de Souza Silva - 860210");
 $display("Test LU's module");
 $display("   x    y    s    z");
 x = 1'b0; y = 1'b1; s = 1'b1;
 x = 1'b0; y = 1'b1; s = 1'b1;
 // projetar testes do modulo
 #1 $monitor("%4b %4b %4b %4b", x, y, s, z);
 #1 s = 1'b1;
 #1 s = 1'b0;
 end
endmodule // test_f7


/* Registro de Saída 

--- Opção 1:
a = 1   b = 0   chave = 1   => 0
a = 1   b = 0   chave = 0   => 1 passa a 
Teste:
   x    y    s    z
   1    0    0    1
   1    0    1    0

---Opção 2:
a = 0   b = 1   chave = 1   => 1 passa b
Teste: 
   x    y    s    z
   0    1    1    1
   0    1    0    0

*/