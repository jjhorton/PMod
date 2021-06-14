PROJ = blinky
PIN_DEF = icebreaker.pcf
DEVICE = up5k

check:
	verilator --lint-only -cc $(PROJ).v

build:
	yosys -p 'synth_ice40 -top blinky -json $(PROJ).json' $(PROJ).v
	nextpnr-ice40 --up5k --package sg48 --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc
	icepack $(PROJ).asc $(PROJ).bin

time:
	icetime -d $(DEVICE) -P sg48 $(PROJ).asc

prog:
		iceprog $(PROJ).bin

clean:
	rm -f $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin
