#ifndef MY7SEG_H
#define MY7SEG_H

class My7Seg
{
	private:
		uint8_t pin_clk;
		uint8_t pin_data;
  public:
    My7Seg(int data_pin , int clk_pin);

		void enable();
		void txData(uint8_t pos, uint8_t data);
		void setdigit(uint8_t pos, uint8_t value, bool decimal);
		void setValue(double value, uint8_t decimal);
		void setValue2(double value1, double value2, uint8_t decimal);
	};

#endif
