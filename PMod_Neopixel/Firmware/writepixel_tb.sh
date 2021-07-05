export VINC=/opt/homebrew/Cellar/verilator/4.200/share/verilator/include
verilator -Wall --trace -Gclk_in_rate_hz=12000000 -cc writepixel.v
make -C obj_dir -f Vwritepixel.mk
# g++ -I${VINC} -I obj_dir ${VINC}/verilated.cpp ${VINC}/verilated_vcd_c.cpp writepixel.cpp obj_dir/Vwritepixel__ALL.a -o writepixel
clang++ -std=gnu++14 -I${VINC} -I obj_dir ${VINC}/verilated.cpp ${VINC}/verilated_vcd_c.cpp writepixel.cpp obj_dir/Vwritepixel__ALL.a -o writepixel
./writepixel
