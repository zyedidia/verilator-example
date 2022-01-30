#include <stdlib.h>
#include "Vcounter.h"
#include "Vcounter___024root.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
    Verilated::traceEverOn(true);

    Verilated::commandArgs(argc, argv);

    Vcounter* dut = new Vcounter;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("trace.vcd");

    // simulate for 100 cycles
    const int maxtime = 100;
    for (int i = 0; i < maxtime; i++) {
        // reset for first 4 cycles
        dut->reset = i < 4;

        dut->clk = 0;
        dut->eval();
        tfp->dump(i*2);

        dut->clk = 1;
        dut->eval();
        tfp->dump(i*2+1);
        tfp->flush();
    }

    tfp->close();
    return 0;
}

