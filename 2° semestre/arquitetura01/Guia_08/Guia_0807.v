// -------------------------
// Guia_0806 - Somador algebrico
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
// -------------------------

// -------------------------
// comparador de igualdade/desigualdade
// -------------------------
module Comparador (
    input [5:0] a,   
    input [5:0] b,    
    input chave,      // chave para slecionar igualdade (chave=0) ou desigualdade (chave=1)
    output resultado  
);

    wire igualdade, desigualdade;

    // Comparacao bit a bit
    wire [5:0] xor_result;
    assign xor_result = a ^ b;  // XOR retorna 1 se for diferente

    assign igualdade = ~(|xor_result); //se for tudo 0, igualdade = 1

    assign desigualdade = |xor_result; // se houver algum 1, desigualdade = 1

    // Selecao entre igualdade ou desigualdade baseado na chave
    assign resultado = (chave) ? desigualdade : igualdade;

endmodule

//modulo de teste
module test_Comparador;

    // ------------------------- definir dados
    reg [5:0] x;
    reg [5:0] y;
    reg chave;
    wire resultado;
    //instanciar modulo
    Comparador comp (.a(x), .b(y), .chave(chave), .resultado(resultado));

    // ------------------------- parte principal
    initial begin
    $display("Guia_0806 - Rayssa Mell de Souza Silva - 860210");
    $display("Test LU's - Comparador de Igualdade/Desigualdade");
    $monitor("x = %b, y = %b, chave = %b, resultado = %b", x, y, chave, resultado);

    // Testes
    x = 6'b000000; y = 6'b000000; chave = 0; #10; // Igualdade
    #1 x = 6'b000001; y = 6'b000001; chave = 0; #10; // Igualdade
    #1 x = 6'b000001; y = 6'b000010; chave = 1; #10; // Desigualdade
    #1 x = 6'b111111; y = 6'b111111; chave = 0; #10; // Igualdade
    #1 x = 6'b111111; y = 6'b000000; chave = 1; #10; // Desigualdade

    end
endmodule

/* Registro de Resultado

Guia_0806 - Rayssa Mell de Souza Silva - 860210
Test LU's - Comparador de Igualdade/Desigualdade
x = 000000, y = 000000, chave = 0, resultado = 1
x = 000001, y = 000001, chave = 0, resultado = 1
x = 000001, y = 000010, chave = 1, resultado = 1
x = 111111, y = 111111, chave = 0, resultado = 1
x = 111111, y = 000000, chave = 1, resultado = 1

*/

