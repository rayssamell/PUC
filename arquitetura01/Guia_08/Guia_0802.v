// -------------------------
// Guia_0800 - FULL DIFFERENCE
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

module test_fullDifference;
    // ------------------------- definir dados
    reg [4:0] x;
    reg [4:0] y;
    wire [4:0] borrow;   // "vem-um"
    wire [4:0] subtractor;
    
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
    $display("Test ALU's full Difference");
    $display("x    -   y  = subtractor");
    
    // Teste 1: Subtrair 4'b0101 (5) e 4'b0011 (3)  
    x = 4'b0101;  // 5
    y = 4'b0011;  // 3
    #1; 
    $display("%b - %b = %b", x, y, subtractor);
        
    // Teste 2: Subtrair 4'b1111 (15) e 4'b0111 (7)
    x = 4'b1111;  // 15
    y = 4'b0111;  // 7
    #1;
    $display("%b - %b = %b", x, y, subtractor);
        
    // Teste 3: Subtrarir 4'b1001 (-7) com 4'b0110 (6)
    x = 4'b1001;  // -7 
    y = 4'b0110;  // 6
    #1;
    $display("%b - %b = %b", x, y, subtractor);

end
endmodule // test_fullDifference

/* Resultados

Guia_0802 - Rayssa Mell de Souza Silva - 860210
Test ALU's full Difference
x    -   y  = subtractor
00101 - 00011 = 00010
01111 - 00111 = 01000
01001 - 00110 = 00011

*/