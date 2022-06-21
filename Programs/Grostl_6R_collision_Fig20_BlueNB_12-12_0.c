#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Grostl_6R_collision_Fig20_BlueNB_12-12_0.h"

const unsigned char sbox[256] = {
	//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F   
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0  
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1   
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2   
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3   
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4   
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5   
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6   
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7   
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8   
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9   
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A   
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B   
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C   
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D   
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E   
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 
	};

const unsigned char rsbox[256] = { 
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,  
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,  
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,  
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,  
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,  
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,  
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,  
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,  
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,  
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,  
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,  
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,  
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,  
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,  
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,  
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d 
	};

/*const unsigned char Rcon[255] = { 
	0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,    
	0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,    
	0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,    
	0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,    
	0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,    
	0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,    
	0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,    
	0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,    
	0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,    
	0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,    
	0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,    
	0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,    
	0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,    
	0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,    
	0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,    
	0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb
	};*/

#define S(x) sbox[x]
#define R(x) rsbox[x]

unsigned char TableMul2_8[256][256];

void MakeTableMul2_8(void)
{
	int a,b;
	unsigned char aa,bb,r,t;
	for (a = 0; a <256 ; a++)
	{
		for (b = a; b < 256 ; b++)
		{
			aa=a;
			bb=b;
			r=0;
			while (aa != 0)
			{
				if ((aa & 1) != 0) r=r^bb;
				t=bb & 0x80;
				bb=bb<<1;
				if (t != 0) bb=bb^0x1b;
				aa=aa>>1;
			}
			TableMul2_8[a][b]=TableMul2_8[b][a]=r;
		}
	}
}

#define Multiply(a,b) TableMul2_8[a][b]

/*unsigned char Inverse(unsigned char a)
{
	static unsigned char TableInverse[256]={0x00,0x01,0x8d,0xf6,0xcb,0x52,0x7b,0xd1,0xe8,0x4f,0x29,0xc0,0xb0,0xe1,0xe5,0xc7,0x74,0xb4,0xaa,0x4b,0x99,0x2b,0x60,0x5f,0x58,0x3f,0xfd,0xcc,0xff,0x40,0xee,0xb2,0x3a,0x6e,0x5a,0xf1,0x55,0x4d,0xa8,0xc9,0xc1,0x0a,0x98,0x15,0x30,0x44,0xa2,0xc2,0x2c,0x45,0x92,0x6c,0xf3,0x39,0x66,0x42,0xf2,0x35,0x20,0x6f,0x77,0xbb,0x59,0x19,0x1d,0xfe,0x37,0x67,0x2d,0x31,0xf5,0x69,0xa7,0x64,0xab,0x13,0x54,0x25,0xe9,0x09,0xed,0x5c,0x05,0xca,0x4c,0x24,0x87,0xbf,0x18,0x3e,0x22,0xf0,0x51,0xec,0x61,0x17,0x16,0x5e,0xaf,0xd3,0x49,0xa6,0x36,0x43,0xf4,0x47,0x91,0xdf,0x33,0x93,0x21,0x3b,0x79,0xb7,0x97,0x85,0x10,0xb5,0xba,0x3c,0xb6,0x70,0xd0,0x06,0xa1,0xfa,0x81,0x82,0x83,0x7e,0x7f,0x80,0x96,0x73,0xbe,0x56,0x9b,0x9e,0x95,0xd9,0xf7,0x02,0xb9,0xa4,0xde,0x6a,0x32,0x6d,0xd8,0x8a,0x84,0x72,0x2a,0x14,0x9f,0x88,0xf9,0xdc,0x89,0x9a,0xfb,0x7c,0x2e,0xc3,0x8f,0xb8,0x65,0x48,0x26,0xc8,0x12,0x4a,0xce,0xe7,0xd2,0x62,0x0c,0xe0,0x1f,0xef,0x11,0x75,0x78,0x71,0xa5,0x8e,0x76,0x3d,0xbd,0xbc,0x86,0x57,0x0b,0x28,0x2f,0xa3,0xda,0xd4,0xe4,0x0f,0xa9,0x27,0x53,0x04,0x1b,0xfc,0xac,0xe6,0x7a,0x07,0xae,0x63,0xc5,0xdb,0xe2,0xea,0x94,0x8b,0xc4,0xd5,0x9d,0xf8,0x90,0x6b,0xb1,0x0d,0xd6,0xeb,0xc6,0x0e,0xcf,0xad,0x08,0x4e,0xd7,0xe3,0x5d,0x50,0x1e,0xb3,0x5b,0x23,0x38,0x34,0x68,0x46,0x03,0x8c,0xdd,0x9c,0x7d,0xa0,0xcd,0x1a,0x41,0x1c};
	return TableInverse[a];
}
*//* Index variables 
 * x[0] = 1
 * x[1] = MC_3[7,7]
 * x[2] = MC_3[6,7]
 * x[3] = MC_3[5,7]
 * x[4] = MC_3[4,7]
 * x[5] = MC_3[3,7]
 * x[6] = MC_3[2,7]
 * x[7] = MC_3[1,7]
 * x[8] = MC_3[0,7]
 * x[9] = AC_3[7,7]
 * x[10] = MC_3[7,6]
 * x[11] = MC_3[6,6]
 * x[12] = MC_3[5,6]
 * x[13] = MC_3[4,6]
 * x[14] = MC_3[3,6]
 * x[15] = MC_3[2,6]
 * x[16] = MC_3[1,6]
 * x[17] = MC_3[0,6]
 * x[18] = AC_3[7,6]
 * x[19] = MC_3[7,5]
 * x[20] = MC_3[6,5]
 * x[21] = MC_3[5,5]
 * x[22] = MC_3[4,5]
 * x[23] = MC_3[3,5]
 * x[24] = MC_3[2,5]
 * x[25] = MC_3[1,5]
 * x[26] = MC_3[0,5]
 * x[27] = AC_3[7,5]
 * x[28] = MC_3[7,4]
 * x[29] = MC_3[6,4]
 * x[30] = MC_3[5,4]
 * x[31] = MC_3[4,4]
 * x[32] = MC_3[3,4]
 * x[33] = MC_3[2,4]
 * x[34] = MC_3[1,4]
 * x[35] = MC_3[0,4]
 * x[36] = AC_3[7,4]
 * x[37] = MC_3[7,3]
 * x[38] = MC_3[6,3]
 * x[39] = MC_3[5,3]
 * x[40] = MC_3[4,3]
 * x[41] = MC_3[3,3]
 * x[42] = MC_3[2,3]
 * x[43] = MC_3[1,3]
 * x[44] = MC_3[0,3]
 * x[45] = AC_3[7,3]
 * x[46] = MC_3[7,2]
 * x[47] = MC_3[6,2]
 * x[48] = MC_3[5,2]
 * x[49] = MC_3[4,2]
 * x[50] = MC_3[3,2]
 * x[51] = MC_3[2,2]
 * x[52] = MC_3[1,2]
 * x[53] = MC_3[0,2]
 * x[54] = AC_3[7,2]
 * x[55] = MC_3[7,1]
 * x[56] = MC_3[6,1]
 * x[57] = MC_3[5,1]
 * x[58] = MC_3[4,1]
 * x[59] = MC_3[3,1]
 * x[60] = MC_3[2,1]
 * x[61] = MC_3[1,1]
 * x[62] = MC_3[0,1]
 * x[63] = AC_3[7,1]
 * x[64] = MC_3[7,0]
 * x[65] = MC_3[6,0]
 * x[66] = MC_3[5,0]
 * x[67] = MC_3[4,0]
 * x[68] = MC_3[3,0]
 * x[69] = MC_3[2,0]
 * x[70] = MC_3[1,0]
 * x[71] = MC_3[0,0]
 * x[72] = AC_3[7,0]
 * x[73] = AC_3[6,7]
 * x[74] = AC_3[6,6]
 * x[75] = AC_3[6,5]
 * x[76] = AC_3[6,4]
 * x[77] = AC_3[6,3]
 * x[78] = AC_3[6,2]
 * x[79] = AC_3[6,1]
 * x[80] = AC_3[6,0]
 * x[81] = AC_3[5,7]
 * x[82] = AC_3[5,6]
 * x[83] = AC_3[5,5]
 * x[84] = AC_3[5,4]
 * x[85] = AC_3[5,3]
 * x[86] = AC_3[5,2]
 * x[87] = AC_3[5,1]
 * x[88] = AC_3[5,0]
 * x[89] = AC_3[4,7]
 * x[90] = AC_3[4,6]
 * x[91] = AC_3[4,5]
 * x[92] = AC_3[4,4]
 * x[93] = AC_3[4,3]
 * x[94] = AC_3[4,2]
 * x[95] = AC_3[4,1]
 * x[96] = AC_3[4,0]
 * x[97] = AC_3[3,7]
 * x[98] = AC_3[3,6]
 * x[99] = AC_3[3,5]
 * x[100] = AC_3[3,4]
 * x[101] = AC_3[3,3]
 * x[102] = AC_3[3,2]
 * x[103] = AC_3[3,1]
 * x[104] = AC_3[3,0]
 * x[105] = AC_3[2,7]
 * x[106] = AC_3[2,6]
 * x[107] = AC_3[2,5]
 * x[108] = AC_3[2,4]
 * x[109] = AC_3[2,3]
 * x[110] = AC_3[2,2]
 * x[111] = AC_3[2,1]
 * x[112] = AC_3[2,0]
 * x[113] = AC_3[1,7]
 * x[114] = AC_3[1,6]
 * x[115] = AC_3[1,5]
 * x[116] = AC_3[1,4]
 * x[117] = AC_3[1,3]
 * x[118] = AC_3[1,2]
 * x[119] = AC_3[1,1]
 * x[120] = AC_3[1,0]
 * x[121] = AC_3[0,7]
 * x[122] = AC_3[0,6]
 * x[123] = AC_3[0,5]
 * x[124] = AC_3[0,4]
 * x[125] = AC_3[0,3]
 * x[126] = AC_3[0,2]
 * x[127] = AC_3[0,1]
 * x[128] = AC_3[0,0]
 * x[129] = SB_3[7,6]
 * x[130] = SB_3[7,5]
 * x[131] = SB_3[7,4]
 * x[132] = SB_3[7,3]
 * x[133] = SB_3[7,2]
 * x[134] = SB_3[7,1]
 * x[135] = SB_3[7,0]
 * x[136] = SB_3[7,7]
 * x[137] = SB_3[6,5]
 * x[138] = SB_3[6,4]
 * x[139] = SB_3[6,3]
 * x[140] = SB_3[6,2]
 * x[141] = SB_3[6,1]
 * x[142] = SB_3[6,0]
 * x[143] = SB_3[6,7]
 * x[144] = SB_3[6,6]
 * x[145] = SB_3[5,4]
 * x[146] = SB_3[5,3]
 * x[147] = SB_3[5,2]
 * x[148] = SB_3[5,1]
 * x[149] = SB_3[5,0]
 * x[150] = SB_3[5,7]
 * x[151] = SB_3[5,6]
 * x[152] = SB_3[5,5]
 * x[153] = SB_3[4,3]
 * x[154] = SB_3[4,2]
 * x[155] = SB_3[4,1]
 * x[156] = SB_3[4,0]
 * x[157] = SB_3[4,7]
 * x[158] = SB_3[4,6]
 * x[159] = SB_3[4,5]
 * x[160] = SB_3[4,4]
 * x[161] = SB_3[3,2]
 * x[162] = SB_3[3,1]
 * x[163] = SB_3[3,0]
 * x[164] = SB_3[3,7]
 * x[165] = SB_3[3,6]
 * x[166] = SB_3[3,5]
 * x[167] = SB_3[3,4]
 * x[168] = SB_3[3,3]
 * x[169] = SB_3[2,1]
 * x[170] = SB_3[2,0]
 * x[171] = SB_3[2,7]
 * x[172] = SB_3[2,6]
 * x[173] = SB_3[2,5]
 * x[174] = SB_3[2,4]
 * x[175] = SB_3[2,3]
 * x[176] = SB_3[2,2]
 * x[177] = SB_3[1,0]
 * x[178] = SB_3[1,7]
 * x[179] = SB_3[1,6]
 * x[180] = SB_3[1,5]
 * x[181] = SB_3[1,4]
 * x[182] = SB_3[1,3]
 * x[183] = SB_3[1,2]
 * x[184] = SB_3[1,1]
 * x[185] = SB_3[0,7]
 * x[186] = SB_3[0,6]
 * x[187] = SB_3[0,5]
 * x[188] = SB_3[0,4]
 * x[189] = SB_3[0,3]
 * x[190] = SB_3[0,2]
 * x[191] = SB_3[0,1]
 * x[192] = SB_3[0,0]
 * x[193] = AC_2[7,7]
 * x[194] = AC_2[7,6]
 * x[195] = AC_2[7,5]
 * x[196] = AC_2[7,4]
 * x[197] = AC_2[7,3]
 * x[198] = AC_2[7,2]
 * x[199] = AC_2[7,1]
 * x[200] = AC_2[7,0]
 * x[201] = AC_2[6,7]
 * x[202] = AC_2[6,6]
 * x[203] = AC_2[6,5]
 * x[204] = AC_2[6,4]
 * x[205] = AC_2[6,3]
 * x[206] = AC_2[6,2]
 * x[207] = AC_2[6,1]
 * x[208] = AC_2[6,0]
 * x[209] = AC_2[5,7]
 * x[210] = AC_2[5,6]
 * x[211] = AC_2[5,5]
 * x[212] = AC_2[5,4]
 * x[213] = AC_2[5,3]
 * x[214] = AC_2[5,2]
 * x[215] = AC_2[5,1]
 * x[216] = AC_2[5,0]
 * x[217] = AC_2[4,7]
 * x[218] = AC_2[4,6]
 * x[219] = AC_2[4,5]
 * x[220] = AC_2[4,4]
 * x[221] = AC_2[4,3]
 * x[222] = AC_2[4,2]
 * x[223] = AC_2[4,1]
 * x[224] = AC_2[4,0]
 * x[225] = AC_2[3,7]
 * x[226] = AC_2[3,6]
 * x[227] = AC_2[3,5]
 * x[228] = AC_2[3,4]
 * x[229] = AC_2[3,3]
 * x[230] = AC_2[3,2]
 * x[231] = AC_2[3,1]
 * x[232] = AC_2[3,0]
 * x[233] = AC_2[2,7]
 * x[234] = AC_2[2,6]
 * x[235] = AC_2[2,5]
 * x[236] = AC_2[2,4]
 * x[237] = AC_2[2,3]
 * x[238] = AC_2[2,2]
 * x[239] = AC_2[2,1]
 * x[240] = AC_2[2,0]
 * x[241] = AC_2[1,7]
 * x[242] = AC_2[1,6]
 * x[243] = AC_2[1,5]
 * x[244] = AC_2[1,4]
 * x[245] = AC_2[1,3]
 * x[246] = AC_2[1,2]
 * x[247] = AC_2[1,1]
 * x[248] = AC_2[1,0]
 * x[249] = AC_2[0,7]
 * x[250] = AC_2[0,6]
 * x[251] = AC_2[0,5]
 * x[252] = AC_2[0,4]
 * x[253] = AC_2[0,3]
 * x[254] = AC_2[0,2]
 * x[255] = AC_2[0,1]
 * x[256] = AC_2[0,0]
 * x[257] = MC_2[7,7]
 * x[258] = MC_2[6,7]
 * x[259] = MC_2[5,7]
 * x[260] = MC_2[4,7]
 * x[261] = MC_2[3,7]
 * x[262] = MC_2[2,7]
 * x[263] = MC_2[1,7]
 * x[264] = MC_2[0,7]
 * x[265] = MC_2[7,6]
 * x[266] = MC_2[6,6]
 * x[267] = MC_2[5,6]
 * x[268] = MC_2[4,6]
 * x[269] = MC_2[3,6]
 * x[270] = MC_2[2,6]
 * x[271] = MC_2[1,6]
 * x[272] = MC_2[0,6]
 * x[273] = MC_2[7,5]
 * x[274] = MC_2[6,5]
 * x[275] = MC_2[5,5]
 * x[276] = MC_2[4,5]
 * x[277] = MC_2[3,5]
 * x[278] = MC_2[2,5]
 * x[279] = MC_2[1,5]
 * x[280] = MC_2[0,5]
 * x[281] = MC_2[7,4]
 * x[282] = MC_2[6,4]
 * x[283] = MC_2[5,4]
 * x[284] = MC_2[4,4]
 * x[285] = MC_2[3,4]
 * x[286] = MC_2[2,4]
 * x[287] = MC_2[1,4]
 * x[288] = MC_2[0,4]
 * x[289] = MC_2[7,3]
 * x[290] = MC_2[6,3]
 * x[291] = MC_2[5,3]
 * x[292] = MC_2[4,3]
 * x[293] = MC_2[3,3]
 * x[294] = MC_2[2,3]
 * x[295] = MC_2[1,3]
 * x[296] = MC_2[0,3]
 * x[297] = MC_2[7,2]
 * x[298] = MC_2[6,2]
 * x[299] = MC_2[5,2]
 * x[300] = MC_2[4,2]
 * x[301] = MC_2[3,2]
 * x[302] = MC_2[2,2]
 * x[303] = MC_2[1,2]
 * x[304] = MC_2[0,2]
 * x[305] = MC_2[7,1]
 * x[306] = MC_2[6,1]
 * x[307] = MC_2[5,1]
 * x[308] = MC_2[4,1]
 * x[309] = MC_2[3,1]
 * x[310] = MC_2[2,1]
 * x[311] = MC_2[1,1]
 * x[312] = MC_2[0,1]
 * x[313] = MC_2[7,0]
 * x[314] = MC_2[6,0]
 * x[315] = MC_2[5,0]
 * x[316] = MC_2[4,0]
 * x[317] = MC_2[3,0]
 * x[318] = MC_2[2,0]
 * x[319] = MC_2[1,0]
 * x[320] = MC_2[0,0]
 **/
