// ---------------------
// TRUTH TABLE
// Nome: Rayssa Mell de Souza Silva
// Matricula: 860210
//  Guia_0401.v
// ---------------------
// -- expression
// ---------------------

module fxyz (output s, input x, input y, input z);
    assign s = (~x | y) & ~(~y | z); 
endmodule

module Guia_0401;
    reg x, y, z;
    wire s;

    // instancias
    fxyz FXY1 (s, x, y, z);

    // valores iniciais
    initial begin: start
    x=1'bx; y=1'bx; z=1'bx; // indefinidos
    end
    // parte principal
    initial begin: main
    // identificacao
    $display("Tabela da Verdade");
    // monitoramento
    $display(" x  y  z  = s");
    $monitor("%2b %2b %2b = %2b", x, y, z, s);
    // sinalizacao
    #1 x=0; y=0; z=0;
    #1 x=0; y=0; z=1;
    #1 x=0; y=1; z=0;
    #1 x=0; y=1; z=1;
    #1 x=1; y=0; z=0;
    #1 x=1; y=0; z=1;
    #1 x=1; y=1; z=0;
    #1 x=1; y=1; z=1;
    end
endmodule // Guia_0401


/* Registro de Resultados 

01.) Tabela da Verdade
a.) x' . ( y'+z )'
Saída:  x  y  z  = s
        0  0  0 =  0
        0  0  1 =  0
        0  1  0 =  1
        0  1  1 =  0
        1  0  0 =  0
        1  0  1 =  0
        1  1  0 =  0
        1  1  1 =  0

b.) ( x' + y' )' . z
Saída:  x  y  z  = s
        0  0  0 =  0
        0  0  1 =  0
        0  1  0 =  0
        0  1  1 =  0
        1  0  0 =  0
        1  0  1 =  0
        1  1  0 =  0
        1  1  1 =  1

c.) ( x . y')' . z'
Saída:  x  y  z  = s
        x  x  x =  x
        0  0  0 =  1
        0  0  1 =  0
        0  1  0 =  1
        0  1  1 =  0
        1  0  0 =  0
        1  0  1 =  0
        1  1  0 =  1
        1  1  1 =  0

d.) ( x' . y )' . z
Saída: x  y  z  = s
       0  0  0 =  0
       0  0  1 =  1
       0  1  0 =  0
       0  1  1 =  0
       1  0  0 =  0
       1  0  1 =  1
       1  1  0 =  0
       1  1  1 =  1

e.) ( x' + y ) . ( y' + z)'
Saída:  x  y  z  = s
        0  0  0 =  0
        0  0  1 =  0
        0  1  0 =  1
        0  1  1 =  0
        1  0  0 =  0
        1  0  1 =  0
        1  1  0 =  1
        1  1  1 =  0
*/