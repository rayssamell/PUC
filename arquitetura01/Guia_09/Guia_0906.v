// ---------------------------
// -- test clock generator (7)
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

  always @ ( negedge clock )
    begin
    signal = 1'b1;
    #5 signal = 1'b0;
    end
endmodule // pulse

module Guia_0906;
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
    $dumpfile ( "Guia_0906.vcd" );
    $dumpvars ( 1, clock, p1, p);
    
    #376 $finish;
    end
endmodule // Guia_0906