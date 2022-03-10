PROJ = blinky
PIN_DEF = icebreaker.pcf
DEVICE = up5k
PACKAGE = sg48

check:
	verilator --lint-only -cc $(PROJ).v

coverage:
	verilator -Wall -GWIDTH=3 --trace --build --coverage -cc --exe $(PROJ).v test.cpp
	./obj_dir/Vblinky
	verilator_coverage logs/coverage.dat --annotate logs/annotated --write-info logs/coverage.info --write logs/results.txt --rank
	genhtml logs/coverage.info --output-directory logs/html
	lcov --list logs/coverage.info > logs/coverage.txt

build:
	yosys -p 'synth_ice40 -top blinky -json $(PROJ).json' $(PROJ).v
	nextpnr-ice40 --$(DEVICE) --package $(PACKAGE) --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc
	icepack $(PROJ).asc $(PROJ).bin

buildecp5:
	yosys -p 'synth_ecp5 -top blinky -json $(PROJ).json' $(PROJ).v
	nextpnr-ecp5 --45k --package CABGA381 --json $(PROJ).json --lpf colorlight.lpf --textcfg $(PROJ).config --freq 100
	ecppack --compress --bit $(PROJ).bin $(PROJ).config

progecp5:
	ecpdap program --freq 5000 $(PROJ).bin

flashecp5:
	ecpdap flash unprotect 
	ecpdap flash write --freq 5000 blinky.bin 

time:
	icetime -c 12 -d $(DEVICE) $(PROJ).asc

prog:
	iceprog $(PROJ).bin

clean:
	rm -f $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin
