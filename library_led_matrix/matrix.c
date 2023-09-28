#include "matrix.h"
#include "string.h"
uint8_t disp1ay[61][8] = {

	{0x0,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  //space
	// --------------dữ liệu ảo--------------------------------//
	{0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x7c},
	{0x7E,0x2,0x2,0x7E,0x40,0x40,0x40,0x7E},
	{0x3E,0x2,0x2,0x3E,0x2,0x2,0x3E,0x0},
	{0x8,0x18,0x28,0x48,0xFE,0x8,0x8,0x8},
	{0x3C,0x20,0x20,0x3C,0x4,0x4,0x3C,0x0},
	{0x3C,0x20,0x20,0x3C,0x24,0x24,0x3C,0x0},
	{0x3E,0x22,0x4,0x8,0x8,0x8,0x8,0x8},
	{0x0,0x3E,0x22,0x22,0x3E,0x22,0x22,0x3E},
	{0x3E,0x22,0x22,0x3E,0x2,0x2,0x2,0x3E},
	{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},
	{0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x7c},
	{0x7E,0x2,0x2,0x7E,0x40,0x40,0x40,0x7E},
	{0x3E,0x2,0x2,0x3E,0x2,0x2,0x3E,0x0},
	{0x8,0x18,0x28,0x48,0xFE,0x8,0x8,0x8},
	{0x3C,0x20,0x20,0x3C,0x4,0x4,0x3C,0x0},
    //----------------------------------------------------------//
	{0x0,0x3C,0x24,0x24,0x24,0x24,0x3C,0x0}, //0
	{0x0,0x8,0x18,0x28,0x8,0x8,0x3C,0x0}, //1
	{0x0,0x3C,0x4,0x3C,0x20,0x20,0x3C,0x0}, // 2
	{0x0,0x3C,0x4,0x3C,0x4,0x4,0x3C,0x0}, // 3
	{0x0,0x4,0xC,0x14,0x3E,0x4,0x4,0x0}, //4
	{0x3C,0x20,0x20,0x3C,0x04,0x04,0x3C,0x00},//5
	{0x3C,0x20,0x20,0x3C,0x24,0x24,0x3C,0x00},//6
	{0x0,0x3C,0x4,0x8,0x8,0x8,0x8,0x0}, //7
	{0x0,0x3C,0x24,0x3C,0x24,0x24,0x3C,0x0}, //8
	{0x0,0x3C,0x24,0x3C,0x4,0x4,0x3C,0x0}, //9

//-------------vớ vẩn----------------------//
	{0x3E,0x2,0x2,0x3E,0x2,0x2,0x3E,0x0},       //3
	{0x8,0x18,0x28,0x48,0xFE,0x8,0x8,0x8},      //4
	{0x3C,0x20,0x20,0x3C,0x4,0x4,0x3C,0x0},//5
	{0x3C,0x20,0x20,0x3C,0x24,0x24,0x3C,0x0},//6
	{0x3E,0x22,0x4,0x8,0x8,0x8,0x8,0x8},//7
	{0x0,0x3E,0x22,0x22,0x3E,0x22,0x22,0x3E},//8
	{0x3E,0x22,0x22,0x3E,0x2,0x2,0x2,0x3E},//9


	{0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42},//A
	{0x3C,0x22,0x22,0x3c,0x22,0x22,0x3C,0x00},//B
	{0x3C,0x40,0x40,0x40,0x40,0x40,0x40,0x3C},//C
	{0x7C,0x22,0x22,0x22,0x22,0x22,0x22,0x7C},//D
	{0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x7C},//E
	{0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x40},//F
	{0x3C,0x40,0x40,0x40,0x4c,0x44,0x44,0x3C},//G
	{0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44},//H
	{0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x7C},//I
	{0x3C,0x08,0x08,0x08,0x08,0x08,0x48,0x30},//J
	{0x00,0x24,0x28,0x30,0x20,0x30,0x28,0x24},//K
	{0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C},//L
	{0x00,0x42,0x66,0x5A,0x42,0x42,0x42,0x42},//M
	{0x00,0x42,0x62,0x52,0x4A,0x46,0x42,0x00},//N
	{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
	{0x3C,0x22,0x22,0x22,0x3C,0x20,0x20,0x20},//P
	{0x1C,0x22,0x22,0x22,0x22,0x26,0x22,0x1D},//Q
	{0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
	{0x00,0x1E,0x20,0x20,0x3E,0x02,0x02,0x3C},//S
	{0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08},//T
	{0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1C},//U
	{0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18},//V
	{0x00,0x49,0x49,0x49,0x49,0x2A,0x1C,0x00},//W
	{0x00,0x41,0x22,0x14,0x08,0x14,0x22,0x41},//X
	{0x41,0x22,0x14,0x08,0x08,0x08,0x08,0x08},//Y
	{0x00,0x7F,0x02,0x04,0x08,0x10,0x20,0x7F},//Z
};
unsigned char map_row[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
void Init (void)
{
	SendAddrDat (0x0c,0x01);
	SendAddrDat (0x0a,0x09);
	SendAddrDat (0x0b,0x07);
	SendAddrDat (0x09,0x00);
	SendAddrDat (0x0f,0x00);
}
void Shiftbyte(unsigned char  data)
{
  unsigned char i;
  for (i = 0; i < 8; i++)
  {
      if (data & 0x80) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
      else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
      data = data << 1;
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
  }
}
void SendAddrDat (unsigned char addr,unsigned char data)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
	Shiftbyte (addr);
	Shiftbyte (data);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);
}
void Print_Text(char text){
	for(unsigned char i = 0; i < 8 ; i++){
	  SendAddrDat(map_row[i], (disp1ay[text - 32][i]));
	}
}
void Print_CharMatrix_LEFT(char text){
	for(unsigned char j = 0; j < 8; j++){
	  for(unsigned char i = 0; i < 8 ; i++){
		  SendAddrDat(map_row[i], (disp1ay[text - 32][i] << j) | (disp1ay[text - 32][i] >> (8-j)));
	  }
	  HAL_Delay(100);
	}
}

void Print_CharMatrix_RIGHT(char text){
	for(unsigned char j = 0; j < 8; j++){
	  for(unsigned char i = 0; i <8 ; i++){
		  SendAddrDat(map_row[i], (disp1ay[text - 32][i] >> j) | (disp1ay[text - 32][i] << (8-j)));
	  }
	  HAL_Delay(100);
	}
}

void Print_StringMatrix(char *s){
	for(unsigned char k = 0; k < strlen(s) - 1; k++){
		for(unsigned char j = 0; j < 8; j++){
		  for(unsigned char i = 0; i < 8 ; i++){
			  unsigned char tmp = (disp1ay[s[k] - 32][i] << j);
			  unsigned char tmp_t = (disp1ay[s[k+1] - 32][i] >> (8-j));
			  SendAddrDat(map_row[i],  tmp | tmp_t );
		  }
		  HAL_Delay(100);
		}
	}
}

void Print_StringMatrix_UP3(char *s){
	char str[100] = " ";
	strcat(str, s);
	for(unsigned char k = 0; k < strlen(str)-1; k++){
		for(unsigned char j = 1; j < 9; j++){
		  for(unsigned char i = 0; i < 8-j ; i++){
			  if(i>=1 && i<= 6)
			  SendAddrDat(map_row[i], (disp1ay[str[k] - 32][(i+j) % 8]));
		  }
		  for(unsigned char i = 8-j; i < 8 ; i++){
			  if(i>=1 && i<= 6)
			  SendAddrDat(map_row[i], (disp1ay[str[k+1] - 32][(i+j) % 8]));
		  }
		  HAL_Delay(100);
		}
		HAL_Delay(300);
	}
}

void Print_StringMatrix_UP(char text){
	for(unsigned char j = 0; j < 8; j++){
	  for(unsigned char i = 0; i < 8 ; i++){
		  SendAddrDat(map_row[i], (disp1ay[text - 32][(i+j) % 8]));
	  }
	  HAL_Delay(100);
	}
}
void Print_StringMatrix_DOWN(char text){
	for(unsigned char j = 7; j >= 0; j--){
	  for(unsigned char i = 0; i < 8 ; i++){
		  SendAddrDat(map_row[i], (disp1ay[text - 32][(i+j) % 8]));
	  }
	  HAL_Delay(100);
	}
}