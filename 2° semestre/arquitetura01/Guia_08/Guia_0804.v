// -------------------------
// Guia_0804 - Difference
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
// comparador de diferenca
// -------------------------
module ComparadorDiferenca (
    input [4:0] x,   
    input [4:0] y,   
    output difference     // Saida 1 se A != B, 0 se A == B
);

    wire s4, s3, s2, s1, s0; 

    // Comparação bit a bit usando XOR 
    assign s4 = (x[4] ^ y[4]);  // Bit de sinal
    assign s3 = (x[3] ^ y[3]);  
    assign s2 = (x[2] ^ y[2]); 
    assign s1 = (x[1] ^ y[1]);  
    assign s0 = (x[0] ^ y[0]); 

    //os bits devem ser diferentes
    assign difference = (s4 | s3 | s2 | s1 | s0);
endmodule //ComparadorDiferenca

//modulo de teste
module test_difference;
    // ------------------------- definir dados
    
    reg [4:0] x;
    reg [4:0] y;
    wire [4:0] borrow;   // "vem-um"
    wire [4:0] subtractor;
    wire difference;

    ComparadorDiferenca comp (.x(x), .y(y), .difference(difference));
   
    fullDifference FA0 (borrow[0], subtractor[0], x[0], y[0], 1'b0 );   
    fullDifference FA1 (borrow[1], subtractor[1], x[1], y[1], borrow[0] ); 
    fullDifference FA2 (borrow[2], subtractor[2], x[2], y[2], borrow[1] );
    fullDifference FA3 (borrow[3], subtractor[3], x[3], y[3], borrow[2] ); 
    fullDifference FA4 (borrow[4], subtractor[4], x[4], y[4], borrow[3] ); 

    assign subtractor[4] = borrow[4]; // Borrow final

    // ------------------------- parte principal
    initial begin
    $display("Guia_0804 - Rayssa Mell de Souza Silva - 860210");
    $display("Test LU'S Difference");

    $monitor("x = %b, y = %b, diferente = %b, Subtractor: %b - %b = %b", x, y, difference, x, y, subtractor);
    
    // casos de teste
    x = 5'b00101; // 5
    y = 5'b00010; // 2
    #1;

    x = 5'b01000; // 8
    y = 5'b00101; // 5
    #1;

    x = 5'b01111; // 15
    y = 5'b01000; // 8
    #1;

    x = 5'b10000; // -16
    y = 5'b00100; // 4
    #1;

end
endmodule // test_difference

/* Resultados

Guia_0804 - Rayssa Mell de Souza Silva - 860210
Test LU'S Difference
x = 00101, y = 00010, diferente = 1, Subtractor: 00101 - 00010 = 00011
x = 01000, y = 00101, diferente = 1, Subtractor: 01000 - 00101 = 00011
x = 01111, y = 01000, diferente = 1, Subtractor: 01111 - 01000 = 00111
x = 10000, y = 00100, diferente = 1, Subtractor: 10000 - 00100 = 01100

*/