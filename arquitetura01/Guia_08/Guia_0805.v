// -------------------------
// Guia_0805 - Complemento de 2
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
    
    or   OR1(s1, w2, w3);
endmodule // fullAdder

// -------------------------
// complemento de 2
// -------------------------
module complemento2( input [5:0] a,     
                     output [5:0] comp2  // complemento de 2
);
    wire [5:0] comp1;   
    wire carry0, carry1, carry2, carry3, carry4, carry_out;    

    assign comp1 = ~a;

    // Somador para adicionar 1 ao complemento de 1
    fullAdder FA0(.a(comp1[0]), .b(1'b1), .carryIn(1'b0), .s0(comp2[0]), .s1(carry0));
    fullAdder FA1(.a(comp1[1]), .b(1'b0), .carryIn(carry0), .s0(comp2[1]), .s1(carry1));
    fullAdder FA2(.a(comp1[2]), .b(1'b0), .carryIn(carry1), .s0(comp2[2]), .s1(carry2));
    fullAdder FA3(.a(comp1[3]), .b(1'b0), .carryIn(carry2), .s0(comp2[3]), .s1(carry3));
    fullAdder FA4(.a(comp1[4]), .b(1'b0), .carryIn(carry3), .s0(comp2[4]), .s1(carry4));
    fullAdder FA5(.a(comp1[5]), .b(1'b0), .carryIn(carry4), .s0(comp2[5]), .s1(carry_out));
endmodule

//modulo de teste do complemento de dois
module test_complementoDois;
    // ------------------------- definir dados
    reg [5:0] x;
    wire [5:0] c2;

    complemento2 comp(.a(x), .comp2(c2));
   
    // ------------------------- parte principal
    initial begin
    $display("Guia_0805 - Rayssa Mell de Souza Silva - 860210");
    $display("Test LU'S Complemento de Dois");

    $monitor("x = %b, Complemento2 = %b", x, c2);
    
    // casos de teste
    x = 000010; 
    #1 x = 111010;
    #1 x = 001101; 

end
endmodule // test_complementoDois

/* Registro de Resultados:

Test LU'S Complemento de Dois
x = 001010, Complemento2 = 110110
x = 100010, Complemento2 = 011110
x = 001101, Complemento2 = 110011

*/