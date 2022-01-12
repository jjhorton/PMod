import sys
sys.path.insert(0,'../../../vcd2json')

from vcd2json import WaveExtractor

path_list = ['TOP/blinky/CLK',
             'TOP/blinky/LED',
             'TOP/blinky/counter',
             'TOP/blinky/display']

extractor = WaveExtractor('trace.vcd', 'trace.json',path_list)
extractor.wave_format('TOP/blinky/display', 'b')
extractor.execute()
