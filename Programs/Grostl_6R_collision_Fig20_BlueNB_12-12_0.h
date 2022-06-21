#include <stdint.h>

typedef struct position24_7
{
	uint8_t a;
	uint128_t b;
}POSITION24_7,*Position24_7;

typedef struct chaine24_7
{
	unsigned char d0;
	unsigned char d1;
	unsigned char d2;
	unsigned char d3;
	unsigned char d4;
	unsigned char d5;
	unsigned char d6;
	uint8_t a;
	uint128_t b;
}CHAINE24_7,*Chaine24_7;

#define taille1_24 0x1000000000000000000000000L
#define taille2_24 0x1000000000000000000000000L
