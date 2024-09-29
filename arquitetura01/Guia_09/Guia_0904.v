// ---------------------------
// -- test clock generator (5)
// -- Rayssa Mell de Souza Silva - 860210
// ---------------------------
`include "clock.v"

//--- 1/4 do periodo do clock
module clk_div4(clk,reset, clk_out);
 
    input clk;
    input reset;
    output clk_out;
    
    reg [1:0] r_reg;
    wire [1:0] r_nxt;
    reg clk_track;
    
    always @(posedge clk or posedge reset)
    begin
        if (reset)
            begin
                r_reg <= 3'b0;
                clk_track <= 1'b0;
            end
        else if (r_nxt == 2'b10) 
            begin
                r_reg <= 0;
                clk_track <= ~clk_track;
            end
        else r_reg <= r_nxt;
    end

    assign r_nxt = r_reg+1;
    assign clk_out = clk_track;
endmodule

module pulse ( signal, clock );
    input clock;
    output signal;
    reg signal;

    always @(posedge clock) 
    begin
        signal = 1'b1;
        #4 signal = 1'b0; 
    end
endmodule // pulse

module Guia_0904;
    reg clk, reset;
    wire clk_out;
    wire p1;

    //instancias
    clk_div4 t1(clk, reset, clk_out);
    pulse pulse1(p1, clk_out);

    initial
        clk= 1'b0;

    always 
        #5 clk = ~clk;
    
        initial 
            begin
            #5 reset= 1'b1;
            #10 reset= 1'b0;
            #500 $finish;
            end

    initial
        $monitor("clk=%b, reset=%b, clk_out=%b, p1=%b", clk, reset, clk_out, p1);

    initial begin
        $dumpfile(" Guia_0904.vcd");
        $dumpvars(1, clk_out, p1);
    end
endmodule // Guia_0904

/* Registro de Resultado

clk=0, reset=x, clk_out=x, p1=x
clk=1, reset=1, clk_out=0, p1=x
clk=0, reset=1, clk_out=0, p1=x
clk=1, reset=0, clk_out=0, p1=x
clk=0, reset=0, clk_out=0, p1=x
clk=1, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=1, p1=0
clk=0, reset=0, clk_out=1, p1=0
clk=1, reset=0, clk_out=1, p1=0
clk=0, reset=0, clk_out=1, p1=0
clk=1, reset=0, clk_out=0, p1=0
clk=0, reset=0, clk_out=0, p1=0
clk=1, reset=0, clk_out=0, p1=0
clk=0, reset=0, clk_out=0, p1=0
clk=1, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=1, p1=0
clk=0, reset=0, clk_out=1, p1=0
clk=1, reset=0, clk_out=1, p1=0
clk=0, reset=0, clk_out=1, p1=0
clk=1, reset=0, clk_out=0, p1=0
clk=0, reset=0, clk_out=0, p1=0
clk=1, reset=0, clk_out=0, p1=0
clk=0, reset=0, clk_out=0, p1=0
clk=1, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=1, p1=0
clk=0, reset=0, clk_out=1, p1=0
clk=1, reset=0, clk_out=1, p1=0

./clock.v:24: $finish called at 120 (1s)

clk=0, reset=0, clk_out=1, p1=0

*/