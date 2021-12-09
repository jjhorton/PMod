/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "MyLedDisp.h"

#include "pico/stdlib.h"

int main() {


	MyLedDisp Display2(0,2);
	Display2.enable();

	uint8_t display_buff[255];


	for(uint8_t pos = 0; pos<255; pos++){
		display_buff[pos] = 0b00000000;
	}

/*
	display_buff[0] = 0b10000010;
	display_buff[1] = 0b10000001;
	display_buff[2] = 0b11111110;
	display_buff[3] = 0b10000000;
	display_buff[4] = 0b00000000;
	display_buff[5] = 0b10000010;
	display_buff[6] = 0b10000001;
	display_buff[7] = 0b11111110;
	display_buff[8] = 0b10000000;
	display_buff[9] = 0b00000000;
	display_buff[10] = 0b11111111;
	display_buff[11] = 0b00001000;
	display_buff[12] = 0b00001000;
	display_buff[13] = 0b11111111;
*/


uint8_t character_store[27][5];
uint8_t character_len[27];
char character_value[27];
// Charcater A
character_value[0] = 'A';
character_len[0] = 4;
character_store[0][0] = 0b01111111;
character_store[0][1] = 0b10010000;
character_store[0][2] = 0b10010000;
character_store[0][3] = 0b01111111;

// Charcater B
character_value[1] = 'B';
character_len[1] = 4;
character_store[1][0] = 0b11111111;
character_store[1][1] = 0b10010001;
character_store[1][2] = 0b10010001;
character_store[1][3] = 0b01101110;

// Charcater C
character_value[2] = 'C';
character_len[2] = 3;
character_store[2][0] = 0b01111110;
character_store[2][1] = 0b10000001;
character_store[2][2] = 0b10000001;
character_store[2][3] = 0b00000000;

// Charcater D
character_value[3] = 'D';
character_len[3] = 4;
character_store[3][0] = 0b11111111;
character_store[3][1] = 0b10000001;
character_store[3][2] = 0b10000001;
character_store[3][3] = 0b01111110;

// Charcater E
character_value[4] = 'E';
character_len[4] = 3;
character_store[4][0] = 0b11111111;
character_store[4][1] = 0b10010001;
character_store[4][2] = 0b10010001;
character_store[4][3] = 0b00000000;

// Charcater F
character_value[5] = 'F';
character_len[5] = 3;
character_store[5][0] = 0b11111111;
character_store[5][1] = 0b10010000;
character_store[5][2] = 0b10000000;
character_store[5][3] = 0b00000000;

// Charcater G
character_value[6] = 'G';
character_len[6] = 3;
character_store[6][0] = 0b01111110;
character_store[6][1] = 0b10000001;
character_store[6][2] = 0b10001111;
character_store[6][3] = 0b00000000;

// Charcater H
character_value[7] = 'H';
character_len[7] = 4;
character_store[7][0] = 0b11111111;
character_store[7][1] = 0b00001000;
character_store[7][2] = 0b00001000;
character_store[7][3] = 0b11111111;

// Charcater I
character_value[8] = 'I';
character_len[8] = 3;
character_store[8][0] = 0b10000001;
character_store[8][1] = 0b11111111;
character_store[8][2] = 0b10000001;
character_store[8][3] = 0b00000000;

	// Charcater J
	character_value[9] = 'J';
	character_len[9] = 4;
	character_store[9][0] = 0b10000010;
	character_store[9][1] = 0b10000001;
	character_store[9][2] = 0b11111110;
	character_store[9][3] = 0b10000000;

	// Charcater K
	character_value[10] = 'K';
	character_len[10] = 4;
	character_store[10][0] = 0b11111111;
	character_store[10][1] = 0b00010100;
	character_store[10][2] = 0b00100010;
	character_store[10][3] = 0b11000001;

	// Charcater L
	character_value[11] = 'L';
	character_len[11] = 3;
	character_store[11][0] = 0b11111111;
	character_store[11][1] = 0b00000001;
	character_store[11][2] = 0b00000001;
	character_store[11][3] = 0b00000000;

	// Charcater M
	character_value[12] = 'M';
	character_len[12] = 5;
	character_store[12][0] = 0b11111111;
	character_store[12][1] = 0b01000000;
	character_store[12][2] = 0b00100000;
	character_store[12][3] = 0b01000000;
	character_store[12][4] = 0b11111111;

	// Charcater N
	character_value[13] = 'N';
	character_len[13] = 4;
	character_store[13][0] = 0b11111111;
	character_store[13][1] = 0b00110000;
	character_store[13][2] = 0b00001100;
	character_store[13][3] = 0b11111111;

	// Charcater O
	character_value[14] = 'O';
	character_len[14] = 4;
	character_store[14][0] = 0b01111110;
	character_store[14][1] = 0b10000001;
	character_store[14][2] = 0b10000001;
	character_store[14][3] = 0b01111110;

	// Charcater P
	character_value[15] = 'P';
	character_len[15] = 4;
	character_store[15][0] = 0b11111111;
	character_store[15][1] = 0b10010000;
	character_store[15][2] = 0b10010000;
	character_store[15][3] = 0b01100000;

	// Charcater Q
	character_value[16] = 'Q';
	character_len[16] = 4;
	character_store[16][0] = 0b01111110;
	character_store[16][1] = 0b10000001;
	character_store[16][2] = 0b01111110;
	character_store[16][3] = 0b00000011;

	// Charcater R
	character_value[17] = 'R';
	character_len[17] = 4;
	character_store[17][0] = 0b11111111;
	character_store[17][1] = 0b10010000;
	character_store[17][2] = 0b10010100;
	character_store[17][3] = 0b01100011;

	// Charcater S
	character_value[18] = 'S';
	character_len[18] = 4;
	character_store[18][0] = 0b01110001;
	character_store[18][1] = 0b10001001;
	character_store[18][2] = 0b10001001;
	character_store[18][3] = 0b10000110;

	// Charcater T
	character_value[19] = 'T';
	character_len[19] = 3;
	character_store[19][0] = 0b10000000;
	character_store[19][1] = 0b11111111;
	character_store[19][2] = 0b10000000;
	character_store[19][3] = 0b00000000;

	// Charcater U
	character_value[20] = 'U';
	character_len[20] = 4;
	character_store[20][0] = 0b11111110;
	character_store[20][1] = 0b00000001;
	character_store[20][2] = 0b00000001;
	character_store[20][3] = 0b11111110;

	// Charcater V
	character_value[21] = 'V';
	character_len[21] = 5;
	character_store[21][0] = 0b11110000;
	character_store[21][1] = 0b00001100;
	character_store[21][2] = 0b00000011;
	character_store[21][3] = 0b00001100;
	character_store[21][4] = 0b11110000;

	// Charcater W
	character_value[22] = 'W';
	character_len[22] = 5;
	character_store[22][0] = 0b11111110;
	character_store[22][1] = 0b00000001;
	character_store[22][2] = 0b00001110;
	character_store[22][3] = 0b00000001;
	character_store[22][4] = 0b11111110;

	// Charcater X
	character_value[23] = 'X';
	character_len[23] = 5;
	character_store[23][0] = 0b11000011;
	character_store[23][1] = 0b00100100;
	character_store[23][2] = 0b00011000;
	character_store[23][3] = 0b00100100;
	character_store[23][4] = 0b11000011;

	// Charcater Y
	character_value[24] = 'Y';
	character_len[24] = 3;
	character_store[24][0] = 0b11100000;
	character_store[24][1] = 0b00011111;
	character_store[24][2] = 0b11100000;
	character_store[24][3] = 0b00000000;

	// Charcater Z
	character_value[25] = 'Z';
	character_len[25] = 4;
	character_store[25][0] = 0b10000011;
	character_store[25][1] = 0b10001101;
	character_store[25][2] = 0b10110001;
	character_store[24][3] = 0b11000001;

	// Charcater [space]
	character_value[26] = ' ';
	character_len[26] = 3;
	character_store[26][0] = 0b00000000;
	character_store[26][1] = 0b00000000;
	character_store[26][2] = 0b00000000;

	int counter = 15;

	char my_str[20] = "MERRY CHRISTMAS";

	for(int my_char=0; my_char<20; my_char++){
		for(int i=0; i<26; i++){
			if (my_str[my_char] == character_value[i]){
				for(int j=0; j<character_len[i]; j++){
					display_buff[counter] = character_store[i][j];
					counter++;
				}
				display_buff[counter] = 0;
				counter++;
			}
			else if (isspace(y_str[my_char])){
			 counter = counter +4;
		 }
		}
	}

	while(1){

		uint8_t my_disp[16];

		for(uint8_t pos = 0; pos<16; pos++){
			my_disp[pos] = 0b00000000;
		}

		for(uint8_t main_pos = 0; main_pos<(255-16); main_pos++){

			for(uint8_t pos = 0; pos<16; pos++){
				my_disp[pos] = display_buff[main_pos+pos];
			}
			Display2.setDisplay(my_disp);
			sleep_ms(200);
		}


		sleep_ms(500);

	}

}
