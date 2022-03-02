import sys
sys.path.insert(0,'../../../vcd2json')

from vcd2json import WaveExtractor

path_list = ['TOP/top/writepixels/d_clk',
             'TOP/top/writepixels/d_out']

extractor = WaveExtractor('trace.vcd', 'trace.json',path_list)
extractor.wave_format('TOP/top/writepixels/display', 'b')
extractor.execute()
