import sys
sys.path.insert(0,'../../../vcd2json')

from vcd2json import WaveExtractor

path_list = ['TOP/writepixels/d_clk',
             'TOP/writepixels/d_out']

extractor = WaveExtractor('trace.vcd', 'trace.json',path_list)
extractor.wave_format('TOP/blinky/display', 'b')
extractor.execute()
