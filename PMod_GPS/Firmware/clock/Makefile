PROJ = clock_count
PIN_DEF = icebreaker.pcf
DEVICE = up5k
PACKAGE = sg48

check:
	verilator --lint-only -cc $(PROJ).v

build:
	yosys -p 'synth_ice40 -top $(PROJ) -json $(PROJ).json' $(PROJ).v
	nextpnr-ice40 --$(DEVICE) --package $(PACKAGE) --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc
	icepack $(PROJ).asc $(PROJ).bin

test:
	verilator -Wall -GWIDTH=32 -GCLOCK_RATE_HZ=4000 -GBAUD_RATE=40 --trace --build --coverage -cc --exe $(PROJ).v test.cpp
	./obj_dir/Vclock_count
	verilator_coverage logs/coverage.dat --annotate logs/annotated --write-info logs/coverage.info --write logs/results.txt --rank
	genhtml logs/coverage.info --output-directory logs/html
	lcov --list logs/coverage.info > logs/coverage.txt

time:
	icetime -c 12 -d $(DEVICE) $(PROJ).asc

prog:
	iceprog $(PROJ).bin

clean:
	rm -rf logs/ obj_dir/ $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin trace.vcd
