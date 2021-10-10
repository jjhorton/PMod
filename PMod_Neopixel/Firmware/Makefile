PROJ = pixel
PIN_DEF = icebreaker.pcf
DEVICE = up5k
PACKAGE = sg48

check:
	verilator --lint-only -cc top.v

test:
	verilator -Wall --trace -Gclk_in_rate_hz=10000000 -cc writepixel.v
	make -C obj_dir -f Vwritepixel.mk
	clang++ -std=gnu++14 -I${VINC} -I obj_dir ${VINC}/verilated.cpp ${VINC}/verilated_vcd_c.cpp writepixel.cpp obj_dir/Vwritepixel__ALL.a -o writepixel
	./writepixel

test-top:
		verilator -Wall --trace -cc top.v writepixel.v
		make -C obj_dir -f Vtop.mk
		clang++ -std=gnu++14 -I${VINC} -I obj_dir ${VINC}/verilated.cpp ${VINC}/verilated_vcd_c.cpp test_top.cpp obj_dir/Vtop__ALL.a -o test_top
		./test_top

build:
	yosys -p 'synth_ice40 -top top -json $(PROJ).json' top.v writepixel.v rxuart.v
	nextpnr-ice40 --$(DEVICE) --package $(PACKAGE) --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc
	icepack $(PROJ).asc $(PROJ).bin

time:
	icetime -c 12 -d $(DEVICE) $(PROJ).asc

prog:
	iceprog $(PROJ).bin

clean:
	rm -rf obj_dir trace.vcd $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin test_top writepixel
