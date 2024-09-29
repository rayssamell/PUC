// -------------------------
// Guia_0801 - FULL ADDER
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------
// -------------------------
// half adder
// -------------------------
module halfAdder (output s1,
                  output s0,
                  input a,
                  input b);
    // descrever por portas
    xor XOR1 ( s0, a, b );
    and AND1 ( s1, a, b );
endmodule // halfAdder

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
    
    or   OR1(s1, w2, w3);
endmodule // fullAdder

module test_fullAdder;
    // ------------------------- definir dados
    reg [3:0] x;
    reg [3:0] y;
    wire [3:0] carry; // “vai-um”
    wire [4:0] soma;
    // halfAdder HA0 ( carry[0], soma[0], x[0], y[0] );
    fullAdder FA0 ( carry[0], soma[0], x[0], y[0], 1'b0 );
    fullAdder FA1 ( carry[1], soma[1], x[1], y[1], carry[0] );  
    fullAdder FA2 ( carry[2], soma[2], x[2], y[2], carry[1] );   
    fullAdder FA3 ( carry[3], soma[3], x[3], y[3], carry[2] );  

    assign soma[4] = carry[3]; // Carry final
    // ------------------------- parte principal
    initial begin
    $display("Guia_0800 - Rayssa Mell de Souza Silva - 860210");
    $display("Test ALU's full adder");
    $display("x    + y     = soma");
    
    // Teste 1: Somar 4'b0011 (3) com 4'b0101 (5)
    x = 4'b0011;  // 3
    y = 4'b0101;  // 5
    #1; // Aguarda 1 unidade de tempo
    $display("%b + %b = %b", x, y, soma);
        
    // Teste 2: Somar 4'b1111 (15) com 4'b0001 (1)
    x = 4'b1111;  // 15
    y = 4'b0001;  // 1
    #1;
    $display("%b + %b = %b", x, y, soma);
        
    // Teste 3: Somar 4'b1001 (-7) com 4'b0110 (6)
    x = 4'b1001;  // -7 
    y = 4'b0110;  // 6
    #1;
    $display("%b + %b = %b", x, y, soma);
    
    end
endmodule // test_fullAdder

/* Resultados:

Guia_0800 - Rayssa Mell de Souza Silva - 860210
Test ALU's full adder
x    + y     = soma
0011 + 0101 = 01000
1111 + 0001 = 10000
1001 + 0110 = 01111


*/