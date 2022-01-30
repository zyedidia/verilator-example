// Output q will count up to M and then reset. Max tick is asserted once every
// M cycles.
module counter
    #(
        parameter M = 10 // mod-M
    )
    (
        input  logic clk, reset,
        output logic max_tick,
        output logic [$clog2(M)-1:0] q
    );

    localparam N = $clog2(M);

    logic [N-1:0] r_reg;
    logic [N-1:0] r_next;

    always_ff @(posedge clk, posedge reset)
        if (reset)
            r_reg <= 0;
        else
            r_reg <= r_next;

    // next-state logic
    assign r_next = (r_reg == (M-1)) ? 0 : r_reg + 1;
    // output logic
    assign q = r_reg;
    assign max_tick = (r_reg == (M-1)) ? 1'b1 : 1'b0;
endmodule
