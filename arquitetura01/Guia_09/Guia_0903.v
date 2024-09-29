// ---------------------------
// -- test clock generator (4)
// -- Rayssa Mell de Souza Silva - 860210
// ---------------------------
`include "clock.v"

//--- 1/3 da frequencia do clock
module clk_div3(clk,reset, clk_out);
 
    input clk;
    input reset;
    output clk_out;
    
    reg [1:0] pos_count, neg_count;
    wire [1:0] r_nxt;
    
    always @(posedge clk)
        if (reset)
            pos_count <=0;
        else if (pos_count ==2) pos_count <= 0;
        else pos_count <= pos_count +1;
    
    always @(negedge clk)
        if (reset)
            neg_count <=0;
        else  if (neg_count ==2) neg_count <= 0;
        else neg_count<= neg_count +1;
    
    assign clk_out = ((pos_count == 2) | (neg_count == 2));
endmodule

module pulse1 ( signal, clock );
    input clock;
    output signal;
    reg signal;

    always @(posedge clock) 
    begin
        signal = 1'b1;
        #4 signal = 1'b0; 
    end
endmodule // pulse

`timescale 1ns/100ps
module Guia_0903;
    reg clk,reset;
    wire clk_out;
    wire p1;

    //instancias
    clk_div3 t1(clk, reset, clk_out);
    pulse1 pulse(p1, clk_out);

    initial
        clk= 1'b0;

    always 
        #12 clk = ~clk;
    
        initial 
            begin
            #5 reset= 1'b1;
            #10 reset= 1'b0;
            #500 $finish;
            end

    initial
        $monitor("clk=%b, reset=%b, clk_out=%b, p1=%b", clk, reset, clk_out, p1);

    initial begin
        $dumpfile("Guia_0903.vcd");
        $dumpvars(clk_out, p1);
    end
endmodule // Guia_0903

/* Registro de Resultado

clk=0, reset=x, clk_out=x, p1=x
clk=0, reset=1, clk_out=x, p1=x
clk=1, reset=1, clk_out=x, p1=x
clk=1, reset=0, clk_out=x, p1=x
clk=0, reset=0, clk_out=x, p1=x
clk=1, reset=0, clk_out=x, p1=x
clk=0, reset=0, clk_out=x, p1=x
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=x, p1=1
clk=0, reset=0, clk_out=x, p1=1
clk=1, reset=0, clk_out=1, p1=1
clk=0, reset=0, clk_out=1, p1=1

*/