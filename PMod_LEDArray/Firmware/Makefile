PROJ = pixel
PIN_DEF = icebreaker.pcf
DEVICE = up5k
PACKAGE = sg48

check:
	verilator --lint-only -cc --top-module top top.v writepixels.v

test:
	verilator -Wall -Gclk_in_rate_hz=50000 --trace --build --coverage -cc --exe top.v writepixels.v test_top.cpp
	./obj_dir/Vtop
	verilator_coverage logs/coverage.dat --annotate logs/annotated --write-info logs/coverage.info --write logs/results.txt --rank
	genhtml logs/coverage.info --output-directory logs/html
	lcov --list logs/coverage.info > logs/coverage.txt

build:
	yosys -p 'synth_ice40 -top top -json $(PROJ).json' top.v writepixels.v
	nextpnr-ice40 --$(DEVICE) --package $(PACKAGE) --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc
	icepack $(PROJ).asc $(PROJ).bin

build-ecp:
	yosys -p 'synth_ecp5 -top top -json $(PROJ).json' top.v writepixels.v
	nextpnr-ecp5 --25k --package CABGA256 --json $(PROJ).json --lpf icesugarpro.lpf --textcfg $(PROJ).config --freq 25
	ecppack --compress --bit $(PROJ).bin $(PROJ).config

time:
	icetime -c 12 -d $(DEVICE) $(PROJ).asc

prog:
	iceprog $(PROJ).bin

prog-ecp5:
	ecpdap program $(PROJ).bin

clean:
	rm -rf obj_dir logs trace.vcd $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin test_top writepixel
