// -------------------------
// Guia_0702 - GATES
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------
// -------------------------
// f7_gate
// -------------------------
module f7 (
  output s0, s1, s2, s3, s4,
  input a, b, sel
);
  nor NOR1 (s0, a, sel);      // Operacao NOR
  nor NOR2 (s1, sel, sel);    // Operacao NOR (equivalente a NOT)
  nor NOR3 (s2, s1, b);       // Operacao NOR
  or  OR1  (s3, s2, s2);      // Operacao OR (equivalente a s2)
  nor NOR4 (s4, s0, s3);      // Operacao NOR
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
    wire w1;
    wire w2;
    // descrever por portas
    nor NOR1 ( sa, a, select);
    nor NOR2 ( sel, select, select);
    nor NOR3 ( w2, sel, b);
    or OR1   ( sb, w2, w2);
    nor NOR4 ( s, sa, sb);
endmodule // mux

module test_f7;
// ------------------------- definir dados
 reg x;
 reg y;
 reg s;
 wire w;
 wire z;
 f7 modulo (w0, w1, w2, w3, w4, x, y, s);     
 mux MUX1 (z, x, y, s);    
// ------------------------- parte principal
 initial
 begin : main
 $display("Guia_0702 - Rayssa Mell de Souza Silva - 860210");
 $display("Test LU's module");
 $display("   x    y    s    z");
 //x = 1'b0; y = 1'b1; s = 1'b1;
 x = 1'b1; y = 1'b0; s = 1'b0;
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