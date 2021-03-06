#ifndef MYLEDDISP_H
#define MYLEDDISP_H

class MyLedDisp
{
	private:
		uint8_t pin_clk;
		uint8_t pin_data;
  public:
    MyLedDisp(int data_pin , int clk_pin);

		void enable();
		void txData(uint8_t pos, uint8_t data);
		void setDisplay(uint8_t data[16]);
		void setValue(double value, uint8_t decimal);
		void setValue2(double value1, double value2, uint8_t decimal);
	};

#endif
