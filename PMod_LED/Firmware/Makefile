PROJ = blinky
PIN_DEF = icebreaker.pcf
DEVICE = up5k
PACKAGE = sg48

check:
	verilator --lint-only -cc $(PROJ).v

coverage:
	verilator -Wall --trace --build --coverage -cc --exe $(PROJ).v test.cpp
	./obj_dir/Vblinky
	verilator_coverage logs/coverage.dat --annotate logs/annotated --write-info logs/coverage.info --write logs/results.txt --rank
	genhtml logs/coverage.info --output-directory logs/html
	lcov --list logs/coverage.info > logs/coverage.txt

build:
	yosys -p 'synth_ice40 -top blinky -json $(PROJ).json' $(PROJ).v
	nextpnr-ice40 --$(DEVICE) --package $(PACKAGE) --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc
	icepack $(PROJ).asc $(PROJ).bin

time:
	icetime -c 12 -d $(DEVICE) $(PROJ).asc

prog:
	iceprog $(PROJ).bin

clean:
	rm -f $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin
