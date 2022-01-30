#include <stdlib.h>
#include "Vmux.h"
#include "Vmux___024root.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vmux* dut = new Vmux;

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int sel = 0; sel < 2; sel++) {
                dut->a = a;
                dut->b = b;
                dut->sel = sel;
                dut->eval();

                printf("a=%d, b=%d, sel=%d; out=%d\n", a, b, sel, dut->out);
            }
        }
    }

    return 0;
}