void Attack(const unsigned char Known[71])
{
	const unsigned char x0=Known[0]; /* 1 */
	const unsigned char x97=Known[1]; /* AC_3[3,7] */
	const unsigned char x106=Known[2]; /* AC_3[2,6] */
	const unsigned char x115=Known[3]; /* AC_3[1,5] */
	const unsigned char x124=Known[4]; /* AC_3[0,4] */
	const unsigned char x45=Known[5]; /* AC_3[7,3] */
	const unsigned char x78=Known[6]; /* AC_3[6,2] */
	const unsigned char x87=Known[7]; /* AC_3[5,1] */
	const unsigned char x96=Known[8]; /* AC_3[4,0] */
	const unsigned char x113=Known[9]; /* AC_3[1,7] */
	const unsigned char x122=Known[10]; /* AC_3[0,6] */
	const unsigned char x27=Known[11]; /* AC_3[7,5] */
	const unsigned char x76=Known[12]; /* AC_3[6,4] */
	const unsigned char x85=Known[13]; /* AC_3[5,3] */
	const unsigned char x94=Known[14]; /* AC_3[4,2] */
	const unsigned char x103=Known[15]; /* AC_3[3,1] */
	const unsigned char x112=Known[16]; /* AC_3[2,0] */
	const unsigned char x121=Known[17]; /* AC_3[0,7] */
	const unsigned char x18=Known[18]; /* AC_3[7,6] */
	const unsigned char x75=Known[19]; /* AC_3[6,5] */
	const unsigned char x84=Known[20]; /* AC_3[5,4] */
	const unsigned char x93=Known[21]; /* AC_3[4,3] */
	const unsigned char x102=Known[22]; /* AC_3[3,2] */
	const unsigned char x111=Known[23]; /* AC_3[2,1] */
	const unsigned char x120=Known[24]; /* AC_3[1,0] */
	const unsigned char x136=Known[25]; /* SB_3[7,7] */
	const unsigned char x135=Known[26]; /* SB_3[7,0] */
	const unsigned char x143=Known[27]; /* SB_3[6,7] */
	const unsigned char x142=Known[28]; /* SB_3[6,0] */
	const unsigned char x150=Known[29]; /* SB_3[5,7] */
	const unsigned char x149=Known[30]; /* SB_3[5,0] */
	const unsigned char x157=Known[31]; /* SB_3[4,7] */
	const unsigned char x156=Known[32]; /* SB_3[4,0] */
	const unsigned char x164=Known[33]; /* SB_3[3,7] */
	const unsigned char x163=Known[34]; /* SB_3[3,0] */
	const unsigned char x171=Known[35]; /* SB_3[2,7] */
	const unsigned char x170=Known[36]; /* SB_3[2,0] */
	const unsigned char x178=Known[37]; /* SB_3[1,7] */
	const unsigned char x177=Known[38]; /* SB_3[1,0] */
	const unsigned char x185=Known[39]; /* SB_3[0,7] */
	const unsigned char x192=Known[40]; /* SB_3[0,0] */
	const unsigned char x265=Known[41]; /* MC_2[7,6] */
	const unsigned char x266=Known[42]; /* MC_2[6,6] */
	const unsigned char x267=Known[43]; /* MC_2[5,6] */
	const unsigned char x274=Known[44]; /* MC_2[6,5] */
	const unsigned char x280=Known[45]; /* MC_2[0,5] */
	const unsigned char x281=Known[46]; /* MC_2[7,4] */
	const unsigned char x287=Known[47]; /* MC_2[1,4] */
	const unsigned char x294=Known[48]; /* MC_2[2,3] */
	const unsigned char x296=Known[49]; /* MC_2[0,3] */
	const unsigned char x301=Known[50]; /* MC_2[3,2] */
	const unsigned char x303=Known[51]; /* MC_2[1,2] */
	const unsigned char x308=Known[52]; /* MC_2[4,1] */
	const unsigned char x309=Known[53]; /* MC_2[3,1] */
	const unsigned char x310=Known[54]; /* MC_2[2,1] */
	const unsigned char x257=Known[55]; /* MC_2[7,7] */
	const unsigned char x313=Known[56]; /* MC_2[7,0] */
	const unsigned char x258=Known[57]; /* MC_2[6,7] */
	const unsigned char x314=Known[58]; /* MC_2[6,0] */
	const unsigned char x259=Known[59]; /* MC_2[5,7] */
	const unsigned char x315=Known[60]; /* MC_2[5,0] */
	const unsigned char x260=Known[61]; /* MC_2[4,7] */
	const unsigned char x316=Known[62]; /* MC_2[4,0] */
	const unsigned char x261=Known[63]; /* MC_2[3,7] */
	const unsigned char x317=Known[64]; /* MC_2[3,0] */
	const unsigned char x262=Known[65]; /* MC_2[2,7] */
	const unsigned char x318=Known[66]; /* MC_2[2,0] */
	const unsigned char x263=Known[67]; /* MC_2[1,7] */
	const unsigned char x319=Known[68]; /* MC_2[1,0] */
	const unsigned char x264=Known[69]; /* MC_2[0,7] */
	const unsigned char x320=Known[70]; /* MC_2[0,0] */
	
	Chaine24_7 espace_24[2];
	POSITION24_7 *L_24;
	L_24=malloc(taille1_24*sizeof(POSITION24_7));
	espace_24[1]=malloc(taille2_24*sizeof(CHAINE24_7));
	
	uint8_t Alloue_24=1;
	unsigned long int pos_24;
	for (pos_24 = 0; pos_24 < taille1_24 ; pos_24++) L_24[pos_24].a=0;
	unsigned long int cpt_24=0;
	int i_12;
	for (i_12 = 0; i_12 < 0x100; i_12++)
	{
		const unsigned char x130=i_12;
		int i_13;
		for (i_13 = 0; i_13 < 0x100; i_13++)
		{
			const unsigned char x132=i_13;
			int i_14;
			for (i_14 = 0; i_14 < 0x100; i_14++)
			{
				const unsigned char x134=i_14;
				int i_15;
				for (i_15 = 0; i_15 < 0x100; i_15++)
				{
					const unsigned char x138=i_15;
					int i_16;
					for (i_16 = 0; i_16 < 0x100; i_16++)
					{
						const unsigned char x146=i_16;
						int i_17;
						for (i_17 = 0; i_17 < 0x100; i_17++)
						{
							const unsigned char x148=i_17;
							int i_18;
							for (i_18 = 0; i_18 < 0x100; i_18++)
							{
								const unsigned char x152=i_18;
								const unsigned char x154=R(Multiply(0x21,x122) ^ Multiply(0x78,x106) ^ Multiply(0xed,x18) ^ Multiply(0x1d,S(x178)) ^ Multiply(0x0a,S(x170)) ^ Multiply(0xec,S(x146)) ^ Multiply(0x93,S(x138)) ^ Multiply(0xae,S(x130)));
								int i_19;
								for (i_19 = 0; i_19 < 0x100; i_19++)
								{
									const unsigned char x158=i_19;
									int i_20;
									for (i_20 = 0; i_20 < 0x100; i_20++)
									{
										const unsigned char x160=i_20;
										const unsigned char x162=R(Multiply(0xc7,x122) ^ Multiply(0x0b,x106) ^ Multiply(0x59,x18) ^ Multiply(0x4f,S(x178)) ^ Multiply(0x3b,S(x170)) ^ Multiply(0x58,S(x146)) ^ Multiply(0x45,S(x138)) ^ Multiply(0xcc,S(x130)));
										int i_21;
										for (i_21 = 0; i_21 < 0x100; i_21++)
										{
											const unsigned char x166=i_21;
											int i_22;
											for (i_22 = 0; i_22 < 0x100; i_22++)
											{
												const unsigned char x168=i_22;
												int i_23;
												for (i_23 = 0; i_23 < 0x100; i_23++)
												{
													const unsigned char x172=i_23;
													const unsigned char x174=R(Multiply(0x46,x102) ^ Multiply(0x99,x94) ^ Multiply(0xf6,x78) ^ Multiply(0x6f,S(x166)) ^ Multiply(0xa6,S(x158)) ^ Multiply(0x17,S(x150)) ^ Multiply(0x44,S(x142)) ^ Multiply(0xe0,S(x134)));
													const unsigned char x176=R(Multiply(0xf7,x120) ^ Multiply(0xf6,x112) ^ Multiply(0xf6,x96) ^ Multiply(0xf3,S(x192)) ^ S(x168) ^ Multiply(0x07,S(x160)) ^ Multiply(0x04,S(x152)) ^ Multiply(0xf2,S(x136)));
													const unsigned char x180=R(Multiply(0x24,x124) ^ Multiply(0x3a,x84) ^ Multiply(0x60,x76) ^ Multiply(0xd9,S(x172)) ^ Multiply(0xe2,S(x164)) ^ Multiply(0xe9,S(x156)) ^ Multiply(0x23,S(x148)) ^ Multiply(0x72,S(x132)));
													const unsigned char x182=R(Multiply(0x8d,x102) ^ Multiply(0x29,x94) ^ Multiply(0xf6,x78) ^ Multiply(0xdf,S(x166)) ^ Multiply(0x50,S(x158)) ^ Multiply(0x2a,S(x150)) ^ Multiply(0x8e,S(x142)) ^ Multiply(0xdc,S(x134)));
													const unsigned char x184=R(Multiply(0xf2,x120) ^ Multiply(0xf4,x112) ^ Multiply(0xf5,x96) ^ Multiply(0xed,S(x192)) ^ Multiply(0x03,S(x168)) ^ Multiply(0x13,S(x160)) ^ Multiply(0x1b,S(x152)) ^ Multiply(0xe9,S(x136)));
													const unsigned char x186=R(Multiply(0xc7,x122) ^ Multiply(0xda,x106) ^ Multiply(0x88,x18) ^ Multiply(0x26,S(x178)) ^ Multiply(0xeb,S(x170)) ^ Multiply(0x89,S(x146)) ^ Multiply(0xfc,S(x138)) ^ Multiply(0x1d,S(x130)));
													const unsigned char x188=R(Multiply(0x0c,x124) ^ Multiply(0x60,x84) ^ Multiply(0x7e,x76) ^ Multiply(0x29,S(x172)) ^ Multiply(0x49,S(x164)) ^ Multiply(0x9a,S(x156)) ^ Multiply(0xb5,S(x148)) ^ Multiply(0x78,S(x132)));
													const unsigned char x190=R(Multiply(0x3d,x102) ^ Multiply(0x25,x94) ^ Multiply(0xa4,x78) ^ Multiply(0x76,S(x166)) ^ Multiply(0x32,S(x158)) ^ Multiply(0x5c,S(x150)) ^ Multiply(0xc8,S(x142)) ^ Multiply(0x0e,S(x134)));
													pos_24=(Multiply(0x8d,x162) ^ Multiply(0x12,x148) ^ Multiply(0xc3,x134));
													pos_24=(pos_24 << 8) ^ (Multiply(0x93,x172) ^ Multiply(0xfc,x158));
													pos_24=(pos_24 << 8) ^ (x180 ^ Multiply(0xe6,x166) ^ Multiply(0x4c,x152) ^ Multiply(0x94,x130));
													pos_24=(pos_24 << 8) ^ (Multiply(0x3d,x174) ^ Multiply(0xa4,x160) ^ Multiply(0x12,x138));
													pos_24=(pos_24 << 8) ^ (x182 ^ Multiply(0x13,x168) ^ Multiply(0xf9,x146) ^ Multiply(0x61,x132));
													pos_24=(pos_24 << 8) ^ (x184 ^ Multiply(0xda,x162) ^ Multiply(0xa0,x148) ^ Multiply(0x94,x134));
													pos_24=(pos_24 << 8) ^ (x186 ^ Multiply(0x32,x172) ^ Multiply(0x40,x158));
													pos_24=(pos_24 << 8) ^ (Multiply(0xbb,x166) ^ Multiply(0xcc,x152) ^ Multiply(0xa0,x130));
													pos_24=(pos_24 << 8) ^ (x188 ^ Multiply(0xd8,x174) ^ Multiply(0x67,x160) ^ Multiply(0x6b,x138));
													pos_24=(pos_24 << 8) ^ (Multiply(0xee,x168) ^ Multiply(0xf0,x146) ^ Multiply(0xf5,x132));
													pos_24=(pos_24 << 8) ^ (x190 ^ Multiply(0x53,x176) ^ Multiply(0xed,x154));
													pos_24=(pos_24 << 8) ^ (Multiply(0x5d,x162) ^ Multiply(0x44,x148) ^ Multiply(0xfd,x134));
													espace_24[1][cpt_24].d0=x130;
													espace_24[1][cpt_24].d1=x132;
													espace_24[1][cpt_24].d2=x134;
													espace_24[1][cpt_24].d3=x138;
													espace_24[1][cpt_24].d4=x146;
													espace_24[1][cpt_24].d5=x148;
													espace_24[1][cpt_24].d6=x172;
													espace_24[1][cpt_24].a=L_24[pos_24].a;
													espace_24[1][cpt_24].b=L_24[pos_24].b;
													L_24[pos_24].a=1;
													L_24[pos_24].b=cpt_24;
													cpt_24++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int i_0;
	for (i_0 = 0; i_0 < 0x100; i_0++)
	{
		const unsigned char x129=i_0;
		int i_1;
		for (i_1 = 0; i_1 < 0x100; i_1++)
		{
			const unsigned char x131=i_1;
			int i_2;
			for (i_2 = 0; i_2 < 0x100; i_2++)
			{
				const unsigned char x133=i_2;
				int i_3;
				for (i_3 = 0; i_3 < 0x100; i_3++)
				{
					const unsigned char x137=i_3;
					int i_4;
					for (i_4 = 0; i_4 < 0x100; i_4++)
					{
						const unsigned char x139=i_4;
						int i_5;
						for (i_5 = 0; i_5 < 0x100; i_5++)
						{
							const unsigned char x141=i_5;
							int i_6;
							for (i_6 = 0; i_6 < 0x100; i_6++)
							{
								const unsigned char x145=i_6;
								int i_7;
								for (i_7 = 0; i_7 < 0x100; i_7++)
								{
									const unsigned char x147=i_7;
									int i_8;
									for (i_8 = 0; i_8 < 0x100; i_8++)
									{
										const unsigned char x151=i_8;
										const unsigned char x153=R(Multiply(0xc7,x121) ^ Multiply(0x95,x113) ^ Multiply(0xc7,x97) ^ S(x185) ^ Multiply(0x52,S(x177)) ^ Multiply(0xf7,S(x145)) ^ Multiply(0x63,S(x137)) ^ Multiply(0x62,S(x129)));
										const unsigned char x155=R(Multiply(0xd1,x115) ^ Multiply(0xd1,x75) ^ Multiply(0xb9,x27) ^ Multiply(0xd3,S(x171)) ^ Multiply(0x6b,S(x163)) ^ Multiply(0xd2,S(x147)) ^ Multiply(0xd3,S(x139)) ^ Multiply(0x68,S(x131)));
										int i_9;
										for (i_9 = 0; i_9 < 0x100; i_9++)
										{
											const unsigned char x159=i_9;
											const unsigned char x161=R(Multiply(0xb3,x121) ^ Multiply(0xec,x113) ^ Multiply(0x6a,x97) ^ Multiply(0x71,S(x185)) ^ Multiply(0x67,S(x177)) ^ S(x145) ^ Multiply(0xd5,S(x137)) ^ Multiply(0x9c,S(x129)));
											int i_10;
											for (i_10 = 0; i_10 < 0x100; i_10++)
											{
												const unsigned char x165=i_10;
												int i_11;
												for (i_11 = 0; i_11 < 0x100; i_11++)
												{
													const unsigned char x167=i_11;
													const unsigned char x169=R(Multiply(0xf2,x121) ^ Multiply(0x26,x113) ^ Multiply(0xca,x97) ^ Multiply(0x48,S(x185)) ^ Multiply(0x7c,S(x177)) ^ Multiply(0xf6,S(x145)) ^ Multiply(0x78,S(x137)) ^ Multiply(0x99,S(x129)));
													const unsigned char x173=R(Multiply(0x9f,x93) ^ Multiply(0x78,x85) ^ Multiply(0x17,x45) ^ Multiply(0x38,S(x165)) ^ Multiply(0x6f,S(x157)) ^ Multiply(0x9e,S(x149)) ^ Multiply(0x2f,S(x141)) ^ Multiply(0xec,S(x133)));
													const unsigned char x175=R(Multiply(0x3c,x111) ^ Multiply(0xce,x103) ^ Multiply(0xea,x87) ^ Multiply(0x90,S(x167)) ^ Multiply(0x63,S(x159)) ^ Multiply(0x76,S(x151)) ^ Multiply(0x16,S(x143)) ^ Multiply(0xba,S(x135)));
													const unsigned char x179=R(Multiply(0x28,x115) ^ Multiply(0xf1,x75) ^ Multiply(0x68,x27) ^ Multiply(0xf3,S(x171)) ^ Multiply(0xa3,S(x163)) ^ Multiply(0xba,S(x147)) ^ Multiply(0x82,S(x139)) ^ Multiply(0xa1,S(x131)));
													const unsigned char x181=R(Multiply(0x1a,x93) ^ Multiply(0xd5,x85) ^ Multiply(0x88,x45) ^ Multiply(0x74,S(x165)) ^ Multiply(0xaa,S(x157)) ^ Multiply(0x1b,S(x149)) ^ Multiply(0x0a,S(x141)) ^ Multiply(0x07,S(x133)));
													const unsigned char x183=R(Multiply(0x51,x111) ^ Multiply(0x0c,x103) ^ Multiply(0x8b,x87) ^ Multiply(0x2b,S(x167)) ^ Multiply(0x77,S(x159)) ^ Multiply(0x46,S(x151)) ^ Multiply(0x33,S(x143)) ^ Multiply(0x49,S(x135)));
													const unsigned char x187=R(Multiply(0x08,x115) ^ Multiply(0x30,x75) ^ Multiply(0xb9,x27) ^ Multiply(0x32,S(x171)) ^ Multiply(0x23,S(x163)) ^ Multiply(0xd3,S(x147)) ^ Multiply(0x7a,S(x139)) ^ Multiply(0x21,S(x131)));
													const unsigned char x189=R(Multiply(0x32,x93) ^ Multiply(0xc2,x85) ^ Multiply(0x6f,x45) ^ Multiply(0xb1,S(x165)) ^ Multiply(0xad,S(x157)) ^ Multiply(0x33,S(x149)) ^ Multiply(0xdf,S(x141)) ^ Multiply(0x4b,S(x133)));
													const unsigned char x191=R(Multiply(0x9f,x111) ^ Multiply(0xd6,x103) ^ Multiply(0xe6,x87) ^ Multiply(0xc1,S(x167)) ^ Multiply(0x89,S(x159)) ^ Multiply(0xfc,S(x151)) ^ Multiply(0x77,S(x143)) ^ Multiply(0x28,S(x135)));
													pos_24=(Multiply(0x17,x310) ^ Multiply(0xa8,x309) ^ Multiply(0xd5,x308) ^ x169 ^ Multiply(0xaa,x155) ^ Multiply(0xd1,x141));
													pos_24=(pos_24 << 8) ^ (Multiply(0x45,x267) ^ Multiply(0x10,x266) ^ Multiply(0x29,x265) ^ x179 ^ Multiply(0xed,x165) ^ Multiply(0x97,x151) ^ Multiply(0xc9,x129));
													pos_24=(pos_24 << 8) ^ (Multiply(0xd5,x280) ^ Multiply(0x39,x274) ^ Multiply(0x28,x173) ^ Multiply(0x31,x159) ^ Multiply(0x8b,x137));
													pos_24=(pos_24 << 8) ^ (Multiply(0xe3,x287) ^ Multiply(0x26,x281) ^ x181 ^ Multiply(0xf8,x167) ^ Multiply(0xb1,x145) ^ Multiply(0x80,x131));
													pos_24=(pos_24 << 8) ^ (Multiply(0xf7,x296) ^ Multiply(0xbd,x294) ^ Multiply(0x68,x175) ^ Multiply(0x13,x153) ^ Multiply(0x3e,x139));
													pos_24=(pos_24 << 8) ^ (Multiply(0xa8,x310) ^ Multiply(0xbe,x309) ^ Multiply(0xc8,x308) ^ Multiply(0x8d,x155) ^ Multiply(0x28,x141));
													pos_24=(pos_24 << 8) ^ (Multiply(0xcc,x267) ^ Multiply(0x51,x266) ^ Multiply(0x3b,x265) ^ Multiply(0x22,x165) ^ Multiply(0xbd,x151) ^ Multiply(0x8e,x129));
													pos_24=(pos_24 << 8) ^ (Multiply(0xa7,x280) ^ Multiply(0xf4,x274) ^ x187 ^ Multiply(0xea,x173) ^ Multiply(0x90,x159) ^ Multiply(0x9d,x137));
													pos_24=(pos_24 << 8) ^ (Multiply(0x65,x287) ^ Multiply(0x33,x281) ^ Multiply(0xc4,x167) ^ Multiply(0xa9,x145) ^ Multiply(0x8a,x131));
													pos_24=(pos_24 << 8) ^ (Multiply(0xec,x296) ^ Multiply(0xd9,x294) ^ x189 ^ Multiply(0x83,x175) ^ Multiply(0xdb,x153) ^ Multiply(0xa1,x139));
													pos_24=(pos_24 << 8) ^ (Multiply(0x06,x303) ^ Multiply(0xb1,x301) ^ Multiply(0x90,x183) ^ Multiply(0xce,x161) ^ Multiply(0x55,x147) ^ Multiply(0xd9,x133));
													pos_24=(pos_24 << 8) ^ (Multiply(0xd5,x310) ^ Multiply(0xc8,x309) ^ Multiply(0x10,x308) ^ x191 ^ Multiply(0x09,x155) ^ Multiply(0x1e,x141));
													POSITION24_7 tmp2_24=L_24[pos_24];
													while (tmp2_24.a) /* Entrée : 12*/
													{
														const unsigned char x130=espace_24[1][tmp2_24.b].d0;
														const unsigned char x132=espace_24[1][tmp2_24.b].d1;
														const unsigned char x134=espace_24[1][tmp2_24.b].d2;
														const unsigned char x138=espace_24[1][tmp2_24.b].d3;
														const unsigned char x146=espace_24[1][tmp2_24.b].d4;
														const unsigned char x148=espace_24[1][tmp2_24.b].d5;
														const unsigned char x172=espace_24[1][tmp2_24.b].d6;
														tmp2_24.a=espace_24[1][tmp2_24.b].a;
														tmp2_24.b=espace_24[1][tmp2_24.b].b;
													/* --- 24 */
														const unsigned char x188=R(Multiply(0x0c,x124) ^ Multiply(0x60,x84) ^ Multiply(0x7e,x76) ^ Multiply(0x29,S(x172)) ^ Multiply(0x49,S(x164)) ^ Multiply(0x9a,S(x156)) ^ Multiply(0xb5,S(x148)) ^ Multiply(0x78,S(x132)));
														const unsigned char x186=Multiply(0xe6,x267) ^ Multiply(0x39,x266) ^ Multiply(0x54,x265) ^ Multiply(0x8b,x179) ^ Multiply(0xb1,x172) ^ Multiply(0x81,x165) ^ Multiply(0x24,x151) ^ Multiply(0xe7,x129);
														if ((S(x186))==(Multiply(0xc7,x122) ^ Multiply(0xda,x106) ^ Multiply(0x88,x18) ^ Multiply(0x26,S(x178)) ^ Multiply(0xeb,S(x170)) ^ Multiply(0x89,S(x146)) ^ Multiply(0xfc,S(x138)) ^ Multiply(0x1d,S(x130))))
														{
															const unsigned char x184=Multiply(0xd6,x310) ^ Multiply(0x7d,x309) ^ Multiply(0x7b,x308) ^ Multiply(0xaf,x169) ^ Multiply(0x0b,x155) ^ Multiply(0xfb,x148) ^ Multiply(0x11,x141) ^ Multiply(0xf6,x134);
															const unsigned char x182=Multiply(0x4d,x296) ^ Multiply(0xd6,x294) ^ Multiply(0xd9,x189) ^ Multiply(0xfb,x175) ^ Multiply(0xd1,x153) ^ Multiply(0xa7,x146) ^ Multiply(0x7a,x139) ^ Multiply(0xaf,x132);
															const unsigned char x180=R(Multiply(0x24,x124) ^ Multiply(0x3a,x84) ^ Multiply(0x60,x76) ^ Multiply(0xd9,S(x172)) ^ Multiply(0xe2,S(x164)) ^ Multiply(0xe9,S(x156)) ^ Multiply(0x23,S(x148)) ^ Multiply(0x72,S(x132)));
															const unsigned char x174=Multiply(0x5c,x287) ^ Multiply(0xfb,x281) ^ Multiply(0x40,x188) ^ Multiply(0x1f,x181) ^ Multiply(0xbb,x167) ^ Multiply(0xc3,x145) ^ Multiply(0x50,x138) ^ Multiply(0xe2,x131);
															const unsigned char x190=R(Multiply(0xf0,x102) ^ Multiply(0xf5,x94) ^ Multiply(0x02,x78) ^ Multiply(0x11,S(x182)) ^ Multiply(0xe0,S(x174)) ^ Multiply(0xf4,S(x150)) ^ Multiply(0xed,S(x142)) ^ Multiply(0xe0,S(x134)));
															const unsigned char x166=R(Multiply(0xf2,x102) ^ Multiply(0xf4,x94) ^ Multiply(0xf5,x78) ^ Multiply(0xe9,S(x182)) ^ Multiply(0xed,S(x174)) ^ Multiply(0x03,S(x150)) ^ Multiply(0x13,S(x142)) ^ Multiply(0x1b,S(x134)));
															if ((Multiply(0xe2,x166))==(Multiply(0x4a,x280) ^ Multiply(0x78,x274) ^ x187 ^ Multiply(0xa2,x180) ^ Multiply(0x0a,x173) ^ Multiply(0x7b,x159) ^ Multiply(0x2d,x137) ^ Multiply(0xfa,x130)))
															{
																const unsigned char x162=R(Multiply(0xc7,x122) ^ Multiply(0x0b,x106) ^ Multiply(0x59,x18) ^ Multiply(0x4f,S(x178)) ^ Multiply(0x3b,S(x170)) ^ Multiply(0x58,S(x146)) ^ Multiply(0x45,S(x138)) ^ Multiply(0xcc,S(x130)));
																if ((Multiply(0x8d,x162))==(Multiply(0x17,x310) ^ Multiply(0xa8,x309) ^ Multiply(0xd5,x308) ^ x169 ^ Multiply(0xaa,x155) ^ Multiply(0x12,x148) ^ Multiply(0xd1,x141) ^ Multiply(0xc3,x134)))
																{
																	const unsigned char x160=Multiply(0x21,x287) ^ Multiply(0x5f,x281) ^ Multiply(0x8f,x181) ^ Multiply(0xe9,x174) ^ Multiply(0x97,x167) ^ Multiply(0xac,x145) ^ Multiply(0x2d,x138) ^ Multiply(0x5b,x131);
																	const unsigned char x158=R(Multiply(0x6d,x102) ^ Multiply(0x3a,x94) ^ Multiply(0x23,x78) ^ Multiply(0x65,S(x174)) ^ Multiply(0x19,S(x166)) ^ Multiply(0x2a,S(x150)) ^ Multiply(0xa7,S(x142)) ^ Multiply(0x6c,S(x134)));
																	if ((Multiply(0xfc,x158))==(Multiply(0x45,x267) ^ Multiply(0x10,x266) ^ Multiply(0x29,x265) ^ x179 ^ Multiply(0x93,x172) ^ Multiply(0xed,x165) ^ Multiply(0x97,x151) ^ Multiply(0xc9,x129)))
																	{
																		const unsigned char x154=R(Multiply(0x21,x122) ^ Multiply(0x78,x106) ^ Multiply(0xed,x18) ^ Multiply(0x1d,S(x178)) ^ Multiply(0x0a,S(x170)) ^ Multiply(0xec,S(x146)) ^ Multiply(0x93,S(x138)) ^ Multiply(0xae,S(x130)));
																		const unsigned char x152=Multiply(0x57,x280) ^ Multiply(0x9b,x274) ^ Multiply(0x54,x180) ^ Multiply(0xf8,x173) ^ Multiply(0xf2,x166) ^ Multiply(0x0d,x159) ^ Multiply(0xc9,x137) ^ Multiply(0xdf,x130);
																		const unsigned char x168=Multiply(0x72,x296) ^ Multiply(0xd7,x294) ^ Multiply(0x4b,x182) ^ Multiply(0x90,x175) ^ x153 ^ Multiply(0xbd,x146) ^ Multiply(0xb0,x139) ^ Multiply(0xb5,x132);
																		if ((Multiply(0x03,S(x168)))==(Multiply(0xf2,x120) ^ Multiply(0xf4,x112) ^ Multiply(0xf5,x96) ^ Multiply(0xed,S(x192)) ^ S(x184) ^ Multiply(0x13,S(x160)) ^ Multiply(0x1b,S(x152)) ^ Multiply(0xe9,S(x136))))
																		{
																			const unsigned char x176=R(Multiply(0xf7,x120) ^ Multiply(0xf6,x112) ^ Multiply(0xf6,x96) ^ Multiply(0xf3,S(x192)) ^ S(x168) ^ Multiply(0x07,S(x160)) ^ Multiply(0x04,S(x152)) ^ Multiply(0xf2,S(x136)));
																			if ((Multiply(0x53,x176))==(Multiply(0x06,x303) ^ Multiply(0xb1,x301) ^ x190 ^ Multiply(0x90,x183) ^ Multiply(0xce,x161) ^ Multiply(0xed,x154) ^ Multiply(0x55,x147) ^ Multiply(0xd9,x133)))
																			{
																				/* --- 24 */
																				const unsigned char x140=R(Multiply(0x42,x124) ^ Multiply(0x24,x84) ^ Multiply(0x0c,x76) ^ Multiply(0x96,S(x172)) ^ Multiply(0xb3,S(x164)) ^ Multiply(0x91,S(x156)) ^ Multiply(0xaa,S(x148)) ^ Multiply(0xa1,S(x132)));
																				if ((Multiply(0x1b,x140))==(Multiply(0xd2,x303) ^ Multiply(0x2e,x301) ^ x183 ^ Multiply(0x21,x176) ^ Multiply(0x44,x161) ^ Multiply(0xab,x154) ^ Multiply(0x9e,x147) ^ Multiply(0x1e,x133)))
																				{
																					const unsigned char x144=R(Multiply(0xf0,x120) ^ Multiply(0xf5,x112) ^ Multiply(0x02,x96) ^ Multiply(0xe0,S(x192)) ^ Multiply(0xf4,S(x168)) ^ Multiply(0xed,S(x160)) ^ Multiply(0xe0,S(x152)) ^ Multiply(0x11,S(x136)));
																					if ((Multiply(0x1c,x144))==(Multiply(0xc2,x267) ^ Multiply(0x40,x266) ^ Multiply(0xf4,x265) ^ x172 ^ Multiply(0x76,x165) ^ Multiply(0x46,x158) ^ Multiply(0x8e,x151) ^ Multiply(0x78,x129)))
																					{
																						const unsigned char x1=S(x129);
																						const unsigned char x2=S(x137);
																						const unsigned char x3=S(x145);
																						const unsigned char x4=Multiply(0xc7,x121) ^ Multiply(0x95,x113) ^ Multiply(0xc7,x97) ^ Multiply(0xf7,x3) ^ Multiply(0x63,x2) ^ Multiply(0x62,x1) ^ S(x185) ^ Multiply(0x52,S(x177));
																						const unsigned char x5=Multiply(0xb3,x121) ^ Multiply(0xec,x113) ^ Multiply(0x6a,x97) ^ x3 ^ Multiply(0xd5,x2) ^ Multiply(0x9c,x1) ^ Multiply(0x71,S(x185)) ^ Multiply(0x67,S(x177));
																						const unsigned char x6=Multiply(0xf2,x121) ^ Multiply(0x26,x113) ^ Multiply(0xca,x97) ^ Multiply(0xf6,x3) ^ Multiply(0x78,x2) ^ Multiply(0x99,x1) ^ Multiply(0x48,S(x185)) ^ Multiply(0x7c,S(x177));
																						const unsigned char x7=Multiply(0xc0,x113) ^ Multiply(0xdb,x97) ^ Multiply(0xac,x6) ^ Multiply(0xf6,x5) ^ Multiply(0x80,x4) ^ Multiply(0x9b,x3) ^ Multiply(0x1a,x2) ^ Multiply(0x77,x1);
																						const unsigned char x8=Multiply(0xf6,x97) ^ Multiply(0x03,x7) ^ Multiply(0xf4,x6) ^ Multiply(0xf7,x5) ^ Multiply(0xf7,x4) ^ x3 ^ Multiply(0xf5,x2) ^ Multiply(0x03,x1);
																						const unsigned char x9=Multiply(0xfe,x121) ^ Multiply(0x4d,x113) ^ Multiply(0x8e,x97) ^ Multiply(0xf7,x3) ^ Multiply(0xf5,x2) ^ Multiply(0x2c,x1) ^ Multiply(0x94,S(x185)) ^ Multiply(0xfe,S(x177));
																						const unsigned char x10=S(x130);
																						const unsigned char x11=S(x138);
																						const unsigned char x12=S(x146);
																						const unsigned char x13=Multiply(0x21,x122) ^ Multiply(0x78,x106) ^ Multiply(0xed,x18) ^ Multiply(0xec,x12) ^ Multiply(0x93,x11) ^ Multiply(0xae,x10) ^ Multiply(0x1d,S(x178)) ^ Multiply(0x0a,S(x170));
																						const unsigned char x14=Multiply(0xc7,x122) ^ Multiply(0x0b,x106) ^ Multiply(0x59,x18) ^ Multiply(0x58,x12) ^ Multiply(0x45,x11) ^ Multiply(0xcc,x10) ^ Multiply(0x4f,S(x178)) ^ Multiply(0x3b,S(x170));
																						const unsigned char x15=Multiply(0x5f,x122) ^ Multiply(0xbe,x106) ^ Multiply(0x67,x18) ^ Multiply(0xe0,x14) ^ Multiply(0x48,x13) ^ Multiply(0xcf,x12) ^ Multiply(0x66,x11) ^ Multiply(0x91,x10);
																						const unsigned char x16=Multiply(0x02,x106) ^ Multiply(0x05,x18) ^ Multiply(0x10,x15) ^ Multiply(0x15,x14) ^ Multiply(0x09,x13) ^ Multiply(0x19,x12) ^ Multiply(0x11,x11) ^ Multiply(0x0c,x10);
																						const unsigned char x17=Multiply(0xc7,x122) ^ Multiply(0xda,x106) ^ Multiply(0x88,x18) ^ Multiply(0x89,x12) ^ Multiply(0xfc,x11) ^ Multiply(0x1d,x10) ^ Multiply(0x26,S(x178)) ^ Multiply(0xeb,S(x170));
																						const unsigned char x19=S(x131);
																						const unsigned char x20=S(x139);
																						const unsigned char x21=S(x147);
																						const unsigned char x22=Multiply(0xd1,x115) ^ Multiply(0xd1,x75) ^ Multiply(0xb9,x27) ^ Multiply(0xd2,x21) ^ Multiply(0xd3,x20) ^ Multiply(0x68,x19) ^ Multiply(0xd3,S(x171)) ^ Multiply(0x6b,S(x163));
																						const unsigned char x23=S(x163);
																						const unsigned char x24=Multiply(0xc7,x115) ^ Multiply(0xc7,x75) ^ Multiply(0x95,x27) ^ Multiply(0xf7,x23) ^ Multiply(0x63,x22) ^ Multiply(0x62,x21) ^ x20 ^ Multiply(0x52,x19);
																						const unsigned char x25=Multiply(0x28,x115) ^ Multiply(0xf1,x75) ^ Multiply(0x68,x27) ^ Multiply(0xba,x21) ^ Multiply(0x82,x20) ^ Multiply(0xa1,x19) ^ Multiply(0xf3,S(x171)) ^ Multiply(0xa3,S(x163));
																						const unsigned char x26=Multiply(0x08,x115) ^ Multiply(0x30,x75) ^ Multiply(0xb9,x27) ^ Multiply(0xd3,x21) ^ Multiply(0x7a,x20) ^ Multiply(0x21,x19) ^ Multiply(0x32,S(x171)) ^ Multiply(0x23,S(x163));
																						const unsigned char x28=S(x132);
																						const unsigned char x29=S(x140);
																						const unsigned char x30=S(x148);
																						const unsigned char x31=S(x156);
																						const unsigned char x32=S(x164);
																						const unsigned char x33=Multiply(0x45,x124) ^ Multiply(0x0d,x84) ^ Multiply(0x6a,x76) ^ Multiply(0xd8,x30) ^ Multiply(0x84,x29) ^ Multiply(0x03,x28) ^ Multiply(0x88,S(x164)) ^ Multiply(0xb0,S(x156));
																						const unsigned char x34=Multiply(0x48,x124) ^ Multiply(0x38,x84) ^ Multiply(0xd9,x76) ^ Multiply(0x91,x30) ^ Multiply(0xaa,x29) ^ Multiply(0x02,x28) ^ Multiply(0x93,S(x164)) ^ Multiply(0x4b,S(x156));
																						const unsigned char x35=Multiply(0x2f,x124) ^ Multiply(0xbe,x84) ^ Multiply(0x86,x76) ^ Multiply(0xa9,x30) ^ Multiply(0xe3,x29) ^ Multiply(0x03,x28) ^ Multiply(0x5d,S(x164)) ^ Multiply(0x2c,S(x156));
																						const unsigned char x36=Multiply(0x89,x124) ^ Multiply(0x1b,x84) ^ Multiply(0xd4,x76) ^ Multiply(0xa9,x30) ^ Multiply(0x19,x29) ^ Multiply(0x0e,x28) ^ Multiply(0x07,S(x164)) ^ Multiply(0x70,S(x156));
																						const unsigned char x37=S(x133);
																						const unsigned char x38=S(x141);
																						const unsigned char x39=S(x149);
																						const unsigned char x40=S(x157);
																						const unsigned char x41=S(x165);
																						const unsigned char x42=Multiply(0x9f,x93) ^ Multiply(0x78,x85) ^ Multiply(0x17,x45) ^ Multiply(0x38,x41) ^ Multiply(0x2f,x38) ^ Multiply(0xec,x37) ^ Multiply(0x6f,S(x157)) ^ Multiply(0x9e,S(x149));
																						const unsigned char x43=Multiply(0x1a,x93) ^ Multiply(0xd5,x85) ^ Multiply(0x88,x45) ^ Multiply(0x74,x41) ^ Multiply(0x0a,x38) ^ Multiply(0x07,x37) ^ Multiply(0xaa,S(x157)) ^ Multiply(0x1b,S(x149));
																						const unsigned char x44=Multiply(0x32,x93) ^ Multiply(0xc2,x85) ^ Multiply(0x6f,x45) ^ Multiply(0xb1,x41) ^ Multiply(0xdf,x38) ^ Multiply(0x4b,x37) ^ Multiply(0xad,S(x157)) ^ Multiply(0x33,S(x149));
																						const unsigned char x46=S(x134);
																						const unsigned char x47=S(x142);
																						const unsigned char x48=S(x150);
																						const unsigned char x49=S(x158);
																						const unsigned char x50=S(x166);
																						const unsigned char x51=Multiply(0x46,x102) ^ Multiply(0x99,x94) ^ Multiply(0xf6,x78) ^ Multiply(0x6f,x50) ^ Multiply(0xa6,x49) ^ Multiply(0xe0,x46) ^ Multiply(0x17,S(x150)) ^ Multiply(0x44,S(x142));
																						const unsigned char x52=Multiply(0x8d,x102) ^ Multiply(0x29,x94) ^ Multiply(0xf6,x78) ^ Multiply(0xdf,x50) ^ Multiply(0x50,x49) ^ Multiply(0xdc,x46) ^ Multiply(0x2a,S(x150)) ^ Multiply(0x8e,S(x142));
																						const unsigned char x53=Multiply(0x3d,x102) ^ Multiply(0x25,x94) ^ Multiply(0xa4,x78) ^ Multiply(0x76,x50) ^ Multiply(0x32,x49) ^ Multiply(0x0e,x46) ^ Multiply(0x5c,S(x150)) ^ Multiply(0xc8,S(x142));
																						const unsigned char x54=Multiply(0xf5,x102) ^ Multiply(0x63,x94) ^ Multiply(0xa7,x78) ^ Multiply(0x34,x50) ^ Multiply(0x39,x49) ^ Multiply(0xcc,x46) ^ Multiply(0x9f,S(x150)) ^ Multiply(0x0e,S(x142));
																						const unsigned char x55=S(x135);
																						const unsigned char x56=S(x143);
																						const unsigned char x57=S(x151);
																						const unsigned char x58=S(x159);
																						const unsigned char x59=S(x167);
																						const unsigned char x60=Multiply(0x3c,x111) ^ Multiply(0xce,x103) ^ Multiply(0xea,x87) ^ Multiply(0x90,x59) ^ Multiply(0x63,x58) ^ Multiply(0x76,x57) ^ Multiply(0x16,S(x143)) ^ Multiply(0xba,S(x135));
																						const unsigned char x61=Multiply(0x51,x111) ^ Multiply(0x0c,x103) ^ Multiply(0x8b,x87) ^ Multiply(0x2b,x59) ^ Multiply(0x77,x58) ^ Multiply(0x46,x57) ^ Multiply(0x33,S(x143)) ^ Multiply(0x49,S(x135));
																						const unsigned char x62=Multiply(0x9f,x111) ^ Multiply(0xd6,x103) ^ Multiply(0xe6,x87) ^ Multiply(0xc1,x59) ^ Multiply(0x89,x58) ^ Multiply(0xfc,x57) ^ Multiply(0x77,S(x143)) ^ Multiply(0x28,S(x135));
																						const unsigned char x63=Multiply(0x26,x111) ^ Multiply(0xb6,x103) ^ Multiply(0xd4,x87) ^ Multiply(0x97,x59) ^ Multiply(0x04,x58) ^ Multiply(0xef,x57) ^ Multiply(0xe4,S(x143)) ^ Multiply(0x57,S(x135));
																						const unsigned char x64=S(x136);
																						const unsigned char x65=S(x144);
																						const unsigned char x66=S(x152);
																						const unsigned char x67=S(x160);
																						const unsigned char x68=Multiply(0xba,x120) ^ Multiply(0x69,x112) ^ Multiply(0xd0,x96) ^ Multiply(0xde,x67) ^ Multiply(0x60,x66) ^ Multiply(0x68,x65) ^ Multiply(0x60,S(x192)) ^ Multiply(0xb2,S(x136));
																						const unsigned char x69=Multiply(0x4d,x120) ^ Multiply(0x9f,x112) ^ Multiply(0x26,x96) ^ Multiply(0xd9,x67) ^ Multiply(0x64,x66) ^ Multiply(0x68,x65) ^ Multiply(0x93,S(x192)) ^ Multiply(0x40,S(x136));
																						const unsigned char x70=Multiply(0x27,x120) ^ Multiply(0x4f,x112) ^ Multiply(0x9e,x96) ^ Multiply(0x6a,x67) ^ Multiply(0xbb,x66) ^ Multiply(0xb8,x65) ^ Multiply(0x4d,S(x192)) ^ Multiply(0x24,S(x136));
																						const unsigned char x71=Multiply(0x52,x96) ^ Multiply(0xf6,x70) ^ x69 ^ Multiply(0xa5,x68) ^ Multiply(0xa4,x67) ^ Multiply(0xa4,x66) ^ Multiply(0xf6,x65) ^ Multiply(0x53,x64);
																						const unsigned char x72=Multiply(0x22,x120) ^ Multiply(0x4d,x112) ^ Multiply(0x9c,x96) ^ Multiply(0x7f,x67) ^ Multiply(0xa3,x66) ^ Multiply(0xbc,x65) ^ Multiply(0x54,S(x192)) ^ Multiply(0x39,S(x136));
																						const unsigned char x73=Multiply(0x2f,x121) ^ Multiply(0x66,x113) ^ Multiply(0x87,x97) ^ x3 ^ Multiply(0x11,x2) ^ Multiply(0x87,x1) ^ Multiply(0xe6,S(x185)) ^ Multiply(0x3b,S(x177));
																						const unsigned char x74=Multiply(0xa5,x122) ^ Multiply(0xeb,x106) ^ Multiply(0x1c,x18) ^ Multiply(0x1e,x12) ^ Multiply(0x3b,x11) ^ Multiply(0x4a,x10) ^ Multiply(0xd6,S(x178)) ^ Multiply(0x4c,S(x170));
																						const unsigned char x77=Multiply(0xeb,x93) ^ Multiply(0xa7,x85) ^ Multiply(0xec,x45) ^ Multiply(0xd8,x41) ^ Multiply(0xc3,x38) ^ Multiply(0xb2,x37) ^ Multiply(0xbf,S(x157)) ^ Multiply(0xee,S(x149));
																						const unsigned char x79=Multiply(0x29,x111) ^ Multiply(0x8a,x103) ^ Multiply(0x44,x87) ^ Multiply(0x11,x59) ^ Multiply(0xb6,x58) ^ Multiply(0xae,x57) ^ Multiply(0x19,S(x143)) ^ Multiply(0x21,S(x135));
																						const unsigned char x80=Multiply(0x2b,x120) ^ Multiply(0x49,x112) ^ Multiply(0x9b,x96) ^ Multiply(0x5f,x67) ^ Multiply(0x92,x66) ^ Multiply(0xbf,x65) ^ Multiply(0x65,S(x192)) ^ Multiply(0x04,S(x136));
																						const unsigned char x81=Multiply(0x27,x121) ^ Multiply(0xdd,x113) ^ Multiply(0xff,x97) ^ Multiply(0xf5,x3) ^ Multiply(0x14,x2) ^ Multiply(0x5c,x1) ^ Multiply(0x75,S(x185)) ^ Multiply(0xc4,S(x177));
																						const unsigned char x82=Multiply(0x20,x122) ^ Multiply(0x11,x106) ^ Multiply(0x85,x18) ^ Multiply(0x81,x12) ^ Multiply(0x41,x11) ^ Multiply(0xc1,x10) ^ Multiply(0xa6,S(x178)) ^ Multiply(0x63,S(x170));
																						const unsigned char x83=Multiply(0xa9,x115) ^ Multiply(0xd9,x75) ^ Multiply(0x03,x27) ^ Multiply(0x0f,x21) ^ Multiply(0x42,x20) ^ Multiply(0x97,x19) ^ Multiply(0xd6,S(x171)) ^ Multiply(0x9a,S(x163));
																						const unsigned char x86=Multiply(0xb1,x102) ^ Multiply(0xa9,x94) ^ Multiply(0xa4,x78) ^ Multiply(0xf9,x50) ^ Multiply(0x35,x49) ^ Multiply(0x81,x46) ^ Multiply(0xd2,S(x150)) ^ Multiply(0x43,S(x142));
																						const unsigned char x88=Multiply(0x08,x120) ^ Multiply(0x04,x112) ^ Multiply(0x07,x96) ^ Multiply(0x25,x67) ^ Multiply(0x34,x66) ^ Multiply(0x07,x65) ^ Multiply(0x33,S(x192)) ^ Multiply(0x3b,S(x136));
																						const unsigned char x89=Multiply(0xb6,x121) ^ Multiply(0x3d,x113) ^ Multiply(0x57,x97) ^ Multiply(0xf3,x3) ^ Multiply(0x5b,x2) ^ Multiply(0xf2,x1) ^ Multiply(0x38,S(x185)) ^ Multiply(0x1e,S(x177));
																						const unsigned char x90=Multiply(0xd7,x122) ^ Multiply(0x5e,x106) ^ Multiply(0xcb,x18) ^ Multiply(0xc9,x12) ^ Multiply(0xdf,x11) ^ Multiply(0x78,x10) ^ Multiply(0x71,S(x178)) ^ Multiply(0xda,S(x170));
																						const unsigned char x91=Multiply(0xe9,x115) ^ Multiply(0x41,x75) ^ Multiply(0xba,x27) ^ Multiply(0xda,x21) ^ Multiply(0xaa,x20) ^ Multiply(0x89,x19) ^ Multiply(0x4c,S(x171)) ^ Multiply(0x80,S(x163));
																						const unsigned char x92=x124 ^ x84 ^ x76 ^ Multiply(0x04,x30) ^ Multiply(0x06,x29) ^ Multiply(0x02,x28) ^ Multiply(0x05,S(x164)) ^ Multiply(0x05,S(x156));
																						const unsigned char x95=Multiply(0xea,x111) ^ Multiply(0x6c,x103) ^ Multiply(0xba,x87) ^ Multiply(0x74,x59) ^ Multiply(0xf4,x58) ^ Multiply(0x5c,x57) ^ Multiply(0xa8,S(x143)) ^ Multiply(0x33,S(x135));
																						const unsigned char x98=Multiply(0x85,x122) ^ Multiply(0x93,x106) ^ Multiply(0xf0,x18) ^ Multiply(0xf0,x12) ^ Multiply(0xac,x11) ^ Multiply(0xe6,x10) ^ Multiply(0xcb,S(x178)) ^ Multiply(0x43,S(x170));
																						const unsigned char x99=Multiply(0x29,x115) ^ Multiply(0xf1,x75) ^ Multiply(0x6a,x27) ^ Multiply(0xb6,x21) ^ Multiply(0x8b,x20) ^ Multiply(0xa5,x19) ^ Multiply(0xfe,S(x171)) ^ Multiply(0xa8,S(x163));
																						const unsigned char x100=Multiply(0xc2,x124) ^ Multiply(0x22,x84) ^ Multiply(0x0c,x76) ^ Multiply(0x3e,x30) ^ Multiply(0xbf,x29) ^ Multiply(0x03,x28) ^ Multiply(0x99,S(x164)) ^ Multiply(0x37,S(x156));
																						const unsigned char x101=Multiply(0xd4,x93) ^ Multiply(0x82,x85) ^ Multiply(0x4a,x45) ^ Multiply(0xdd,x41) ^ Multiply(0x91,x38) ^ Multiply(0x71,x37) ^ Multiply(0xcc,S(x157)) ^ Multiply(0xd6,S(x149));
																						const unsigned char x104=Multiply(0x2c,x120) ^ Multiply(0x4a,x112) ^ Multiply(0x99,x96) ^ Multiply(0x45,x67) ^ Multiply(0x85,x66) ^ Multiply(0xb9,x65) ^ Multiply(0x75,S(x192)) ^ Multiply(0x15,S(x136));
																						const unsigned char x105=Multiply(0xd0,x121) ^ Multiply(0x2b,x113) ^ Multiply(0x09,x97) ^ Multiply(0xf3,x3) ^ Multiply(0xe1,x2) ^ Multiply(0xaf,x1) ^ Multiply(0x74,S(x185)) ^ Multiply(0xc7,S(x177));
																						const unsigned char x107=Multiply(0x98,x115) ^ Multiply(0x79,x75) ^ Multiply(0xb8,x27) ^ Multiply(0xd0,x21) ^ Multiply(0x41,x20) ^ Multiply(0x54,x19) ^ Multiply(0x79,S(x171)) ^ Multiply(0x54,S(x163));
																						const unsigned char x108=Multiply(0xfa,x124) ^ Multiply(0xc2,x84) ^ Multiply(0x45,x76) ^ Multiply(0x4e,x30) ^ Multiply(0x2f,x29) ^ Multiply(0x04,x28) ^ Multiply(0xef,S(x164)) ^ Multiply(0x0e,S(x156));
																						const unsigned char x109=Multiply(0x99,x93) ^ Multiply(0x0a,x85) ^ Multiply(0x73,x45) ^ Multiply(0x66,x41) ^ Multiply(0xe3,x38) ^ Multiply(0xa9,x37) ^ Multiply(0x89,S(x157)) ^ Multiply(0x9d,S(x149));
																						const unsigned char x110=Multiply(0xcb,x102) ^ Multiply(0x47,x94) ^ x78 ^ Multiply(0x42,x50) ^ Multiply(0x05,x49) ^ Multiply(0xcc,x46) ^ Multiply(0xcb,S(x150)) ^ Multiply(0xcf,S(x142));
																						const unsigned char x114=Multiply(0xb5,x122) ^ Multiply(0xd6,x106) ^ Multiply(0xe7,x18) ^ Multiply(0xe2,x12) ^ Multiply(0x74,x11) ^ Multiply(0x97,x10) ^ Multiply(0x55,S(x178)) ^ Multiply(0xc0,S(x170));
																						const unsigned char x116=Multiply(0xd7,x124) ^ Multiply(0x7d,x84) ^ Multiply(0xc2,x76) ^ Multiply(0xe5,x30) ^ Multiply(0xc0,x29) ^ Multiply(0x0e,x28) ^ Multiply(0xbd,S(x164)) ^ Multiply(0x2d,S(x156));
																						const unsigned char x117=Multiply(0x8f,x93) ^ Multiply(0x39,x85) ^ Multiply(0x33,x45) ^ Multiply(0xa1,x41) ^ Multiply(0x62,x38) ^ Multiply(0x22,x37) ^ Multiply(0xfb,S(x157)) ^ Multiply(0x8d,S(x149));
																						const unsigned char x118=Multiply(0x3e,x102) ^ Multiply(0x80,x94) ^ Multiply(0x51,x78) ^ Multiply(0x21,x50) ^ Multiply(0x6d,x49) ^ Multiply(0x57,x46) ^ Multiply(0xf0,S(x150)) ^ Multiply(0xc2,S(x142));
																						const unsigned char x119=Multiply(0x2a,x111) ^ Multiply(0x8b,x103) ^ Multiply(0x46,x87) ^ Multiply(0x1f,x59) ^ Multiply(0xbe,x58) ^ Multiply(0xa7,x57) ^ Multiply(0x17,S(x143)) ^ Multiply(0x20,S(x135));
																						const unsigned char x123=Multiply(0xf8,x115) ^ Multiply(0x21,x75) ^ Multiply(0xd2,x27) ^ Multiply(0x66,x21) ^ Multiply(0x5c,x20) ^ Multiply(0xcf,x19) ^ Multiply(0x28,S(x171)) ^ Multiply(0xc3,S(x163));
																						const unsigned char x125=Multiply(0xea,x93) ^ Multiply(0xa6,x85) ^ Multiply(0xec,x45) ^ Multiply(0xdd,x41) ^ Multiply(0xc5,x38) ^ Multiply(0xb0,x37) ^ Multiply(0xba,S(x157)) ^ Multiply(0xea,S(x149));
																						const unsigned char x126=Multiply(0xb1,x102) ^ Multiply(0xa8,x94) ^ Multiply(0xa5,x78) ^ Multiply(0xfc,x50) ^ Multiply(0x30,x49) ^ Multiply(0x83,x46) ^ Multiply(0xd6,S(x150)) ^ Multiply(0x45,S(x142));
																						const unsigned char x127=Multiply(0xc3,x111) ^ Multiply(0xe6,x103) ^ Multiply(0xff,x87) ^ Multiply(0x60,x59) ^ Multiply(0x47,x58) ^ Multiply(0xf6,x57) ^ Multiply(0xb7,S(x143)) ^ Multiply(0x10,S(x135));
																						const unsigned char x128=Multiply(0x47,x120) ^ Multiply(0x9b,x112) ^ Multiply(0x20,x96) ^ Multiply(0xf4,x67) ^ Multiply(0x59,x66) ^ Multiply(0x6d,x65) ^ Multiply(0xad,S(x192)) ^ Multiply(0x71,S(x136));
																						const unsigned char x193=x136;
																						const unsigned char x194=x129;
																						const unsigned char x195=x130;
																						const unsigned char x196=x131;
																						const unsigned char x197=x132;
																						const unsigned char x198=x133;
																						const unsigned char x199=x134;
																						const unsigned char x200=x135;
																						const unsigned char x201=x143;
																						const unsigned char x202=x144;
																						const unsigned char x203=x137;
																						const unsigned char x204=x138;
																						const unsigned char x205=x139;
																						const unsigned char x206=x140;
																						const unsigned char x207=x141;
																						const unsigned char x208=x142;
																						const unsigned char x209=x150;
																						const unsigned char x210=x151;
																						const unsigned char x211=x152;
																						const unsigned char x212=x145;
																						const unsigned char x213=x146;
																						const unsigned char x214=x147;
																						const unsigned char x215=x148;
																						const unsigned char x216=x149;
																						const unsigned char x217=x157;
																						const unsigned char x218=x158;
																						const unsigned char x219=x159;
																						const unsigned char x220=x160;
																						const unsigned char x221=x153;
																						const unsigned char x222=x154;
																						const unsigned char x223=x155;
																						const unsigned char x224=x156;
																						const unsigned char x225=x164;
																						const unsigned char x226=x165;
																						const unsigned char x227=x166;
																						const unsigned char x228=x167;
																						const unsigned char x229=x168;
																						const unsigned char x230=x161;
																						const unsigned char x231=x162;
																						const unsigned char x232=x163;
																						const unsigned char x233=x171;
																						const unsigned char x234=Multiply(0xc2,x267) ^ Multiply(0x40,x266) ^ Multiply(0xf4,x265) ^ Multiply(0x76,x165) ^ Multiply(0x46,x158) ^ Multiply(0x8e,x151) ^ Multiply(0x1c,x144) ^ Multiply(0x78,x129);
																						const unsigned char x235=x173;
																						const unsigned char x236=x174;
																						const unsigned char x237=x175;
																						const unsigned char x238=x176;
																						const unsigned char x239=Multiply(0x17,x310) ^ Multiply(0xa8,x309) ^ Multiply(0xd5,x308) ^ Multiply(0x8d,x162) ^ Multiply(0xaa,x155) ^ Multiply(0x12,x148) ^ Multiply(0xd1,x141) ^ Multiply(0xc3,x134);
																						const unsigned char x240=x170;
																						const unsigned char x241=x178;
																						const unsigned char x242=Multiply(0x40,x267) ^ Multiply(0xf1,x266) ^ Multiply(0x65,x265) ^ Multiply(0x45,x165) ^ Multiply(0x5a,x158) ^ Multiply(0xfd,x151) ^ Multiply(0x7d,x144) ^ Multiply(0xd2,x129);
																						const unsigned char x243=Multiply(0xd5,x280) ^ Multiply(0x39,x274) ^ Multiply(0x28,x173) ^ Multiply(0xe6,x166) ^ Multiply(0x31,x159) ^ Multiply(0x4c,x152) ^ Multiply(0x8b,x137) ^ Multiply(0x94,x130);
																						const unsigned char x244=Multiply(0xe3,x287) ^ Multiply(0x26,x281) ^ Multiply(0x3d,x174) ^ Multiply(0xf8,x167) ^ Multiply(0xa4,x160) ^ Multiply(0xb1,x145) ^ Multiply(0x12,x138) ^ Multiply(0x80,x131);
																						const unsigned char x245=Multiply(0xf7,x296) ^ Multiply(0xbd,x294) ^ Multiply(0x68,x175) ^ Multiply(0x13,x168) ^ Multiply(0x13,x153) ^ Multiply(0xf9,x146) ^ Multiply(0x3e,x139) ^ Multiply(0x61,x132);
																						const unsigned char x246=Multiply(0xd2,x303) ^ Multiply(0x2e,x301) ^ Multiply(0x21,x176) ^ Multiply(0x44,x161) ^ Multiply(0xab,x154) ^ Multiply(0x9e,x147) ^ Multiply(0x1b,x140) ^ Multiply(0x1e,x133);
																						const unsigned char x247=Multiply(0xa8,x310) ^ Multiply(0xbe,x309) ^ Multiply(0xc8,x308) ^ Multiply(0xda,x162) ^ Multiply(0x8d,x155) ^ Multiply(0xa0,x148) ^ Multiply(0x28,x141) ^ Multiply(0x94,x134);
																						const unsigned char x248=x177;
																						const unsigned char x249=x185;
																						const unsigned char x250=Multiply(0xf4,x267) ^ Multiply(0x65,x266) ^ Multiply(0xb8,x265) ^ Multiply(0xad,x165) ^ Multiply(0xd8,x158) ^ Multiply(0xf2,x151) ^ Multiply(0x4e,x144) ^ Multiply(0x26,x129);
																						const unsigned char x251=Multiply(0xa7,x280) ^ Multiply(0xf4,x274) ^ Multiply(0xea,x173) ^ Multiply(0xbb,x166) ^ Multiply(0x90,x159) ^ Multiply(0xcc,x152) ^ Multiply(0x9d,x137) ^ Multiply(0xa0,x130);
																						const unsigned char x252=Multiply(0x65,x287) ^ Multiply(0x33,x281) ^ Multiply(0xd8,x174) ^ Multiply(0xc4,x167) ^ Multiply(0x67,x160) ^ Multiply(0xa9,x145) ^ Multiply(0x6b,x138) ^ Multiply(0x8a,x131);
																						const unsigned char x253=Multiply(0xec,x296) ^ Multiply(0xd9,x294) ^ Multiply(0x83,x175) ^ Multiply(0xee,x168) ^ Multiply(0xdb,x153) ^ Multiply(0xf0,x146) ^ Multiply(0xa1,x139) ^ Multiply(0xf5,x132);
																						const unsigned char x254=Multiply(0x9d,x303) ^ Multiply(0x8d,x301) ^ Multiply(0x5e,x176) ^ Multiply(0x99,x161) ^ Multiply(0x75,x154) ^ Multiply(0x75,x147) ^ Multiply(0x84,x140) ^ Multiply(0xbb,x133);
																						const unsigned char x255=Multiply(0xd5,x310) ^ Multiply(0xc8,x309) ^ Multiply(0x10,x308) ^ Multiply(0x5d,x162) ^ Multiply(0x09,x155) ^ Multiply(0x44,x148) ^ Multiply(0x1e,x141) ^ Multiply(0xfd,x134);
																						const unsigned char x256=x192;
																						const unsigned char x268=Multiply(0x76,x267) ^ Multiply(0x45,x266) ^ Multiply(0xad,x265) ^ Multiply(0x4d,x165) ^ Multiply(0xca,x158) ^ Multiply(0x35,x151) ^ Multiply(0x59,x144) ^ Multiply(0x9e,x129);
																						const unsigned char x269=Multiply(0x46,x267) ^ Multiply(0x5a,x266) ^ Multiply(0xd8,x265) ^ Multiply(0xca,x165) ^ Multiply(0xa0,x158) ^ Multiply(0xf3,x151) ^ Multiply(0x1d,x144) ^ Multiply(0xc7,x129);
																						const unsigned char x270=Multiply(0x8e,x267) ^ Multiply(0xfd,x266) ^ Multiply(0xf2,x265) ^ Multiply(0x35,x165) ^ Multiply(0xf3,x158) ^ Multiply(0x6c,x151) ^ Multiply(0xa0,x144) ^ Multiply(0x83,x129);
																						const unsigned char x271=Multiply(0x1c,x267) ^ Multiply(0x7d,x266) ^ Multiply(0x4e,x265) ^ Multiply(0x59,x165) ^ Multiply(0x1d,x158) ^ Multiply(0xa0,x151) ^ Multiply(0xd3,x144) ^ Multiply(0x2d,x129);
																						const unsigned char x272=Multiply(0x78,x267) ^ Multiply(0xd2,x266) ^ Multiply(0x26,x265) ^ Multiply(0x9e,x165) ^ Multiply(0xc7,x158) ^ Multiply(0x83,x151) ^ Multiply(0x2d,x144) ^ Multiply(0x8c,x129);
																						const unsigned char x273=Multiply(0x9d,x280) ^ Multiply(0x19,x274) ^ Multiply(0xfe,x173) ^ Multiply(0x2a,x166) ^ Multiply(0xe7,x159) ^ Multiply(0x42,x152) ^ Multiply(0x60,x137) ^ Multiply(0x9b,x130);
																						const unsigned char x275=Multiply(0x8c,x280) ^ Multiply(0xb5,x274) ^ Multiply(0xa6,x173) ^ Multiply(0xaf,x166) ^ Multiply(0xde,x159) ^ Multiply(0xed,x152) ^ Multiply(0xd1,x137) ^ Multiply(0x0a,x130);
																						const unsigned char x276=Multiply(0xa8,x280) ^ Multiply(0x0c,x274) ^ Multiply(0xf3,x173) ^ Multiply(0xfa,x166) ^ Multiply(0xcf,x159) ^ Multiply(0x71,x152) ^ Multiply(0x1d,x137) ^ Multiply(0xc9,x130);
																						const unsigned char x277=Multiply(0x26,x280) ^ Multiply(0x06,x274) ^ Multiply(0x25,x173) ^ Multiply(0x12,x166) ^ Multiply(0xca,x159) ^ Multiply(0xef,x152) ^ Multiply(0xe5,x137) ^ Multiply(0xe8,x130);
																						const unsigned char x278=Multiply(0x09,x280) ^ Multiply(0x74,x274) ^ Multiply(0xd4,x173) ^ Multiply(0x42,x166) ^ Multiply(0x09,x159) ^ Multiply(0x96,x152) ^ Multiply(0x96,x137) ^ Multiply(0x42,x130);
																						const unsigned char x279=Multiply(0xb9,x280) ^ Multiply(0x61,x274) ^ Multiply(0x1b,x173) ^ Multiply(0x1b,x166) ^ Multiply(0x55,x159) ^ Multiply(0xd8,x152) ^ Multiply(0xd2,x137) ^ Multiply(0xe1,x130);
																						const unsigned char x282=Multiply(0x43,x287) ^ Multiply(0x50,x281) ^ Multiply(0x31,x174) ^ Multiply(0x4f,x167) ^ Multiply(0x74,x160) ^ Multiply(0xa8,x145) ^ Multiply(0x4e,x138) ^ Multiply(0xe2,x131);
																						const unsigned char x283=Multiply(0xb0,x287) ^ Multiply(0x20,x281) ^ Multiply(0x9d,x174) ^ Multiply(0x51,x167) ^ Multiply(0x6b,x160) ^ Multiply(0x67,x145) ^ Multiply(0xfb,x138) ^ Multiply(0xbd,x131);
																						const unsigned char x284=Multiply(0x4f,x287) ^ Multiply(0x23,x281) ^ Multiply(0x1b,x174) ^ Multiply(0xb0,x167) ^ Multiply(0xb0,x160) ^ Multiply(0x37,x145) ^ Multiply(0xc1,x138) ^ Multiply(0x3f,x131);
																						const unsigned char x285=Multiply(0xeb,x287) ^ Multiply(0x66,x281) ^ Multiply(0x17,x174) ^ Multiply(0xba,x167) ^ Multiply(0x24,x160) ^ Multiply(0xa3,x145) ^ Multiply(0xc5,x138) ^ Multiply(0x62,x131);
																						const unsigned char x286=Multiply(0xb0,x287) ^ Multiply(0xf4,x281) ^ Multiply(0x59,x174) ^ Multiply(0x30,x167) ^ Multiply(0xcb,x160) ^ Multiply(0x3e,x145) ^ Multiply(0xe8,x138) ^ Multiply(0xbe,x131);
																						const unsigned char x288=Multiply(0x6d,x287) ^ Multiply(0x3a,x281) ^ Multiply(0xa5,x174) ^ Multiply(0xc6,x167) ^ Multiply(0xf7,x160) ^ Multiply(0x9b,x145) ^ Multiply(0x71,x138) ^ Multiply(0x4c,x131);
																						const unsigned char x289=Multiply(0x22,x296) ^ Multiply(0x8b,x294) ^ Multiply(0x5a,x175) ^ Multiply(0x9c,x168) ^ Multiply(0x58,x153) ^ Multiply(0x50,x146) ^ Multiply(0x72,x139) ^ Multiply(0x2d,x132);
																						const unsigned char x290=Multiply(0x90,x296) ^ Multiply(0x10,x294) ^ Multiply(0xef,x175) ^ Multiply(0x4c,x168) ^ Multiply(0x90,x153) ^ Multiply(0xa3,x146) ^ Multiply(0xa3,x139) ^ Multiply(0x4c,x132);
																						const unsigned char x291=Multiply(0x76,x296) ^ Multiply(0xa5,x294) ^ Multiply(0xf3,x175) ^ Multiply(0x30,x168) ^ Multiply(0x24,x153) ^ Multiply(0x27,x146) ^ Multiply(0x1b,x139) ^ Multiply(0x95,x132);
																						const unsigned char x292=Multiply(0x32,x296) ^ Multiply(0xc0,x294) ^ Multiply(0x5b,x175) ^ Multiply(0x87,x168) ^ Multiply(0x55,x153) ^ Multiply(0xa4,x146) ^ Multiply(0xc8,x139) ^ Multiply(0xb4,x132);
																						const unsigned char x293=Multiply(0x6b,x296) ^ Multiply(0x60,x294) ^ Multiply(0x71,x175) ^ Multiply(0xa1,x168) ^ Multiply(0x87,x153) ^ Multiply(0x08,x146) ^ Multiply(0x02,x139) ^ Multiply(0x5b,x132);
																						const unsigned char x295=Multiply(0x95,x296) ^ Multiply(0x4a,x294) ^ Multiply(0xc3,x175) ^ Multiply(0x92,x168) ^ Multiply(0x79,x153) ^ Multiply(0x89,x146) ^ Multiply(0x83,x139) ^ Multiply(0x68,x132);
																						const unsigned char x297=Multiply(0x1a,x303) ^ Multiply(0x36,x301) ^ Multiply(0xcf,x176) ^ Multiply(0x4e,x161) ^ Multiply(0x42,x154) ^ Multiply(0x9e,x147) ^ Multiply(0x9f,x140) ^ Multiply(0xd9,x133);
																						const unsigned char x298=Multiply(0x22,x303) ^ Multiply(0x62,x301) ^ Multiply(0x7e,x176) ^ Multiply(0xc5,x161) ^ Multiply(0x13,x154) ^ Multiply(0x07,x147) ^ Multiply(0xb1,x140) ^ Multiply(0x21,x133);
																						const unsigned char x299=Multiply(0xdd,x303) ^ Multiply(0x9a,x301) ^ Multiply(0x15,x176) ^ Multiply(0x52,x161) ^ Multiply(0xf3,x154) ^ Multiply(0x21,x147) ^ Multiply(0x9d,x140) ^ Multiply(0xc3,x133);
																						const unsigned char x300=Multiply(0x0c,x303) ^ Multiply(0xc0,x301) ^ Multiply(0xd9,x176) ^ Multiply(0x61,x161) ^ Multiply(0xee,x154) ^ Multiply(0xc8,x147) ^ Multiply(0x1d,x140) ^ Multiply(0x31,x133);
																						const unsigned char x302=Multiply(0x7b,x303) ^ Multiply(0x7e,x301) ^ Multiply(0x99,x176) ^ Multiply(0x96,x161) ^ Multiply(0x71,x154) ^ Multiply(0x9a,x147) ^ Multiply(0xb8,x140) ^ Multiply(0xa9,x133);
																						const unsigned char x304=Multiply(0x5f,x303) ^ Multiply(0x10,x301) ^ Multiply(0xce,x176) ^ Multiply(0x93,x161) ^ Multiply(0x81,x154) ^ Multiply(0x45,x147) ^ Multiply(0x95,x140) ^ Multiply(0x36,x133);
																						const unsigned char x305=Multiply(0x12,x310) ^ Multiply(0xa0,x309) ^ Multiply(0x44,x308) ^ Multiply(0x76,x162) ^ Multiply(0xf7,x155) ^ Multiply(0x0f,x148) ^ Multiply(0xf4,x141) ^ Multiply(0xde,x134);
																						const unsigned char x306=Multiply(0xd1,x310) ^ Multiply(0x28,x309) ^ Multiply(0x1e,x308) ^ Multiply(0x17,x162) ^ Multiply(0xd3,x155) ^ Multiply(0xf4,x148) ^ Multiply(0x5b,x141) ^ Multiply(0xc0,x134);
																						const unsigned char x307=Multiply(0xc3,x310) ^ Multiply(0x94,x309) ^ Multiply(0xfd,x308) ^ Multiply(0x76,x162) ^ Multiply(0xc3,x155) ^ Multiply(0xde,x148) ^ Multiply(0xc0,x141) ^ Multiply(0x3b,x134);
																						const unsigned char x311=Multiply(0x8d,x310) ^ Multiply(0xda,x309) ^ Multiply(0x5d,x308) ^ Multiply(0xe9,x162) ^ Multiply(0x0e,x155) ^ Multiply(0x76,x148) ^ Multiply(0x17,x141) ^ Multiply(0x76,x134);
																						const unsigned char x312=Multiply(0xaa,x310) ^ Multiply(0x8d,x309) ^ Multiply(0x09,x308) ^ Multiply(0x0e,x162) ^ Multiply(0x05,x155) ^ Multiply(0xf7,x148) ^ Multiply(0xd3,x141) ^ Multiply(0xc3,x134);
																						printf("# Solution found :\n");
																						printf("MC_3[7,7] = %02x\n",x1);
																						printf("MC_3[6,7] = %02x\n",x2);
																						printf("MC_3[5,7] = %02x\n",x3);
																						printf("MC_3[4,7] = %02x\n",x4);
																						printf("MC_3[3,7] = %02x\n",x5);
																						printf("MC_3[2,7] = %02x\n",x6);
																						printf("MC_3[1,7] = %02x\n",x7);
																						printf("MC_3[0,7] = %02x\n",x8);
																						printf("AC_3[7,7] = %02x\n",x9);
																						printf("MC_3[7,6] = %02x\n",x10);
																						printf("MC_3[6,6] = %02x\n",x11);
																						printf("MC_3[5,6] = %02x\n",x12);
																						printf("MC_3[4,6] = %02x\n",x13);
																						printf("MC_3[3,6] = %02x\n",x14);
																						printf("MC_3[2,6] = %02x\n",x15);
																						printf("MC_3[1,6] = %02x\n",x16);
																						printf("MC_3[0,6] = %02x\n",x17);
																						printf("AC_3[7,6] = %02x\n",x18);
																						printf("MC_3[7,5] = %02x\n",x19);
																						printf("MC_3[6,5] = %02x\n",x20);
																						printf("MC_3[5,5] = %02x\n",x21);
																						printf("MC_3[4,5] = %02x\n",x22);
																						printf("MC_3[3,5] = %02x\n",x23);
																						printf("MC_3[2,5] = %02x\n",x24);
																						printf("MC_3[1,5] = %02x\n",x25);
																						printf("MC_3[0,5] = %02x\n",x26);
																						printf("AC_3[7,5] = %02x\n",x27);
																						printf("MC_3[7,4] = %02x\n",x28);
																						printf("MC_3[6,4] = %02x\n",x29);
																						printf("MC_3[5,4] = %02x\n",x30);
																						printf("MC_3[4,4] = %02x\n",x31);
																						printf("MC_3[3,4] = %02x\n",x32);
																						printf("MC_3[2,4] = %02x\n",x33);
																						printf("MC_3[1,4] = %02x\n",x34);
																						printf("MC_3[0,4] = %02x\n",x35);
																						printf("AC_3[7,4] = %02x\n",x36);
																						printf("MC_3[7,3] = %02x\n",x37);
																						printf("MC_3[6,3] = %02x\n",x38);
																						printf("MC_3[5,3] = %02x\n",x39);
																						printf("MC_3[4,3] = %02x\n",x40);
																						printf("MC_3[3,3] = %02x\n",x41);
																						printf("MC_3[2,3] = %02x\n",x42);
																						printf("MC_3[1,3] = %02x\n",x43);
																						printf("MC_3[0,3] = %02x\n",x44);
																						printf("AC_3[7,3] = %02x\n",x45);
																						printf("MC_3[7,2] = %02x\n",x46);
																						printf("MC_3[6,2] = %02x\n",x47);
																						printf("MC_3[5,2] = %02x\n",x48);
																						printf("MC_3[4,2] = %02x\n",x49);
																						printf("MC_3[3,2] = %02x\n",x50);
																						printf("MC_3[2,2] = %02x\n",x51);
																						printf("MC_3[1,2] = %02x\n",x52);
																						printf("MC_3[0,2] = %02x\n",x53);
																						printf("AC_3[7,2] = %02x\n",x54);
																						printf("MC_3[7,1] = %02x\n",x55);
																						printf("MC_3[6,1] = %02x\n",x56);
																						printf("MC_3[5,1] = %02x\n",x57);
																						printf("MC_3[4,1] = %02x\n",x58);
																						printf("MC_3[3,1] = %02x\n",x59);
																						printf("MC_3[2,1] = %02x\n",x60);
																						printf("MC_3[1,1] = %02x\n",x61);
																						printf("MC_3[0,1] = %02x\n",x62);
																						printf("AC_3[7,1] = %02x\n",x63);
																						printf("MC_3[7,0] = %02x\n",x64);
																						printf("MC_3[6,0] = %02x\n",x65);
																						printf("MC_3[5,0] = %02x\n",x66);
																						printf("MC_3[4,0] = %02x\n",x67);
																						printf("MC_3[3,0] = %02x\n",x68);
																						printf("MC_3[2,0] = %02x\n",x69);
																						printf("MC_3[1,0] = %02x\n",x70);
																						printf("MC_3[0,0] = %02x\n",x71);
																						printf("AC_3[7,0] = %02x\n",x72);
																						printf("AC_3[6,7] = %02x\n",x73);
																						printf("AC_3[6,6] = %02x\n",x74);
																						printf("AC_3[6,5] = %02x\n",x75);
																						printf("AC_3[6,4] = %02x\n",x76);
																						printf("AC_3[6,3] = %02x\n",x77);
																						printf("AC_3[6,2] = %02x\n",x78);
																						printf("AC_3[6,1] = %02x\n",x79);
																						printf("AC_3[6,0] = %02x\n",x80);
																						printf("AC_3[5,7] = %02x\n",x81);
																						printf("AC_3[5,6] = %02x\n",x82);
																						printf("AC_3[5,5] = %02x\n",x83);
																						printf("AC_3[5,4] = %02x\n",x84);
																						printf("AC_3[5,3] = %02x\n",x85);
																						printf("AC_3[5,2] = %02x\n",x86);
																						printf("AC_3[5,1] = %02x\n",x87);
																						printf("AC_3[5,0] = %02x\n",x88);
																						printf("AC_3[4,7] = %02x\n",x89);
																						printf("AC_3[4,6] = %02x\n",x90);
																						printf("AC_3[4,5] = %02x\n",x91);
																						printf("AC_3[4,4] = %02x\n",x92);
																						printf("AC_3[4,3] = %02x\n",x93);
																						printf("AC_3[4,2] = %02x\n",x94);
																						printf("AC_3[4,1] = %02x\n",x95);
																						printf("AC_3[4,0] = %02x\n",x96);
																						printf("AC_3[3,7] = %02x\n",x97);
																						printf("AC_3[3,6] = %02x\n",x98);
																						printf("AC_3[3,5] = %02x\n",x99);
																						printf("AC_3[3,4] = %02x\n",x100);
																						printf("AC_3[3,3] = %02x\n",x101);
																						printf("AC_3[3,2] = %02x\n",x102);
																						printf("AC_3[3,1] = %02x\n",x103);
																						printf("AC_3[3,0] = %02x\n",x104);
																						printf("AC_3[2,7] = %02x\n",x105);
																						printf("AC_3[2,6] = %02x\n",x106);
																						printf("AC_3[2,5] = %02x\n",x107);
																						printf("AC_3[2,4] = %02x\n",x108);
																						printf("AC_3[2,3] = %02x\n",x109);
																						printf("AC_3[2,2] = %02x\n",x110);
																						printf("AC_3[2,1] = %02x\n",x111);
																						printf("AC_3[2,0] = %02x\n",x112);
																						printf("AC_3[1,7] = %02x\n",x113);
																						printf("AC_3[1,6] = %02x\n",x114);
																						printf("AC_3[1,5] = %02x\n",x115);
																						printf("AC_3[1,4] = %02x\n",x116);
																						printf("AC_3[1,3] = %02x\n",x117);
																						printf("AC_3[1,2] = %02x\n",x118);
																						printf("AC_3[1,1] = %02x\n",x119);
																						printf("AC_3[1,0] = %02x\n",x120);
																						printf("AC_3[0,7] = %02x\n",x121);
																						printf("AC_3[0,6] = %02x\n",x122);
																						printf("AC_3[0,5] = %02x\n",x123);
																						printf("AC_3[0,4] = %02x\n",x124);
																						printf("AC_3[0,3] = %02x\n",x125);
																						printf("AC_3[0,2] = %02x\n",x126);
																						printf("AC_3[0,1] = %02x\n",x127);
																						printf("AC_3[0,0] = %02x\n",x128);
																						printf("SB_3[7,6] = %02x\n",x129);
																						printf("SB_3[7,5] = %02x\n",x130);
																						printf("SB_3[7,4] = %02x\n",x131);
																						printf("SB_3[7,3] = %02x\n",x132);
																						printf("SB_3[7,2] = %02x\n",x133);
																						printf("SB_3[7,1] = %02x\n",x134);
																						printf("SB_3[7,0] = %02x\n",x135);
																						printf("SB_3[7,7] = %02x\n",x136);
																						printf("SB_3[6,5] = %02x\n",x137);
																						printf("SB_3[6,4] = %02x\n",x138);
																						printf("SB_3[6,3] = %02x\n",x139);
																						printf("SB_3[6,2] = %02x\n",x140);
																						printf("SB_3[6,1] = %02x\n",x141);
																						printf("SB_3[6,0] = %02x\n",x142);
																						printf("SB_3[6,7] = %02x\n",x143);
																						printf("SB_3[6,6] = %02x\n",x144);
																						printf("SB_3[5,4] = %02x\n",x145);
																						printf("SB_3[5,3] = %02x\n",x146);
																						printf("SB_3[5,2] = %02x\n",x147);
																						printf("SB_3[5,1] = %02x\n",x148);
																						printf("SB_3[5,0] = %02x\n",x149);
																						printf("SB_3[5,7] = %02x\n",x150);
																						printf("SB_3[5,6] = %02x\n",x151);
																						printf("SB_3[5,5] = %02x\n",x152);
																						printf("SB_3[4,3] = %02x\n",x153);
																						printf("SB_3[4,2] = %02x\n",x154);
																						printf("SB_3[4,1] = %02x\n",x155);
																						printf("SB_3[4,0] = %02x\n",x156);
																						printf("SB_3[4,7] = %02x\n",x157);
																						printf("SB_3[4,6] = %02x\n",x158);
																						printf("SB_3[4,5] = %02x\n",x159);
																						printf("SB_3[4,4] = %02x\n",x160);
																						printf("SB_3[3,2] = %02x\n",x161);
																						printf("SB_3[3,1] = %02x\n",x162);
																						printf("SB_3[3,0] = %02x\n",x163);
																						printf("SB_3[3,7] = %02x\n",x164);
																						printf("SB_3[3,6] = %02x\n",x165);
																						printf("SB_3[3,5] = %02x\n",x166);
																						printf("SB_3[3,4] = %02x\n",x167);
																						printf("SB_3[3,3] = %02x\n",x168);
																						printf("SB_3[2,1] = %02x\n",x169);
																						printf("SB_3[2,0] = %02x\n",x170);
																						printf("SB_3[2,7] = %02x\n",x171);
																						printf("SB_3[2,6] = %02x\n",x172);
																						printf("SB_3[2,5] = %02x\n",x173);
																						printf("SB_3[2,4] = %02x\n",x174);
																						printf("SB_3[2,3] = %02x\n",x175);
																						printf("SB_3[2,2] = %02x\n",x176);
																						printf("SB_3[1,0] = %02x\n",x177);
																						printf("SB_3[1,7] = %02x\n",x178);
																						printf("SB_3[1,6] = %02x\n",x179);
																						printf("SB_3[1,5] = %02x\n",x180);
																						printf("SB_3[1,4] = %02x\n",x181);
																						printf("SB_3[1,3] = %02x\n",x182);
																						printf("SB_3[1,2] = %02x\n",x183);
																						printf("SB_3[1,1] = %02x\n",x184);
																						printf("SB_3[0,7] = %02x\n",x185);
																						printf("SB_3[0,6] = %02x\n",x186);
																						printf("SB_3[0,5] = %02x\n",x187);
																						printf("SB_3[0,4] = %02x\n",x188);
																						printf("SB_3[0,3] = %02x\n",x189);
																						printf("SB_3[0,2] = %02x\n",x190);
																						printf("SB_3[0,1] = %02x\n",x191);
																						printf("SB_3[0,0] = %02x\n",x192);
																						printf("AC_2[7,7] = %02x\n",x193);
																						printf("AC_2[7,6] = %02x\n",x194);
																						printf("AC_2[7,5] = %02x\n",x195);
																						printf("AC_2[7,4] = %02x\n",x196);
																						printf("AC_2[7,3] = %02x\n",x197);
																						printf("AC_2[7,2] = %02x\n",x198);
																						printf("AC_2[7,1] = %02x\n",x199);
																						printf("AC_2[7,0] = %02x\n",x200);
																						printf("AC_2[6,7] = %02x\n",x201);
																						printf("AC_2[6,6] = %02x\n",x202);
																						printf("AC_2[6,5] = %02x\n",x203);
																						printf("AC_2[6,4] = %02x\n",x204);
																						printf("AC_2[6,3] = %02x\n",x205);
																						printf("AC_2[6,2] = %02x\n",x206);
																						printf("AC_2[6,1] = %02x\n",x207);
																						printf("AC_2[6,0] = %02x\n",x208);
																						printf("AC_2[5,7] = %02x\n",x209);
																						printf("AC_2[5,6] = %02x\n",x210);
																						printf("AC_2[5,5] = %02x\n",x211);
																						printf("AC_2[5,4] = %02x\n",x212);
																						printf("AC_2[5,3] = %02x\n",x213);
																						printf("AC_2[5,2] = %02x\n",x214);
																						printf("AC_2[5,1] = %02x\n",x215);
																						printf("AC_2[5,0] = %02x\n",x216);
																						printf("AC_2[4,7] = %02x\n",x217);
																						printf("AC_2[4,6] = %02x\n",x218);
																						printf("AC_2[4,5] = %02x\n",x219);
																						printf("AC_2[4,4] = %02x\n",x220);
																						printf("AC_2[4,3] = %02x\n",x221);
																						printf("AC_2[4,2] = %02x\n",x222);
																						printf("AC_2[4,1] = %02x\n",x223);
																						printf("AC_2[4,0] = %02x\n",x224);
																						printf("AC_2[3,7] = %02x\n",x225);
																						printf("AC_2[3,6] = %02x\n",x226);
																						printf("AC_2[3,5] = %02x\n",x227);
																						printf("AC_2[3,4] = %02x\n",x228);
																						printf("AC_2[3,3] = %02x\n",x229);
																						printf("AC_2[3,2] = %02x\n",x230);
																						printf("AC_2[3,1] = %02x\n",x231);
																						printf("AC_2[3,0] = %02x\n",x232);
																						printf("AC_2[2,7] = %02x\n",x233);
																						printf("AC_2[2,6] = %02x\n",x234);
																						printf("AC_2[2,5] = %02x\n",x235);
																						printf("AC_2[2,4] = %02x\n",x236);
																						printf("AC_2[2,3] = %02x\n",x237);
																						printf("AC_2[2,2] = %02x\n",x238);
																						printf("AC_2[2,1] = %02x\n",x239);
																						printf("AC_2[2,0] = %02x\n",x240);
																						printf("AC_2[1,7] = %02x\n",x241);
																						printf("AC_2[1,6] = %02x\n",x242);
																						printf("AC_2[1,5] = %02x\n",x243);
																						printf("AC_2[1,4] = %02x\n",x244);
																						printf("AC_2[1,3] = %02x\n",x245);
																						printf("AC_2[1,2] = %02x\n",x246);
																						printf("AC_2[1,1] = %02x\n",x247);
																						printf("AC_2[1,0] = %02x\n",x248);
																						printf("AC_2[0,7] = %02x\n",x249);
																						printf("AC_2[0,6] = %02x\n",x250);
																						printf("AC_2[0,5] = %02x\n",x251);
																						printf("AC_2[0,4] = %02x\n",x252);
																						printf("AC_2[0,3] = %02x\n",x253);
																						printf("AC_2[0,2] = %02x\n",x254);
																						printf("AC_2[0,1] = %02x\n",x255);
																						printf("AC_2[0,0] = %02x\n",x256);
																						printf("MC_2[7,7] = %02x\n",x257);
																						printf("MC_2[6,7] = %02x\n",x258);
																						printf("MC_2[5,7] = %02x\n",x259);
																						printf("MC_2[4,7] = %02x\n",x260);
																						printf("MC_2[3,7] = %02x\n",x261);
																						printf("MC_2[2,7] = %02x\n",x262);
																						printf("MC_2[1,7] = %02x\n",x263);
																						printf("MC_2[0,7] = %02x\n",x264);
																						printf("MC_2[7,6] = %02x\n",x265);
																						printf("MC_2[6,6] = %02x\n",x266);
																						printf("MC_2[5,6] = %02x\n",x267);
																						printf("MC_2[4,6] = %02x\n",x268);
																						printf("MC_2[3,6] = %02x\n",x269);
																						printf("MC_2[2,6] = %02x\n",x270);
																						printf("MC_2[1,6] = %02x\n",x271);
																						printf("MC_2[0,6] = %02x\n",x272);
																						printf("MC_2[7,5] = %02x\n",x273);
																						printf("MC_2[6,5] = %02x\n",x274);
																						printf("MC_2[5,5] = %02x\n",x275);
																						printf("MC_2[4,5] = %02x\n",x276);
																						printf("MC_2[3,5] = %02x\n",x277);
																						printf("MC_2[2,5] = %02x\n",x278);
																						printf("MC_2[1,5] = %02x\n",x279);
																						printf("MC_2[0,5] = %02x\n",x280);
																						printf("MC_2[7,4] = %02x\n",x281);
																						printf("MC_2[6,4] = %02x\n",x282);
																						printf("MC_2[5,4] = %02x\n",x283);
																						printf("MC_2[4,4] = %02x\n",x284);
																						printf("MC_2[3,4] = %02x\n",x285);
																						printf("MC_2[2,4] = %02x\n",x286);
																						printf("MC_2[1,4] = %02x\n",x287);
																						printf("MC_2[0,4] = %02x\n",x288);
																						printf("MC_2[7,3] = %02x\n",x289);
																						printf("MC_2[6,3] = %02x\n",x290);
																						printf("MC_2[5,3] = %02x\n",x291);
																						printf("MC_2[4,3] = %02x\n",x292);
																						printf("MC_2[3,3] = %02x\n",x293);
																						printf("MC_2[2,3] = %02x\n",x294);
																						printf("MC_2[1,3] = %02x\n",x295);
																						printf("MC_2[0,3] = %02x\n",x296);
																						printf("MC_2[7,2] = %02x\n",x297);
																						printf("MC_2[6,2] = %02x\n",x298);
																						printf("MC_2[5,2] = %02x\n",x299);
																						printf("MC_2[4,2] = %02x\n",x300);
																						printf("MC_2[3,2] = %02x\n",x301);
																						printf("MC_2[2,2] = %02x\n",x302);
																						printf("MC_2[1,2] = %02x\n",x303);
																						printf("MC_2[0,2] = %02x\n",x304);
																						printf("MC_2[7,1] = %02x\n",x305);
																						printf("MC_2[6,1] = %02x\n",x306);
																						printf("MC_2[5,1] = %02x\n",x307);
																						printf("MC_2[4,1] = %02x\n",x308);
																						printf("MC_2[3,1] = %02x\n",x309);
																						printf("MC_2[2,1] = %02x\n",x310);
																						printf("MC_2[1,1] = %02x\n",x311);
																						printf("MC_2[0,1] = %02x\n",x312);
																						printf("MC_2[7,0] = %02x\n",x313);
																						printf("MC_2[6,0] = %02x\n",x314);
																						printf("MC_2[5,0] = %02x\n",x315);
																						printf("MC_2[4,0] = %02x\n",x316);
																						printf("MC_2[3,0] = %02x\n",x317);
																						printf("MC_2[2,0] = %02x\n",x318);
																						printf("MC_2[1,0] = %02x\n",x319);
																						printf("MC_2[0,0] = %02x\n",x320);
																						return ;/*getchar();*/
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int j_24;
	for (j_24 = 1; j_24 <= Alloue_24; j_24++) free(espace_24[j_24]);
	free(L_24);
}

int Generator(unsigned char Known[71]/*, unsigned char y[321]*/)
{
	const unsigned char x0=1;
	const unsigned char x320=1+(rand()%255);
	const unsigned char x97=1+(rand()%255);
	const unsigned char x106=1+(rand()%255);
	const unsigned char x115=1+(rand()%255);
	const unsigned char x124=1+(rand()%255);
	const unsigned char x45=1+(rand()%255);
	const unsigned char x78=1+(rand()%255);
	const unsigned char x87=1+(rand()%255);
	const unsigned char x96=1+(rand()%255);
	const unsigned char x113=1+(rand()%255);
	const unsigned char x122=1+(rand()%255);
	const unsigned char x27=1+(rand()%255);
	const unsigned char x76=1+(rand()%255);
	const unsigned char x85=1+(rand()%255);
	const unsigned char x94=1+(rand()%255);
	const unsigned char x103=1+(rand()%255);
	const unsigned char x112=1+(rand()%255);
	const unsigned char x121=1+(rand()%255);
	const unsigned char x18=1+(rand()%255);
	const unsigned char x75=1+(rand()%255);
	const unsigned char x84=1+(rand()%255);
	const unsigned char x93=1+(rand()%255);
	const unsigned char x102=1+(rand()%255);
	const unsigned char x111=1+(rand()%255);
	const unsigned char x120=1+(rand()%255);
	const unsigned char x136=1+(rand()%255);
	const unsigned char x135=1+(rand()%255);
	const unsigned char x143=1+(rand()%255);
	const unsigned char x142=1+(rand()%255);
	const unsigned char x150=1+(rand()%255);
	const unsigned char x149=1+(rand()%255);
	const unsigned char x157=1+(rand()%255);
	const unsigned char x156=1+(rand()%255);
	const unsigned char x164=1+(rand()%255);
	const unsigned char x163=1+(rand()%255);
	const unsigned char x171=1+(rand()%255);
	const unsigned char x170=1+(rand()%255);
	const unsigned char x178=1+(rand()%255);
	const unsigned char x177=1+(rand()%255);
	const unsigned char x185=1+(rand()%255);
	const unsigned char x192=Multiply(0x4b,x320) ^ Multiply(0x79,x177) ^ Multiply(0xb6,x170) ^ Multiply(0xb4,x163) ^ Multiply(0x81,x156) ^ Multiply(0xbf,x149) ^ Multiply(0x21,x142) ^ Multiply(0x5c,x135);
	const unsigned char x265=1+(rand()%255);
	const unsigned char x266=1+(rand()%255);
	const unsigned char x267=1+(rand()%255);
	const unsigned char x274=1+(rand()%255);
	const unsigned char x280=1+(rand()%255);
	const unsigned char x281=1+(rand()%255);
	const unsigned char x287=1+(rand()%255);
	const unsigned char x294=1+(rand()%255);
	const unsigned char x296=1+(rand()%255);
	const unsigned char x301=1+(rand()%255);
	const unsigned char x303=1+(rand()%255);
	const unsigned char x308=1+(rand()%255);
	const unsigned char x309=1+(rand()%255);
	const unsigned char x310=1+(rand()%255);
	const unsigned char x257=Multiply(0x5a,x185) ^ Multiply(0x54,x178) ^ Multiply(0x72,x171) ^ Multiply(0x50,x164) ^ Multiply(0xdf,x157) ^ Multiply(0x45,x150) ^ Multiply(0x53,x143) ^ Multiply(0x13,x136);
	const unsigned char x313=Multiply(0x5a,x192) ^ Multiply(0x54,x177) ^ Multiply(0x72,x170) ^ Multiply(0x50,x163) ^ Multiply(0xdf,x156) ^ Multiply(0x45,x149) ^ Multiply(0x53,x142) ^ Multiply(0x13,x135);
	const unsigned char x258=Multiply(0x54,x185) ^ Multiply(0x72,x178) ^ Multiply(0x50,x171) ^ Multiply(0xdf,x164) ^ Multiply(0x45,x157) ^ Multiply(0x53,x150) ^ Multiply(0x13,x143) ^ Multiply(0x5a,x136);
	const unsigned char x314=Multiply(0x54,x192) ^ Multiply(0x72,x177) ^ Multiply(0x50,x170) ^ Multiply(0xdf,x163) ^ Multiply(0x45,x156) ^ Multiply(0x53,x149) ^ Multiply(0x13,x142) ^ Multiply(0x5a,x135);
	const unsigned char x259=Multiply(0x72,x185) ^ Multiply(0x50,x178) ^ Multiply(0xdf,x171) ^ Multiply(0x45,x164) ^ Multiply(0x53,x157) ^ Multiply(0x13,x150) ^ Multiply(0x5a,x143) ^ Multiply(0x54,x136);
	const unsigned char x315=Multiply(0x72,x192) ^ Multiply(0x50,x177) ^ Multiply(0xdf,x170) ^ Multiply(0x45,x163) ^ Multiply(0x53,x156) ^ Multiply(0x13,x149) ^ Multiply(0x5a,x142) ^ Multiply(0x54,x135);
	const unsigned char x260=Multiply(0x50,x185) ^ Multiply(0xdf,x178) ^ Multiply(0x45,x171) ^ Multiply(0x53,x164) ^ Multiply(0x13,x157) ^ Multiply(0x5a,x150) ^ Multiply(0x54,x143) ^ Multiply(0x72,x136);
	const unsigned char x316=Multiply(0x50,x192) ^ Multiply(0xdf,x177) ^ Multiply(0x45,x170) ^ Multiply(0x53,x163) ^ Multiply(0x13,x156) ^ Multiply(0x5a,x149) ^ Multiply(0x54,x142) ^ Multiply(0x72,x135);
	const unsigned char x261=Multiply(0xdf,x185) ^ Multiply(0x45,x178) ^ Multiply(0x53,x171) ^ Multiply(0x13,x164) ^ Multiply(0x5a,x157) ^ Multiply(0x54,x150) ^ Multiply(0x72,x143) ^ Multiply(0x50,x136);
	const unsigned char x317=Multiply(0xdf,x192) ^ Multiply(0x45,x177) ^ Multiply(0x53,x170) ^ Multiply(0x13,x163) ^ Multiply(0x5a,x156) ^ Multiply(0x54,x149) ^ Multiply(0x72,x142) ^ Multiply(0x50,x135);
	const unsigned char x262=Multiply(0x45,x185) ^ Multiply(0x53,x178) ^ Multiply(0x13,x171) ^ Multiply(0x5a,x164) ^ Multiply(0x54,x157) ^ Multiply(0x72,x150) ^ Multiply(0x50,x143) ^ Multiply(0xdf,x136);
	const unsigned char x318=Multiply(0x45,x192) ^ Multiply(0x53,x177) ^ Multiply(0x13,x170) ^ Multiply(0x5a,x163) ^ Multiply(0x54,x156) ^ Multiply(0x72,x149) ^ Multiply(0x50,x142) ^ Multiply(0xdf,x135);
	const unsigned char x263=Multiply(0x53,x185) ^ Multiply(0x13,x178) ^ Multiply(0x5a,x171) ^ Multiply(0x54,x164) ^ Multiply(0x72,x157) ^ Multiply(0x50,x150) ^ Multiply(0xdf,x143) ^ Multiply(0x45,x136);
	const unsigned char x319=Multiply(0x53,x192) ^ Multiply(0x13,x177) ^ Multiply(0x5a,x170) ^ Multiply(0x54,x163) ^ Multiply(0x72,x156) ^ Multiply(0x50,x149) ^ Multiply(0xdf,x142) ^ Multiply(0x45,x135);
	const unsigned char x264=Multiply(0x13,x185) ^ Multiply(0x5a,x178) ^ Multiply(0x54,x171) ^ Multiply(0x72,x164) ^ Multiply(0x50,x157) ^ Multiply(0xdf,x150) ^ Multiply(0x45,x143) ^ Multiply(0x53,x136);
	Known[0]=x0; /* 1 */
	Known[1]=x97; /* AC_3[3,7] */
	Known[2]=x106; /* AC_3[2,6] */
	Known[3]=x115; /* AC_3[1,5] */
	Known[4]=x124; /* AC_3[0,4] */
	Known[5]=x45; /* AC_3[7,3] */
	Known[6]=x78; /* AC_3[6,2] */
	Known[7]=x87; /* AC_3[5,1] */
	Known[8]=x96; /* AC_3[4,0] */
	Known[9]=x113; /* AC_3[1,7] */
	Known[10]=x122; /* AC_3[0,6] */
	Known[11]=x27; /* AC_3[7,5] */
	Known[12]=x76; /* AC_3[6,4] */
	Known[13]=x85; /* AC_3[5,3] */
	Known[14]=x94; /* AC_3[4,2] */
	Known[15]=x103; /* AC_3[3,1] */
	Known[16]=x112; /* AC_3[2,0] */
	Known[17]=x121; /* AC_3[0,7] */
	Known[18]=x18; /* AC_3[7,6] */
	Known[19]=x75; /* AC_3[6,5] */
	Known[20]=x84; /* AC_3[5,4] */
	Known[21]=x93; /* AC_3[4,3] */
	Known[22]=x102; /* AC_3[3,2] */
	Known[23]=x111; /* AC_3[2,1] */
	Known[24]=x120; /* AC_3[1,0] */
	Known[25]=x136; /* SB_3[7,7] */
	Known[26]=x135; /* SB_3[7,0] */
	Known[27]=x143; /* SB_3[6,7] */
	Known[28]=x142; /* SB_3[6,0] */
	Known[29]=x150; /* SB_3[5,7] */
	Known[30]=x149; /* SB_3[5,0] */
	Known[31]=x157; /* SB_3[4,7] */
	Known[32]=x156; /* SB_3[4,0] */
	Known[33]=x164; /* SB_3[3,7] */
	Known[34]=x163; /* SB_3[3,0] */
	Known[35]=x171; /* SB_3[2,7] */
	Known[36]=x170; /* SB_3[2,0] */
	Known[37]=x178; /* SB_3[1,7] */
	Known[38]=x177; /* SB_3[1,0] */
	Known[39]=x185; /* SB_3[0,7] */
	Known[40]=x192; /* SB_3[0,0] */
	Known[41]=x265; /* MC_2[7,6] */
	Known[42]=x266; /* MC_2[6,6] */
	Known[43]=x267; /* MC_2[5,6] */
	Known[44]=x274; /* MC_2[6,5] */
	Known[45]=x280; /* MC_2[0,5] */
	Known[46]=x281; /* MC_2[7,4] */
	Known[47]=x287; /* MC_2[1,4] */
	Known[48]=x294; /* MC_2[2,3] */
	Known[49]=x296; /* MC_2[0,3] */
	Known[50]=x301; /* MC_2[3,2] */
	Known[51]=x303; /* MC_2[1,2] */
	Known[52]=x308; /* MC_2[4,1] */
	Known[53]=x309; /* MC_2[3,1] */
	Known[54]=x310; /* MC_2[2,1] */
	Known[55]=x257; /* MC_2[7,7] */
	Known[56]=x313; /* MC_2[7,0] */
	Known[57]=x258; /* MC_2[6,7] */
	Known[58]=x314; /* MC_2[6,0] */
	Known[59]=x259; /* MC_2[5,7] */
	Known[60]=x315; /* MC_2[5,0] */
	Known[61]=x260; /* MC_2[4,7] */
	Known[62]=x316; /* MC_2[4,0] */
	Known[63]=x261; /* MC_2[3,7] */
	Known[64]=x317; /* MC_2[3,0] */
	Known[65]=x262; /* MC_2[2,7] */
	Known[66]=x318; /* MC_2[2,0] */
	Known[67]=x263; /* MC_2[1,7] */
	Known[68]=x319; /* MC_2[1,0] */
	Known[69]=x264; /* MC_2[0,7] */
	Known[70]=x320; /* MC_2[0,0] */
	return 1;
	return 0;
}

int main(int argc, char** argv)
{
	unsigned char Known[71];
   srand(getpid()); /* Init PRNG */
	MakeTableMul2_8();
	/* assign values */
	Generator(Known);
	/* Attack */
	Attack(Known);
	return 0;
}
