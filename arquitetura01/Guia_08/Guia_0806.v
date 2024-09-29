// -------------------------
// Guia_0806 - Somador algebrico
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

// -------------------------
// full adder
// -------------------------
module fullAdder ( output s1,
                   output s0,
                   input a,
                   input b,
                   input carryIn );

    wire w1, w2, w3;

    // descrever por portas e/ou modulos
    xor XOR1(w1, a, b);
    xor XOR2(s0, w1, carryIn);

    and AND1(w2, a, b);
    and AND2(w3, w1, carryIn);
    
    or  OR1(s1, w2, w3);
endmodule // fullAdder

// -------------------------
// Complemento de 1 
// -------------------------
module complemento1 (
    output [5:0] s,   // Saída com o complemento de 1
    input [5:0] cin,     
    input sel           // Seletor (0 = in, 1 = ~cin)
);
    assign s = sel ? ~cin : cin + 1;   //soma 1 para complemento de 2
endmodule

// -------------------------
// Somador Algebrico (Soma/Subtração)
// -------------------------
module somador_algebrico (
    output [5:0] s,   
    output carryOut,       
    input [5:0] a,         
    input [5:0] b,         
    input carryIn          // Selecao (0 = soma, 1 = subtracao)
);
    wire [5:0] b_comp;     // B apos complemento (se subtracao)
    wire c0, c1, c2, c3, c4;
    // Complemento de 1 condicionado pelo carryIn
    complemento1 comp1 (b_comp, b, carryIn);

    // Somadores completos para cada bit
    fullAdder FA0 (c0, s[0], a[0], b_comp[0], carryIn);
    fullAdder FA1 (c1, s[1], a[1], b_comp[1], c0);
    fullAdder FA2 (c2, s[2], a[2], b_comp[2], c1);
    fullAdder FA3 (c3, s[3], a[3], b_comp[3], c2);
    fullAdder FA4 (c4, s[4], a[4], b_comp[4], c3);
    fullAdder FA5 (carryOut, s[5], a[5], b_comp[5], c4);
endmodule

// -------------------------
// Comparador de Igualdade
// -------------------------
module comparador_igualdade (
    output equal,        
    input [5:0] a,       
    input [5:0] b        
);
    assign equal = (a == b);  // Verifica se A e B sao iguais
endmodule

// -------------------------
// Modulo para resultado
// -------------------------
module Guia_0806 (
    output [5:0] s,   
    output equal,         
    output not_equal,     
    input [5:0] a,        
    input [5:0] b,         
    input carryIn,        
    input chave            // chave para selecionar resultado (igualdade/desigualdade)
);
    wire [5:0] soma_sub;   // resultado da operação aritmetica
    wire igualdade;        // sinal de igualdade

    // somador algebrico
    somador_algebrico sa (soma_sub, carryOut , a, b, carryIn);

    // comparador de igualdade
    comparador_igualdade comp (igualdade, a, b);

    // Saida final com base na chave 
    assign s = chave ? {5'b00000, igualdade} : soma_sub;
    assign equal = igualdade;
    assign not_equal = ~igualdade;
endmodule

// -------------------------
// modulo de Teste
// -------------------------
module test_Guia_0806;
    // ------------------------- definir dados
    reg [5:0] a;
    reg [5:0] b;
    reg carryIn; //vai-um
    reg chave;  //seletor para igualdade/desigualdade
    wire [5:0] result;
    wire equal; //igualdade
    wire not_equal;  //desigualdade

    // Instancia do modulo principal
    Guia_0806 guia (result, equal, not_equal, a, b, carryIn, chave);

    // ------------------------- parte principal
    initial begin
    $display("Guia_0806 - Rayssa Mell de Souza Silva - 860210");
    $display("Test LU's");
    $monitor("a=%b, b=%b, carryIn=%b, chave=%b -> result=%b, equal=%b, not_equal=%b", a, b, carryIn, chave, result, equal, not_equal);

    // Casos de teste
    a = 6'b000101; b = 6'b000011; carryIn = 0; chave = 0;    // Soma
    #1 a = 6'b000101; b = 6'b000011; carryIn = 1; chave = 0;  // Subtracao
    #1 a = 6'b000101; b = 6'b000101; carryIn = 0; chave = 1; // Igualdade
    #1 a = 6'b000101; b = 6'b000011; carryIn = 1; chave = 1; // Desigualdade
    end
endmodule

/* Registro de Resultado:

Guia_0806 - Rayssa Mell de Souza Silva - 860210
Test LU's
a=000101, b=000011, carryIn=0, chave=0 -> result=001001, equal=0, not_equal=1
a=000101, b=000011, carryIn=1, chave=0 -> result=000010, equal=0, not_equal=1
a=000101, b=000101, carryIn=0, chave=1 -> result=000001, equal=1, not_equal=0
a=000101, b=000011, carryIn=1, chave=1 -> result=000000, equal=0, not_equal=1

*/