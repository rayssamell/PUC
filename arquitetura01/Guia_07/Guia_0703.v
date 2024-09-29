// -------------------------
// Guia_0703 - GATES
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------
// -------------------------
// f7_gate
// -------------------------

// -------------------------
// multiplexer
// -------------------------
module mux (
    output s1,   // Saída para AND/NAND
    output s2,   // Saída para OR/NOR
    input a,
    input b,
    input sel1,  // Seleção para AND/NAND
    input sel2   // Seleção para OR/NOR
);

    // definir dados locais
    wire w1;
    wire w2;
    wire w3;
    wire w4;
    wire w5;
    wire w6;
    wire w7;


    // descrever por portas
    nand NAND1 (w1, sel1, sel1);
    nand NAND2 (w2, w1, a);
    nand NAND3 (w3, sel1, b);
    nand NAND4 (s1, w2, w3);

    nor NOR1 ( w4, sel2, sel2);
    nor NOR2 ( w5, sel2, a);
    nor NOR3 ( w6, w4, b);
    or OR1   ( w7, w6, w6);
    nor NOR4 ( s2, w5, w7);
endmodule // mux

module test_f7;
// ------------------------- definir dados
    reg x; // a
    reg y; // b
    reg s1; 
    reg s2; 
    wire sel1; 
    wire sel2; 

    mux MUX1 (sel1, sel2, x, y, s1, s2);    
// ------------------------- parte principal
 initial
 begin : main
    $display("Guia_0703 - Rayssa Mell de Souza Silva - 860210");
    $display("Test LU's module");
    $display("   x    y    s1  s2   sel1  sel2");
    x = 1'b0; y = 1'b0; s1 = 1'b0; s2 = 1'b0; 

  //projetar teste do modulo
  #1 $monitor("%4b %4b %4b %4b %4b %4b", x, y, sel1, sel2, s1, s2);
  #1 x = 0; y = 1; s1 = 0; s2 = 0;
  #1 x = 1; y = 0; s1 = 1; s2 = 0; 
  #1 x = 1; y = 0; s1 = 0; s2 = 1; 
  #1 x = 0; y = 1; s1 = 1; s2 = 0; 
  #1 x = 1; y = 0; s1 = 0; s2 = 0; 
  #1 x = 0; y = 1; s1 = 0; s2 = 1; 
 end
endmodule // test_f7


/* Registro de Saída 

Guia_0703 - Rayssa Mell de Souza Silva - 860210
Test LU's module
   x    y    s1  s2   sel1  sel2
   0    0    0    0    0    0
   0    1    0    0    0    0
   1    0    0    1    1    0
   1    0    1    0    0    1
   0    1    1    0    1    0
   1    0    1    1    0    0
   0    1    0    1    0    1

*/