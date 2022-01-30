module mux
    (
        input logic a, b,
        input logic sel,
        output logic out
    );
    assign out = sel ? a : b;
endmodule
