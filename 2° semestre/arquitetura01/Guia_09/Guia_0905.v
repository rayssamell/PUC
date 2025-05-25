// ---------------------------
// -- test clock generator (6)
// -- Rayssa Mell de Souza Silva - 860210
// ---------------------------

module clock ( output clk );
 reg    clk;
 initial
  begin
    clk = 1'b0;
 end

 always
  begin
    #12 clk = ~clk;
  end
endmodule

module pulse ( signal, clock );
  input clock;
  output signal;
  reg signal;

  always @ ( posedge clock )
    begin
    signal = 1'b1;
    #4 signal = 1'b0;
    #4 signal = 1'b1;
    end
endmodule // pulse

module Guia_0905;
    wire clock;
    reg p;
    wire p1;
    
    //instancia
    clock clk ( clock );
    pulse pulse1 ( p1, clock );
   
    initial begin
        p = 1'b0;
    end
    initial begin
    $dumpfile ( "Guia_0905.vcd" );
    $dumpvars ( 1, clock, p1, p);
    #060 p = 1'b1;
    #120 p = 1'b0;
    #180 p = 1'b1;
    #240 p = 1'b0;
    #300 p = 1'b1;
    #360 p = 1'b0;
    #376 $finish;
    end
endmodule // Guia_0905