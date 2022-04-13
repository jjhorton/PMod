#ifndef RGB7SEG_H
#define RGB7SEG_H

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
        
        void set_LED(int pos, int value);
        void set_current(uint8_t current);
        uint8_t get_current();

        void set_scaling();

};
#endif