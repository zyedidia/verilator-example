# top module name
TOP=counter
# list of SystemVerilog source files
SV=counter.sv
# list of simulation c++ files
SIM=sim.cc
# output binary
BIN=sim
# output directory where Verilator dumps build files
ODIR=obj_dir

$(BIN): $(ODIR)/$(BIN)
	mv $< $@

$(ODIR)/$(BIN): $(SIM) $(SV)
	verilator -sv -cc --Mdir $(ODIR) $(SV) --top $(TOP) --exe --trace --build $< -o $(notdir $@)
