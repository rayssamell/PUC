// -------------------------
// Guia_0803 - Equallity
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------
// -------------------------
// half difference
// -------------------------
module halfDifference (output s1,
                  output s0,
                  input a,
                  input b);
    // descrever por portas
    xor XOR1 ( s0, a, b );
    and AND1 ( s1, ~a, b );
endmodule // halfDifference

// -------------------------
// full difference
// -------------------------
module fullDifference ( output s1,
                   output s0,
                   input a,
                   input b,
                    input borrowIn  // Borrow-in
);
    wire s_half1, b_half1, b_half2;

    halfDifference HD (
        .s0(s_half1), 
        .s1(b_half1),  
        .a(a),
        .b(b)
    );

    xor XOR1 (s0, s_half1, borrowIn);

    and AND1 (b_half2, ~s_half1, borrowIn);
    or OR1 (s1, b_half1, b_half2);

endmodule // fullDifference

// -------------------------
// comparador de igualdade
// -------------------------
module ComparadorIgualdade (
    input [4:0] x,   
    input [4:0] y,   
    output igual     // Saida 1 se A == B, 0 se A != B
);

    wire s4, s3, s2, s1, s0; 

    // Comparação bit a bit usando XNOR 
    assign s4 = ~(x[4] ^ y[4]);  // Bit de sinal
    assign s3 = ~(x[3] ^ y[3]);  
    assign s2 = ~(x[2] ^ y[2]); 
    assign s1 = ~(x[1] ^ y[1]);  
    assign s0 = ~(x[0] ^ y[0]); 

    //os bits devem ser iguais
    assign igual = s4 & s3 & s2 & s1 & s0;
endmodule //ComparadorIgualdade

//modulo de teste
module test_equal;
    // ------------------------- definir dados
    
    reg [4:0] x;
    reg [4:0] y;
    wire [4:0] borrow;   // "vem-um"
    wire [4:0] subtractor;
    wire igual;

    ComparadorIgualdade comp (.x(x), .y(y), .igual(igual));
    // fullDifference ( borrow[0], subtractor[0], x[0], y[0] );
    fullDifference FA0 (borrow[0], subtractor[0], x[0], y[0], 1'b0 );   
    fullDifference FA1 (borrow[1], subtractor[1], x[1], y[1], borrow[0] ); 
    fullDifference FA2 (borrow[2], subtractor[2], x[2], y[2], borrow[1] );
    fullDifference FA3 (borrow[3], subtractor[3], x[3], y[3], borrow[2] ); 
    fullDifference FA4 (borrow[4], subtractor[4], x[4], y[4], borrow[3] ); 

    assign subtractor[4] = borrow[4]; // Borrow final

    // ------------------------- parte principal
    initial begin
    $display("Guia_0802 - Rayssa Mell de Souza Silva - 860210");
    $display("Test LU'S Equallity");

    $monitor("x = %b, y = %b, igual = %b, Subtractor: %b - %b = %b", x, y, igual, x, y, subtractor);
    
    // casos de teste
    x = 5'b01010;  // 10
    y = 5'b01010;  // 10
    #1; 
    
    x = 5'b11010;  // -6
    y = 5'b01010;  // 10
    #1;

    x = 5'b11100;  // -4
    y = 5'b00100;  // 4
    #1;

    x = 5'b01101;  // 13
    y = 5'b00111;  // 7
    #1;

end
endmodule // test_equal

/* Resultados

Guia_0802 - Rayssa Mell de Souza Silva - 860210
Test LU'S Equallity
x = 01010, y = 01010, igual = 1, Subtractor: 01010 - 01010 = 00000
x = 11010, y = 01010, igual = 0, Subtractor: 11010 - 01010 = x0000
x = 11100, y = 00100, igual = 0, Subtractor: 11100 - 00100 = x1000
x = 01101, y = 00111, igual = 0, Subtractor: 01101 - 00111 = 00110

*/