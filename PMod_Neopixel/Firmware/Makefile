PROJ = neopixel
PIN_DEF = icebreaker.pcf
DEVICE = up5k

all: $(PROJ).bin

%.json: top.v
	yosys -p 'synth_ice40 -top top -json $(PROJ).json' top.v

%.asc: $(PIN_DEF) $(PROJ).json
	nextpnr-ice40 --up5k --package sg48 --json $(PROJ).json --pcf $(PIN_DEF) --asc $(PROJ).asc

%.bin: %.asc
	icepack $< $@

%.rpt: %.asc
	icetime -d $(DEVICE) -mtr $@ $<

prog: $(PROJ).bin
		iceprog $<

clean:
	rm -f $(PROJ).json $(PROJ).asc $(PROJ).rpt $(PROJ).bin
