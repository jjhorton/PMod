#ifndef RGB7SEG_H
#define RGB7SEG_H

const int Led_lookup[] = {   90,120,150,180,210,240, //D1  .. D6
                            183,213,243,  6, 36, 66, //D7  .. D12
                              3, 33, 63,  0, 30, 60, //D13 .. D18
                             93, 123, 153, 96,       //D19 .. D22
                             99,129,159,189,219,249, //D23 .. D28
                            192,222,252, 15, 45, 75, //D29 .. D34
                             12, 42, 72,  9, 39, 69, //D35 .. D40
                            102,132,162,105,135,165, //D41 .. D46
                            108,138,168,198,228,258, //D47 .. D52
                            201,231,261, 24, 54, 84, //D53 .. D58
                             21, 51, 81, 78, 48, 18, //D59 .. D64
                            111,141,171,114,         //D65 .. D68
                            117,147,177,207,237,267, //D69 .. D74
                            324,333,342,273,282,291, //D75 .. D80
                            270,279,288, 87, 57, 27, //D81 .. D86
                            297,306,315,300          //D87 .. D90 
                    };

const int Led_segments[][8][3]=  {{{1,2,3},{4,5,6},{7,8,9},{10,11,12},
                                   {13,14,15},{16,17,18},{19,20,21},{22,0,0}},
                                  {{23,24,25},{26,27,28},{29,30,31},{32,33,34},
                                   {35,36,37},{38,39,40},{41,42,43},{44, 0, 0}},
                                  {{47,48,49},{50,51,52},{53,54,55},{56,57,58},
                                   {59,60,61},{62,63,64},{65,66,67},{68, 0, 0}},
                                  {{69,70,71},{72,73,74},{75,76,77},{78,79,80},
                                   {81,82,83},{84,85,86},{87,88,89},{90,0,0}}
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
        void set_segment(uint8_t segment, uint8_t digit, uint8_t value[3]);
        uint8_t get_current();

        void set_scaling();

};
#endif