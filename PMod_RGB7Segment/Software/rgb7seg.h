#ifndef RGB7SEG_H
#define RGB7SEG_H

const int Led_lookup[] = {  90,120,150,180,210,240, //D1 .. D6
                            183,213,243, 6, 36, 66, //D7 .. D12
                              3, 33, 63, 0, 30, 60, //D13 .. D18
                              93, 123, 153, 96
                    };

class RGB7Seg
{
    private:
        uint8_t current_page = 0;
        uint8_t address = 0x30;
        uint8_t rgb_values[197][3];


    public:
        RGB7Seg();
        void enable();
        uint8_t reset();
        uint8_t get_id();
        void unlock();
        uint8_t select_page(uint8_t page);
        
        void set_LED(int pos, uint8_t value[3]);
        void set_pixel(int led, int rgb);
        void set_current(uint8_t current);
        uint8_t get_current();

        void set_scaling();

};
#endif