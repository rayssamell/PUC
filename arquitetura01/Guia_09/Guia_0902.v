// ---------------------------
// -- test clock generator (3)
// -- Rayssa Mell de Souza Silva - 860210
// ---------------------------
`include "clock.v"

module pulse1 ( signal, clock );
    input clock;
    output signal;
    reg signal;
    always @ ( posedge clock )
    begin
        signal = 1'b1;
        #4 signal = 1'b0;
        #4 signal = 1'b1;
        #4 signal = 1'b0;
        #4 signal = 1'b1;
        #4 signal = 1'b0;
    end
endmodule // pulse

module pulse2 ( signal, clock );
    input clock;
    output signal;
    reg signal;

    always @ ( posedge clock )
    begin
        signal = 1'b1;
        #5 signal = 1'b0;
        #5 signal = 1'b1;
        #5 signal = 1'b0;
        #5 signal = 1'b0;
        #5 signal = 1'b1;
    end
endmodule // pulse

module pulse3 ( signal, clock );
    input clock;
    output signal;
    reg signal;
    always @ ( negedge clock )
    begin
        signal = 1'b1;
        #15 signal = 1'b0;
        #15 signal = 1'b1;
        #15 signal = 1'b1;
        #15 signal = 1'b0;
    end
endmodule // pulse

module pulse4 ( signal, clock );
    input clock;
    output signal;
    reg signal;
    always @ ( negedge clock )
    begin
        signal = 1'b1;
        #20 signal = 1'b0;
        #20 signal = 1'b1;
        #20 signal = 1'b0;
        #20 signal = 1'b1;
    end
endmodule // pulse

module Guia_0902;
    wire clock;
    wire p1,p2,p3,p4;

    //instancias
    clock clk ( clock );
    pulse1 pls1 ( p1, clock );
    pulse2 pls2 ( p2, clock );
    pulse3 pls3 ( p3, clock );
    pulse4 pls4 ( p4, clock );

    //---- Parte principal
    initial begin
    $dumpfile ( "Guia_0902.vcd" );
    $dumpvars ( 1, clock, p1, p2, p3, p4 );
    #120 $finish;
    end
endmodule // Guia_0902