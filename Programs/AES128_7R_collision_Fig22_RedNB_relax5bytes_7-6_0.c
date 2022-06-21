#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "AES128_7R_collision_Fig22_RedNB_relax5bytes_7-6_0.h"

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
 * x[1] = K_0[3,2]
 * x[2] = K_0[2,2]
 * x[3] = K_0[1,2]
 * x[4] = K_0[0,2]
 * x[5] = Z_0[0,1]
 * x[6] = Z_0[0,0]
 * x[7] = K_1[0,0]
 * x[8] = K_0[1,3]
 * x[9] = K_0[0,0]
 * x[10] = K_1[1,0]
 * x[11] = K_0[2,3]
 * x[12] = K_0[1,0]
 * x[13] = K_1[2,0]
 * x[14] = K_0[3,3]
 * x[15] = K_0[2,0]
 * x[16] = K_1[3,0]
 * x[17] = K_0[3,0]
 * x[18] = K_0[0,3]
 * x[19] = K_1[0,1]
 * x[20] = K_0[0,1]
 * x[21] = K_1[1,1]
 * x[22] = K_0[1,1]
 * x[23] = K_1[2,1]
 * x[24] = K_0[2,1]
 * x[25] = K_1[3,1]
 * x[26] = K_0[3,1]
 * x[27] = K_1[0,2]
 * x[28] = K_1[1,2]
 * x[29] = K_1[2,2]
 * x[30] = K_1[3,2]
 * x[31] = K_1[0,3]
 * x[32] = K_1[1,3]
 * x[33] = K_1[2,3]
 * x[34] = K_1[3,3]
 * x[35] = K_2[0,0]
 * x[36] = K_2[1,0]
 * x[37] = K_2[2,0]
 * x[38] = K_2[3,0]
 * x[39] = K_2[0,1]
 * x[40] = K_2[1,1]
 * x[41] = K_2[2,1]
 * x[42] = K_2[3,1]
 * x[43] = K_2[0,2]
 * x[44] = K_2[1,2]
 * x[45] = K_2[2,2]
 * x[46] = K_2[3,2]
 * x[47] = K_2[0,3]
 * x[48] = K_2[1,3]
 * x[49] = K_2[2,3]
 * x[50] = K_2[3,3]
 * x[51] = K_3[0,0]
 * x[52] = K_3[1,0]
 * x[53] = K_3[2,0]
 * x[54] = K_3[3,0]
 * x[55] = K_3[0,1]
 * x[56] = K_3[1,1]
 * x[57] = K_3[2,1]
 * x[58] = K_3[3,1]
 * x[59] = K_3[0,2]
 * x[60] = K_3[1,2]
 * x[61] = K_3[2,2]
 * x[62] = K_3[3,2]
 * x[63] = K_3[0,3]
 * x[64] = K_3[1,3]
 * x[65] = K_3[2,3]
 * x[66] = K_3[3,3]
 * x[67] = K_4[0,0]
 * x[68] = K_4[1,0]
 * x[69] = K_4[2,0]
 * x[70] = K_4[3,0]
 * x[71] = K_4[0,1]
 * x[72] = K_4[1,1]
 * x[73] = K_4[2,1]
 * x[74] = K_4[3,1]
 * x[75] = K_4[0,2]
 * x[76] = K_4[1,2]
 * x[77] = K_4[2,2]
 * x[78] = K_4[3,2]
 * x[79] = K_4[0,3]
 * x[80] = K_4[1,3]
 * x[81] = K_4[2,3]
 * x[82] = K_4[3,3]
 * x[83] = K_5[0,0]
 * x[84] = K_5[1,0]
 * x[85] = K_5[2,0]
 * x[86] = K_5[3,0]
 * x[87] = K_5[0,1]
 * x[88] = K_5[1,1]
 * x[89] = K_5[2,1]
 * x[90] = K_5[3,1]
 * x[91] = K_5[0,2]
 * x[92] = K_5[1,2]
 * x[93] = K_5[2,2]
 * x[94] = K_5[3,2]
 * x[95] = K_5[0,3]
 * x[96] = K_5[1,3]
 * x[97] = K_5[2,3]
 * x[98] = K_5[3,3]
 * x[99] = AK_1[3,3]
 * x[100] = AK_1[2,3]
 * x[101] = AK_1[1,3]
 * x[102] = AK_1[0,3]
 * x[103] = SB_1[3,3]
 * x[104] = AK_1[3,0]
 * x[105] = AK_1[2,0]
 * x[106] = AK_1[1,0]
 * x[107] = AK_1[0,0]
 * x[108] = SB_1[2,0]
 * x[109] = AK_1[3,1]
 * x[110] = AK_1[2,1]
 * x[111] = AK_1[1,1]
 * x[112] = AK_1[0,1]
 * x[113] = SB_1[1,1]
 * x[114] = AK_1[3,2]
 * x[115] = AK_1[2,2]
 * x[116] = AK_1[1,2]
 * x[117] = AK_1[0,2]
 * x[118] = SB_1[0,2]
 * x[119] = SB_2[3,3]
 * x[120] = SB_2[3,2]
 * x[121] = SB_2[3,1]
 * x[122] = SB_2[3,0]
 * x[123] = SB_2[2,3]
 * x[124] = SB_2[2,2]
 * x[125] = SB_2[2,1]
 * x[126] = SB_2[2,0]
 * x[127] = SB_2[1,3]
 * x[128] = SB_2[1,2]
 * x[129] = SB_2[1,1]
 * x[130] = SB_2[1,0]
 * x[131] = SB_2[0,3]
 * x[132] = SB_2[0,2]
 * x[133] = SB_2[0,1]
 * x[134] = SB_2[0,0]
 * x[135] = AK_2[3,3]
 * x[136] = AK_2[2,3]
 * x[137] = AK_2[1,3]
 * x[138] = AK_2[0,3]
 * x[139] = AK_2[3,2]
 * x[140] = AK_2[2,2]
 * x[141] = AK_2[1,2]
 * x[142] = AK_2[0,2]
 * x[143] = AK_2[3,1]
 * x[144] = AK_2[2,1]
 * x[145] = AK_2[1,1]
 * x[146] = AK_2[0,1]
 * x[147] = AK_2[3,0]
 * x[148] = AK_2[2,0]
 * x[149] = AK_2[1,0]
 * x[150] = AK_2[0,0]
 * x[151] = SB_3[3,3]
 * x[152] = SB_3[3,2]
 * x[153] = SB_3[3,1]
 * x[154] = SB_3[3,0]
 * x[155] = SB_3[2,3]
 * x[156] = SB_3[2,2]
 * x[157] = SB_3[2,1]
 * x[158] = SB_3[2,0]
 * x[159] = SB_3[1,3]
 * x[160] = SB_3[1,2]
 * x[161] = SB_3[1,1]
 * x[162] = SB_3[1,0]
 * x[163] = SB_3[0,3]
 * x[164] = SB_3[0,2]
 * x[165] = SB_3[0,1]
 * x[166] = SB_3[0,0]
 * x[167] = AK_3[3,3]
 * x[168] = AK_3[2,3]
 * x[169] = AK_3[1,3]
 * x[170] = AK_3[0,3]
 * x[171] = AK_3[3,2]
 * x[172] = AK_3[2,2]
 * x[173] = AK_3[1,2]
 * x[174] = AK_3[0,2]
 * x[175] = AK_3[3,1]
 * x[176] = AK_3[2,1]
 * x[177] = AK_3[1,1]
 * x[178] = AK_3[0,1]
 * x[179] = AK_3[3,0]
 * x[180] = AK_3[2,0]
 * x[181] = AK_3[1,0]
 * x[182] = AK_3[0,0]
 * x[183] = SB_4[3,3]
 * x[184] = SB_4[3,2]
 * x[185] = SB_4[3,1]
 * x[186] = SB_4[3,0]
 * x[187] = SB_4[2,3]
 * x[188] = SB_4[2,2]
 * x[189] = SB_4[2,1]
 * x[190] = SB_4[2,0]
 * x[191] = SB_4[1,3]
 * x[192] = SB_4[1,2]
 * x[193] = SB_4[1,1]
 * x[194] = SB_4[1,0]
 * x[195] = SB_4[0,3]
 * x[196] = SB_4[0,2]
 * x[197] = SB_4[0,1]
 * x[198] = SB_4[0,0]
 * x[199] = AK_4[3,3]
 * x[200] = AK_4[2,2]
 * x[201] = AK_4[1,1]
 * x[202] = AK_4[0,0]
 * x[203] = SB_5[3,3]
 * x[204] = SB_5[2,2]
 * x[205] = SB_5[1,1]
 * x[206] = SB_5[0,0]
 **/
void Attack(const unsigned char Known[27])
{
	const unsigned char x0=Known[0]; /* 1 */
	const unsigned char x205=Known[1]; /* SB_5[1,1] */
	const unsigned char x203=Known[2]; /* SB_5[3,3] */
	const unsigned char x204=Known[3]; /* SB_5[2,2] */
	const unsigned char x187=Known[4]; /* SB_4[2,3] */
	const unsigned char x191=Known[5]; /* SB_4[1,3] */
	const unsigned char x195=Known[6]; /* SB_4[0,3] */
	const unsigned char x185=Known[7]; /* SB_4[3,1] */
	const unsigned char x167=Known[8]; /* AK_3[3,3] */
	const unsigned char x119=Known[9]; /* SB_2[3,3] */
	const unsigned char x121=Known[10]; /* SB_2[3,1] */
	const unsigned char x124=Known[11]; /* SB_2[2,2] */
	const unsigned char x126=Known[12]; /* SB_2[2,0] */
	const unsigned char x127=Known[13]; /* SB_2[1,3] */
	const unsigned char x129=Known[14]; /* SB_2[1,1] */
	const unsigned char x132=Known[15]; /* SB_2[0,2] */
	const unsigned char x134=Known[16]; /* SB_2[0,0] */
	const unsigned char x5=Known[17]; /* Z_0[0,1] */
	const unsigned char x6=Known[18]; /* Z_0[0,0] */
	const unsigned char x86=Known[19]; /* K_5[3,0] */
	const unsigned char x84=Known[20]; /* K_5[1,0] */
	const unsigned char x47=Known[21]; /* K_2[0,3] */
	const unsigned char x46=Known[22]; /* K_2[3,2] */
	const unsigned char x36=Known[23]; /* K_2[1,0] */
	const unsigned char x66=Known[24]; /* K_3[3,3] */
	const unsigned char x14=Known[25]; /* K_0[3,3] */
	const unsigned char x1=Known[26]; /* K_0[3,2] */
	const unsigned char x150=Multiply(0x02,S(x134)) ^ Multiply(0x03,S(x129)) ^ S(x124) ^ S(x119);
	const unsigned char x149=Multiply(0x8d,x150) ^ Multiply(0x8e,S(x129)) ^ Multiply(0x8e,S(x124)) ^ Multiply(0x8c,S(x119));
	const unsigned char x148=Multiply(0x68,x150) ^ Multiply(0xd1,x149) ^ Multiply(0x02,S(x124)) ^ Multiply(0xba,S(x119));
	const unsigned char x147=Multiply(0x5d,x150) ^ Multiply(0x35,x149) ^ Multiply(0x8c,x148) ^ Multiply(0xe5,S(x119));
	const unsigned char x142=Multiply(0x02,S(x132)) ^ Multiply(0x03,S(x127)) ^ S(x126) ^ S(x121);
	const unsigned char x141=Multiply(0x8d,x142) ^ Multiply(0x8e,S(x127)) ^ Multiply(0x8e,S(x126)) ^ Multiply(0x8c,S(x121));
	const unsigned char x140=Multiply(0x68,x142) ^ Multiply(0xd1,x141) ^ Multiply(0x02,S(x126)) ^ Multiply(0xba,S(x121));
	const unsigned char x139=Multiply(0x5d,x142) ^ Multiply(0x35,x141) ^ Multiply(0x8c,x140) ^ Multiply(0xe5,S(x121));
	const unsigned char x54=x46 ^ x1 ^ S(x47);
	const unsigned char x38=x46 ^ x1;
	const unsigned char x183=x167 ^ x66;
	const unsigned char x152=x139 ^ x46;
	const unsigned char x154=x147 ^ x38;
	const unsigned char x162=x149 ^ x36;
	
	Chaine13_3 espace_13[2];
	POSITION13_3 *L_13;
	L_13=malloc(taille1_13*sizeof(POSITION13_3));
	espace_13[1]=malloc(taille2_13*sizeof(CHAINE13_3));
	
	uint8_t Alloue_13=1;
	unsigned long int pos_13;
	for (pos_13 = 0; pos_13 < taille1_13 ; pos_13++) L_13[pos_13].a=0;
	unsigned long int cpt_13=0;
	int i_7;
	for (i_7 = 0; i_7 < 0x100; i_7++)
	{
		const unsigned char x164=i_7;
		int i_8;
		for (i_8 = 0; i_8 < 0x100; i_8++)
		{
			const unsigned char x166=i_8;
			int i_9;
			for (i_9 = 0; i_9 < 0x100; i_9++)
			{
				const unsigned char x184=i_9;
				int i_10;
				for (i_10 = 0; i_10 < 0x100; i_10++)
				{
					const unsigned char x186=i_10;
					int i_11;
					for (i_11 = 0; i_11 < 0x100; i_11++)
					{
						const unsigned char x194=i_11;
						int i_12;
						for (i_12 = 0; i_12 < 0x100; i_12++)
						{
							const unsigned char x197=i_12;
							pos_13=(x166 ^ x164);
							pos_13=(pos_13 << 8) ^ (x194 ^ Multiply(0x07,x186) ^ Multiply(0x0d,S(x166)));
							pos_13=(pos_13 << 8) ^ (S(x194) ^ Multiply(0x02,S(x184)));
							pos_13=(pos_13 << 8) ^ (Multiply(0x52,x184) ^ Multiply(0x51,S(x164)));
							pos_13=(pos_13 << 8) ^ (x197 ^ x164);
							pos_13=(pos_13 << 8) ^ (S(x197) ^ S(x186));
							espace_13[1][cpt_13].d0=x164;
							espace_13[1][cpt_13].d1=x166;
							espace_13[1][cpt_13].d2=x194;
							espace_13[1][cpt_13].a=L_13[pos_13].a;
							espace_13[1][cpt_13].b=L_13[pos_13].b;
							L_13[pos_13].a=1;
							L_13[pos_13].b=cpt_13;
							cpt_13++;
						}
					}
				}
			}
		}
	}
	int i_0;
	for (i_0 = 0; i_0 < 0x100; i_0++)
	{
		const unsigned char x63=i_0;
		const unsigned char x64=Multiply(0x04,x195) ^ x191 ^ Multiply(0x07,x167) ^ Multiply(0x04,x63) ^ Multiply(0x09,S(x162)) ^ Multiply(0x0b,S(x152));
		const unsigned char x65=Multiply(0x07,x195) ^ x187 ^ Multiply(0x05,x167) ^ Multiply(0x07,x63) ^ Multiply(0x0d,S(x162)) ^ Multiply(0x0e,S(x152));
		const unsigned char x79=R(x86 ^ x54 ^ S(x63));
		int i_1;
		for (i_1 = 0; i_1 < 0x100; i_1++)
		{
			const unsigned char x81=i_1;
			int i_2;
			for (i_2 = 0; i_2 < 0x100; i_2++)
			{
				const unsigned char x48=i_2;
				const unsigned char x49=R(x84 ^ x36 ^ S(x81) ^ S(x65));
				const unsigned char x50=R(Multiply(0x07,x195) ^ x187 ^ Multiply(0x05,x167) ^ x81 ^ Multiply(0x07,x79) ^ Multiply(0x0d,x6) ^ Multiply(0x0e,x5) ^ Multiply(0x05,x1) ^ Multiply(0x48,x0) ^ Multiply(0x0d,S(x162)) ^ Multiply(0x0e,S(x152)) ^ S(x66) ^ Multiply(0x07,S(x64)) ^ Multiply(0x07,S(x48)));
				int i_3;
				for (i_3 = 0; i_3 < 0x100; i_3++)
				{
					const unsigned char x156=i_3;
					const unsigned char x158=x156 ^ x148 ^ x140 ^ Multiply(0x07,x79) ^ Multiply(0x07,x63) ^ Multiply(0x0d,x6) ^ Multiply(0x0e,x5) ^ Multiply(0x05,x1) ^ Multiply(0x48,x0) ^ Multiply(0x07,S(x64)) ^ Multiply(0x07,S(x48));
					const unsigned char x160=x141 ^ Multiply(0x04,x79) ^ Multiply(0x04,x63) ^ x36 ^ Multiply(0x09,x6) ^ Multiply(0x0b,x5) ^ Multiply(0x07,x1) ^ Multiply(0x60,x0) ^ Multiply(0x04,S(x64)) ^ Multiply(0x04,S(x48));
					int i_4;
					for (i_4 = 0; i_4 < 0x100; i_4++)
					{
						const unsigned char x189=i_4;
						int i_5;
						for (i_5 = 0; i_5 < 0x100; i_5++)
						{
							const unsigned char x190=i_5;
							int i_6;
							for (i_6 = 0; i_6 < 0x100; i_6++)
							{
								const unsigned char x192=i_6;
								const unsigned char x196=R(x204 ^ Multiply(0x07,x79) ^ Multiply(0x07,x63) ^ Multiply(0x0d,x6) ^ Multiply(0x0e,x5) ^ Multiply(0x05,x1) ^ Multiply(0x48,x0) ^ S(x191) ^ Multiply(0x02,S(x190)) ^ Multiply(0x03,S(x185)) ^ S(x66) ^ Multiply(0x07,S(x64)) ^ S(x50) ^ Multiply(0x07,S(x48)));
								pos_13=(x150 ^ x142 ^ x79 ^ x63 ^ Multiply(0x18,x0) ^ S(x64) ^ S(x48));
								pos_13=(pos_13 << 8) ^ (Multiply(0x05,x190) ^ Multiply(0x05,x156) ^ Multiply(0x05,x140) ^ Multiply(0x1b,x79) ^ Multiply(0x1b,x63) ^ Multiply(0x07,x54) ^ x36 ^ Multiply(0x39,x6) ^ Multiply(0x36,x5) ^ Multiply(0x11,x1) ^ Multiply(0x73,x0) ^ Multiply(0x0e,S(x156)) ^ Multiply(0x1b,S(x64)) ^ Multiply(0x05,S(x50)) ^ S(x49) ^ Multiply(0x1b,S(x48)));
								pos_13=(pos_13 << 8) ^ (x203 ^ x66 ^ x54 ^ x46 ^ Multiply(0x03,S(x195)) ^ S(x189) ^ S(x63));
								pos_13=(pos_13 << 8) ^ (x196 ^ Multiply(0xa2,x195) ^ Multiply(0xa5,x192) ^ Multiply(0xa5,x191) ^ Multiply(0x56,x167) ^ Multiply(0xa3,x63) ^ Multiply(0x52,x54) ^ Multiply(0x52,x50) ^ Multiply(0xa5,x48) ^ x47 ^ Multiply(0x52,x38) ^ Multiply(0x52,x14) ^ Multiply(0x52,x1) ^ Multiply(0xfa,S(x162)) ^ Multiply(0xa7,S(x158)) ^ Multiply(0xab,S(x152)));
								pos_13=(pos_13 << 8) ^ (x195 ^ Multiply(0xd1,x189) ^ Multiply(0xd1,x187) ^ Multiply(0xb8,x185) ^ Multiply(0xb8,x167) ^ Multiply(0xd1,x156) ^ x142 ^ Multiply(0xd1,x140) ^ Multiply(0xb8,x54) ^ Multiply(0xb8,x50) ^ Multiply(0xd1,x49) ^ x47 ^ Multiply(0xb8,x46) ^ Multiply(0xb8,x38) ^ Multiply(0xb8,x14) ^ Multiply(0xb8,x1) ^ Multiply(0x6a,S(x162)) ^ Multiply(0x6a,S(x160)) ^ Multiply(0x02,S(x154)) ^ Multiply(0x02,S(x152)));
								pos_13=(pos_13 << 8) ^ (x205 ^ Multiply(0x04,x195) ^ x191 ^ Multiply(0x07,x167) ^ Multiply(0x04,x79) ^ x48 ^ Multiply(0x09,x6) ^ Multiply(0x0b,x5) ^ Multiply(0x07,x1) ^ Multiply(0x60,x0) ^ Multiply(0x02,S(x192)) ^ Multiply(0x03,S(x187)) ^ Multiply(0x09,S(x162)) ^ Multiply(0x0b,S(x152)) ^ S(x65) ^ Multiply(0x04,S(x64)) ^ S(x49) ^ Multiply(0x04,S(x48)));
								POSITION13_3 tmp2_13=L_13[pos_13];
								while (tmp2_13.a) /* Entrée : 7*/
								{
									const unsigned char x164=espace_13[1][tmp2_13.b].d0;
									const unsigned char x166=espace_13[1][tmp2_13.b].d1;
									const unsigned char x194=espace_13[1][tmp2_13.b].d2;
									tmp2_13.a=espace_13[1][tmp2_13.b].a;
									tmp2_13.b=espace_13[1][tmp2_13.b].b;
								/* --- 13 */
									const unsigned char x197=x195 ^ Multiply(0xd1,x189) ^ Multiply(0xd1,x187) ^ Multiply(0xb8,x185) ^ Multiply(0xb8,x167) ^ x164 ^ Multiply(0xd1,x156) ^ x142 ^ Multiply(0xd1,x140) ^ Multiply(0xb8,x54) ^ Multiply(0xb8,x50) ^ Multiply(0xd1,x49) ^ x47 ^ Multiply(0xb8,x46) ^ Multiply(0xb8,x38) ^ Multiply(0xb8,x14) ^ Multiply(0xb8,x1) ^ Multiply(0x6a,S(x162)) ^ Multiply(0x6a,S(x160)) ^ Multiply(0x02,S(x154)) ^ Multiply(0x02,S(x152));
									const unsigned char x186=Multiply(0xd1,x194) ^ Multiply(0xb8,x190) ^ Multiply(0xb8,x156) ^ Multiply(0xb8,x140) ^ Multiply(0x05,x79) ^ Multiply(0x05,x63) ^ x54 ^ Multiply(0xd1,x36) ^ Multiply(0xd9,x6) ^ Multiply(0x0a,x5) ^ Multiply(0x6e,x1) ^ Multiply(0x78,x0) ^ Multiply(0x6a,S(x166)) ^ Multiply(0x02,S(x156)) ^ Multiply(0x05,S(x64)) ^ Multiply(0xb8,S(x50)) ^ Multiply(0xd1,S(x49)) ^ Multiply(0x05,S(x48));
									if ((S(x186))==(x205 ^ Multiply(0x04,x195) ^ x191 ^ Multiply(0x07,x167) ^ Multiply(0x04,x79) ^ x48 ^ Multiply(0x09,x6) ^ Multiply(0x0b,x5) ^ Multiply(0x07,x1) ^ Multiply(0x60,x0) ^ S(x197) ^ Multiply(0x02,S(x192)) ^ Multiply(0x03,S(x187)) ^ Multiply(0x09,S(x162)) ^ Multiply(0x0b,S(x152)) ^ S(x65) ^ Multiply(0x04,S(x64)) ^ S(x49) ^ Multiply(0x04,S(x48))))
									{
										const unsigned char x184=R(Multiply(0x8d,x203) ^ Multiply(0x8d,x66) ^ Multiply(0x8d,x54) ^ Multiply(0x8d,x46) ^ Multiply(0x8c,S(x195)) ^ Multiply(0x8d,S(x194)) ^ Multiply(0x8d,S(x189)) ^ Multiply(0x8d,S(x63)));
										if ((Multiply(0x52,x184))==(x196 ^ Multiply(0xa2,x195) ^ Multiply(0xa5,x192) ^ Multiply(0xa5,x191) ^ Multiply(0x56,x167) ^ Multiply(0xa3,x63) ^ Multiply(0x52,x54) ^ Multiply(0x52,x50) ^ Multiply(0xa5,x48) ^ x47 ^ Multiply(0x52,x38) ^ Multiply(0x52,x14) ^ Multiply(0x52,x1) ^ Multiply(0x51,S(x164)) ^ Multiply(0xfa,S(x162)) ^ Multiply(0xa7,S(x158)) ^ Multiply(0xab,S(x152))))
										{
											/* --- 13 */
											const unsigned char x151=R(x190 ^ x186 ^ x156 ^ x140 ^ Multiply(0x07,x79) ^ Multiply(0x07,x63) ^ x54 ^ Multiply(0x0d,x6) ^ Multiply(0x0e,x5) ^ Multiply(0x05,x1) ^ Multiply(0x48,x0) ^ Multiply(0x02,S(x166)) ^ Multiply(0x03,S(x156)) ^ Multiply(0x07,S(x64)) ^ S(x50) ^ Multiply(0x07,S(x48)));
											const unsigned char x153=R(Multiply(0x52,x192) ^ Multiply(0xa4,x184) ^ Multiply(0x52,x64) ^ Multiply(0xa4,x54) ^ Multiply(0xa4,x50) ^ Multiply(0x52,x48) ^ Multiply(0xa4,x38) ^ Multiply(0xa4,x14) ^ Multiply(0xa4,x1) ^ Multiply(0xa5,S(x164)) ^ Multiply(0x52,S(x158)));
											const unsigned char x155=R(Multiply(0x68,x189) ^ Multiply(0xd1,x185) ^ Multiply(0x68,x156) ^ Multiply(0x68,x140) ^ Multiply(0x68,x65) ^ Multiply(0xd1,x54) ^ Multiply(0xd1,x50) ^ Multiply(0x68,x49) ^ Multiply(0xd1,x46) ^ Multiply(0xd1,x38) ^ Multiply(0xd1,x14) ^ Multiply(0xd1,x1) ^ Multiply(0xb9,S(x160)) ^ S(x154));
											const unsigned char x157=R(Multiply(0x0d,x195) ^ Multiply(0x09,x191) ^ Multiply(0x0e,x187) ^ Multiply(0x0b,x167) ^ Multiply(0x0e,x65) ^ Multiply(0x09,x64) ^ Multiply(0x0d,x63));
											const unsigned char x159=R(x184 ^ x54 ^ x50 ^ x38 ^ x14 ^ x1 ^ Multiply(0x03,S(x164)) ^ S(x158) ^ Multiply(0x02,S(x153)));
											const unsigned char x161=R(x186 ^ x54 ^ Multiply(0x03,S(x166)) ^ S(x156) ^ Multiply(0x02,S(x151)));
											const unsigned char x163=R(Multiply(0x0e,x195) ^ Multiply(0x0b,x191) ^ Multiply(0x0d,x187) ^ Multiply(0x09,x167) ^ Multiply(0x0d,x65) ^ Multiply(0x0b,x64) ^ Multiply(0x0e,x63));
											const unsigned char x165=R(Multiply(0xf6,x185) ^ Multiply(0xf6,x54) ^ Multiply(0xf6,x50) ^ Multiply(0xf6,x46) ^ Multiply(0xf6,x38) ^ Multiply(0xf6,x14) ^ Multiply(0xf6,x1) ^ Multiply(0xf6,S(x160)) ^ Multiply(0xf6,S(x155)) ^ Multiply(0xf7,S(x154)));
											const unsigned char x8=Multiply(0x04,x79) ^ x64 ^ Multiply(0x04,x63) ^ Multiply(0x09,x6) ^ Multiply(0x0b,x5) ^ Multiply(0x07,x1) ^ Multiply(0x60,x0) ^ Multiply(0x04,S(x64)) ^ S(x49) ^ Multiply(0x04,S(x48));
											const unsigned char x11=x65 ^ Multiply(0x47,x64) ^ Multiply(0x47,x8) ^ Multiply(0x44,x6) ^ Multiply(0xc9,x5) ^ Multiply(0xcb,x1) ^ S(x50) ^ Multiply(0x47,S(x49));
											const unsigned char x18=Multiply(0xcb,x64) ^ x63 ^ Multiply(0xcb,x8) ^ Multiply(0xc9,x6) ^ Multiply(0x44,x5) ^ Multiply(0x47,x1) ^ Multiply(0x08,x0) ^ Multiply(0xcb,S(x49)) ^ S(x48);
											const unsigned char x31=x164 ^ x142 ^ x47;
											const unsigned char x32=Multiply(0x04,x63) ^ x48 ^ x36 ^ Multiply(0x04,x18) ^ Multiply(0x09,x6) ^ Multiply(0x0b,x5) ^ Multiply(0x07,x1) ^ Multiply(0x20,x0) ^ Multiply(0x04,S(x48));
											const unsigned char x33=x156 ^ x140 ^ x49;
											const unsigned char x34=x50 ^ x46;
											const unsigned char x80=x8 ^ S(x65);
											const unsigned char x82=x66 ^ x54 ^ x46 ^ S(x63);
											const unsigned char x120=R(Multiply(0x0b,x163) ^ Multiply(0x0d,x159) ^ Multiply(0x09,x155) ^ Multiply(0x0e,x151) ^ Multiply(0x09,x49) ^ Multiply(0x0d,x48) ^ Multiply(0x0b,x47) ^ Multiply(0x0e,x46) ^ Multiply(0x0e,x34));
											const unsigned char x122=R(Multiply(0x0b,x165) ^ Multiply(0x0d,x161) ^ Multiply(0x09,x157) ^ Multiply(0x0e,x153) ^ Multiply(0x09,x49) ^ Multiply(0x0d,x48) ^ Multiply(0x0b,x47) ^ Multiply(0x0e,x38) ^ Multiply(0x0e,x34) ^ Multiply(0x0b,x18) ^ Multiply(0x0e,x14) ^ Multiply(0x09,x11) ^ Multiply(0x0d,x8) ^ Multiply(0x0e,x1));
											const unsigned char x123=R(Multiply(0x9b,x161) ^ Multiply(0x76,x157) ^ Multiply(0x5b,x153) ^ Multiply(0x76,x49) ^ Multiply(0x9b,x48) ^ Multiply(0x5b,x38) ^ Multiply(0x5b,x34) ^ Multiply(0x5b,x14) ^ Multiply(0x76,x11) ^ Multiply(0x9b,x8) ^ Multiply(0x5b,x1) ^ Multiply(0xb7,S(x122)));
											const unsigned char x125=R(Multiply(0x9b,x159) ^ Multiply(0x76,x155) ^ Multiply(0x5b,x151) ^ Multiply(0x76,x49) ^ Multiply(0x9b,x48) ^ Multiply(0x5b,x46) ^ Multiply(0x5b,x34) ^ Multiply(0xb7,S(x120)));
											const unsigned char x128=R(Multiply(0x8c,x157) ^ Multiply(0x8d,x153) ^ Multiply(0x8c,x49) ^ Multiply(0x8d,x38) ^ Multiply(0x8d,x34) ^ Multiply(0x8d,x14) ^ Multiply(0x8c,x11) ^ Multiply(0x8d,x1) ^ Multiply(0x8e,S(x123)) ^ Multiply(0x8e,S(x122)));
											const unsigned char x130=R(Multiply(0x8c,x155) ^ Multiply(0x8d,x151) ^ Multiply(0x8c,x49) ^ Multiply(0x8d,x46) ^ Multiply(0x8d,x34) ^ Multiply(0x8e,S(x125)) ^ Multiply(0x8e,S(x120)));
											const unsigned char x131=R(Multiply(0xf6,x151) ^ Multiply(0xf6,x46) ^ Multiply(0xf6,x34) ^ Multiply(0xf6,S(x130)) ^ Multiply(0xf6,S(x125)) ^ Multiply(0xf7,S(x120)));
											const unsigned char x133=R(Multiply(0xf6,x153) ^ Multiply(0xf6,x38) ^ Multiply(0xf6,x34) ^ Multiply(0xf6,x14) ^ Multiply(0xf6,x1) ^ Multiply(0xf6,S(x128)) ^ Multiply(0xf6,S(x123)) ^ Multiply(0xf7,S(x122)));
											const unsigned char x188=x49 ^ Multiply(0x47,x48) ^ Multiply(0x47,x36) ^ Multiply(0x47,x32) ^ x11 ^ Multiply(0x44,x6) ^ Multiply(0xc9,x5) ^ Multiply(0xcb,x1) ^ S(x164) ^ S(x159) ^ Multiply(0x02,S(x158)) ^ Multiply(0x03,S(x153)) ^ S(x50);
											const unsigned char x193=Multiply(0xf6,x185) ^ Multiply(0xf6,x54) ^ x48 ^ Multiply(0xf6,x38) ^ x36 ^ Multiply(0xf6,x34) ^ Multiply(0xf6,x14) ^ x8 ^ Multiply(0xf6,x1) ^ Multiply(0xf4,S(x160)) ^ Multiply(0xf5,S(x155)) ^ Multiply(0xf6,S(x154)) ^ S(x49);
											const unsigned char x198=Multiply(0xcb,x48) ^ x47 ^ Multiply(0xcb,x36) ^ Multiply(0xcb,x32) ^ x31 ^ Multiply(0xc9,x6) ^ Multiply(0x44,x5) ^ Multiply(0x47,x1) ^ Multiply(0x08,x0) ^ Multiply(0x02,S(x166)) ^ Multiply(0x03,S(x161)) ^ S(x156) ^ S(x151) ^ S(x48);
											const unsigned char x2=Multiply(0x47,x48) ^ Multiply(0x47,x36) ^ Multiply(0x47,x32) ^ Multiply(0x44,x6) ^ Multiply(0xc9,x5) ^ Multiply(0xcb,x1);
											const unsigned char x3=Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1);
											const unsigned char x4=Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1);
											const unsigned char x7=x47 ^ x31 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1) ^ Multiply(0x04,x0) ^ S(x32);
											const unsigned char x9=x7 ^ Multiply(0x02,x0) ^ S(x8);
											const unsigned char x10=x36 ^ S(x33);
											const unsigned char x12=x10 ^ S(x11);
											const unsigned char x13=x49 ^ x33 ^ x2 ^ S(x34);
											const unsigned char x15=x13 ^ S(x14);
											const unsigned char x16=x38 ^ S(x31);
											const unsigned char x17=x16 ^ S(x18);
											const unsigned char x19=x31 ^ x18 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1);
											const unsigned char x20=x19 ^ x7;
											const unsigned char x21=x32 ^ x8 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1);
											const unsigned char x22=x21 ^ x10;
											const unsigned char x23=x33 ^ x11 ^ x2;
											const unsigned char x24=x23 ^ x13;
											const unsigned char x25=x34 ^ x14 ^ x1;
											const unsigned char x26=x25 ^ x16;
											const unsigned char x27=x19 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1);
											const unsigned char x28=x21 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1);
											const unsigned char x29=x23 ^ x2;
											const unsigned char x30=x25 ^ x1;
											const unsigned char x35=x47 ^ x19 ^ x18;
											const unsigned char x37=x13 ^ S(x34);
											const unsigned char x39=x47 ^ x18;
											const unsigned char x40=x36 ^ x21;
											const unsigned char x41=x23 ^ x13 ^ S(x34);
											const unsigned char x42=x46 ^ x25 ^ x1;
											const unsigned char x43=x47 ^ x19 ^ x18 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1);
											const unsigned char x44=x36 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1);
											const unsigned char x45=x13 ^ x2 ^ S(x34);
											const unsigned char x51=x47 ^ x19 ^ x18 ^ Multiply(0x08,x0) ^ S(x48);
											const unsigned char x52=x36 ^ S(x49);
											const unsigned char x53=x13 ^ S(x50) ^ S(x34);
											const unsigned char x55=x19 ^ Multiply(0x08,x0) ^ S(x48);
											const unsigned char x56=x21 ^ S(x49);
											const unsigned char x57=x23 ^ S(x50);
											const unsigned char x58=x25 ^ S(x47);
											const unsigned char x59=x47 ^ x18 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1) ^ Multiply(0x08,x0) ^ S(x48);
											const unsigned char x60=x36 ^ x21 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1) ^ S(x49);
											const unsigned char x61=x23 ^ x13 ^ x2 ^ S(x50) ^ S(x34);
											const unsigned char x62=x46 ^ x25 ^ S(x47);
											const unsigned char x67=x47 ^ x19 ^ x18 ^ Multiply(0x18,x0) ^ S(x64) ^ S(x48);
											const unsigned char x68=x36 ^ S(x65) ^ S(x49);
											const unsigned char x69=x13 ^ S(x66) ^ S(x50) ^ S(x34);
											const unsigned char x70=x46 ^ x1 ^ S(x63) ^ S(x47);
											const unsigned char x71=x47 ^ x18 ^ Multiply(0x10,x0) ^ S(x64);
											const unsigned char x72=x36 ^ x21 ^ S(x65);
											const unsigned char x73=x23 ^ x13 ^ S(x66) ^ S(x34);
											const unsigned char x74=x46 ^ x25 ^ x1 ^ S(x63);
											const unsigned char x75=Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1) ^ Multiply(0x18,x0) ^ S(x64) ^ S(x48);
											const unsigned char x76=Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1) ^ S(x65) ^ S(x49);
											const unsigned char x77=x2 ^ S(x66) ^ S(x50);
											const unsigned char x78=x1 ^ S(x63) ^ S(x47);
											const unsigned char x83=x47 ^ x19 ^ x18 ^ Multiply(0x38,x0) ^ S(x80) ^ S(x64) ^ S(x48);
											const unsigned char x85=x13 ^ S(x82) ^ S(x66) ^ S(x50) ^ S(x34);
											const unsigned char x87=x19 ^ Multiply(0x28,x0) ^ S(x80) ^ S(x48);
											const unsigned char x88=x84 ^ x36 ^ x21 ^ S(x65);
											const unsigned char x89=x23 ^ S(x82) ^ S(x50);
											const unsigned char x90=x86 ^ x46 ^ x25 ^ x1 ^ S(x63);
											const unsigned char x91=x19 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1) ^ Multiply(0x30,x0) ^ S(x80) ^ S(x64);
											const unsigned char x92=x84 ^ x36 ^ x21 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1) ^ S(x49);
											const unsigned char x93=x23 ^ x2 ^ S(x82) ^ S(x66);
											const unsigned char x94=x86 ^ x46 ^ x25 ^ S(x47);
											const unsigned char x95=x19 ^ x18 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1) ^ Multiply(0x20,x0) ^ S(x80);
											const unsigned char x96=x84 ^ x36 ^ x21 ^ x8 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1) ^ S(x65) ^ S(x49);
											const unsigned char x97=x23 ^ x11 ^ x2 ^ S(x82);
											const unsigned char x98=x86 ^ x66 ^ x46 ^ x25 ^ x1 ^ S(x63);
											const unsigned char x99=x119 ^ x25 ^ x14 ^ x1;
											const unsigned char x100=x123 ^ x23 ^ x11 ^ x2;
											const unsigned char x101=x127 ^ x21 ^ x8 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1);
											const unsigned char x102=x131 ^ x19 ^ x18 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1);
											const unsigned char x103=Multiply(0x0d,x127) ^ Multiply(0x0e,x119) ^ Multiply(0x0b,x102) ^ Multiply(0x09,x100) ^ Multiply(0x0e,x25) ^ Multiply(0x0d,x21) ^ Multiply(0x0e,x14) ^ Multiply(0x0d,x8) ^ Multiply(0xc3,x6) ^ Multiply(0x17,x5) ^ Multiply(0xb3,x2) ^ Multiply(0x64,x1);
											const unsigned char x104=x122 ^ x16;
											const unsigned char x105=x126 ^ x13;
											const unsigned char x106=x130 ^ x10;
											const unsigned char x107=x134 ^ x7;
											const unsigned char x108=Multiply(0x0d,x134) ^ Multiply(0x0e,x126) ^ Multiply(0x09,x106) ^ Multiply(0x0b,x104) ^ Multiply(0x0e,x13) ^ Multiply(0x0d,x7);
											const unsigned char x109=x121 ^ x25;
											const unsigned char x110=x125 ^ x23;
											const unsigned char x111=x129 ^ x21;
											const unsigned char x112=x133 ^ x19;
											const unsigned char x113=Multiply(0x0e,x129) ^ Multiply(0x0d,x121) ^ Multiply(0x09,x112) ^ Multiply(0x0b,x110) ^ Multiply(0x0d,x25) ^ Multiply(0x0e,x21);
											const unsigned char x114=x120 ^ x25 ^ x1;
											const unsigned char x115=x124 ^ x23 ^ x2;
											const unsigned char x116=x128 ^ x21 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1);
											const unsigned char x117=x132 ^ x19 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1);
											const unsigned char x118=Multiply(0x0e,x132) ^ Multiply(0x0d,x124) ^ Multiply(0x0b,x116) ^ Multiply(0x09,x114) ^ Multiply(0x0d,x23) ^ Multiply(0x0e,x19) ^ Multiply(0x1a,x6) ^ Multiply(0x1c,x5) ^ Multiply(0x0f,x2) ^ Multiply(0x0a,x1);
											const unsigned char x135=Multiply(0x03,S(x131)) ^ S(x130) ^ S(x125) ^ Multiply(0x02,S(x120));
											const unsigned char x136=S(x131) ^ S(x130) ^ Multiply(0x02,S(x125)) ^ Multiply(0x03,S(x120));
											const unsigned char x137=S(x131) ^ Multiply(0x02,S(x130)) ^ Multiply(0x03,S(x125)) ^ S(x120);
											const unsigned char x138=Multiply(0x02,S(x131)) ^ Multiply(0x03,S(x130)) ^ S(x125) ^ S(x120);
											const unsigned char x143=Multiply(0x03,S(x133)) ^ S(x128) ^ S(x123) ^ Multiply(0x02,S(x122));
											const unsigned char x144=S(x133) ^ S(x128) ^ Multiply(0x02,S(x123)) ^ Multiply(0x03,S(x122));
											const unsigned char x145=S(x133) ^ Multiply(0x02,S(x128)) ^ Multiply(0x03,S(x123)) ^ S(x122);
											const unsigned char x146=Multiply(0x02,S(x133)) ^ Multiply(0x03,S(x128)) ^ S(x123) ^ S(x122);
											const unsigned char x168=x187 ^ x11 ^ x2 ^ S(x50);
											const unsigned char x169=x191 ^ x8 ^ Multiply(0xba,x6) ^ Multiply(0x03,x5) ^ Multiply(0x69,x2) ^ Multiply(0xd1,x1) ^ S(x49);
											const unsigned char x170=x195 ^ x18 ^ Multiply(0x6a,x6) ^ Multiply(0x02,x5) ^ Multiply(0xd1,x2) ^ Multiply(0xb8,x1) ^ Multiply(0x08,x0) ^ S(x48);
											const unsigned char x171=Multiply(0x03,S(x164)) ^ S(x159) ^ S(x158) ^ Multiply(0x02,S(x153));
											const unsigned char x172=S(x164) ^ S(x159) ^ Multiply(0x02,S(x158)) ^ Multiply(0x03,S(x153));
											const unsigned char x173=S(x164) ^ Multiply(0x02,S(x159)) ^ Multiply(0x03,S(x158)) ^ S(x153);
											const unsigned char x174=Multiply(0x02,S(x164)) ^ Multiply(0x03,S(x159)) ^ S(x158) ^ S(x153);
											const unsigned char x175=x185 ^ x25 ^ S(x47);
											const unsigned char x176=Multiply(0xf6,x185) ^ Multiply(0xf6,x25) ^ Multiply(0xf7,S(x160)) ^ Multiply(0xf4,S(x155)) ^ Multiply(0xf4,S(x154)) ^ Multiply(0xf6,S(x47));
											const unsigned char x177=Multiply(0xf6,x185) ^ Multiply(0xf6,x25) ^ Multiply(0xf4,S(x160)) ^ Multiply(0xf5,S(x155)) ^ Multiply(0xf6,S(x154)) ^ Multiply(0xf6,S(x47));
											const unsigned char x178=Multiply(0xf7,x185) ^ Multiply(0xf7,x25) ^ Multiply(0xf4,S(x160)) ^ Multiply(0xf6,S(x155)) ^ Multiply(0xf4,S(x154)) ^ Multiply(0xf7,S(x47));
											const unsigned char x179=Multiply(0x03,S(x166)) ^ S(x161) ^ S(x156) ^ Multiply(0x02,S(x151));
											const unsigned char x180=S(x166) ^ S(x161) ^ Multiply(0x02,S(x156)) ^ Multiply(0x03,S(x151));
											const unsigned char x181=S(x166) ^ Multiply(0x02,S(x161)) ^ Multiply(0x03,S(x156)) ^ S(x151);
											const unsigned char x182=Multiply(0x02,S(x166)) ^ Multiply(0x03,S(x161)) ^ S(x156) ^ S(x151);
											const unsigned char x199=x203 ^ x66 ^ x1 ^ S(x63) ^ S(x47);
											const unsigned char x200=x204 ^ x2 ^ S(x66) ^ S(x50);
											const unsigned char x201=x205 ^ x36 ^ x21 ^ S(x65);
											const unsigned char x202=Multiply(0x02,S(x198)) ^ Multiply(0x03,S(x193)) ^ S(x188) ^ S(x183);
											const unsigned char x206=x47 ^ x19 ^ x18 ^ Multiply(0x18,x0) ^ Multiply(0x02,S(x198)) ^ Multiply(0x03,S(x193)) ^ S(x188) ^ S(x183) ^ S(x64) ^ S(x48);
											printf("# Solution found :\n");
											printf("K_0[3,2] = %02x\n",x1);
											printf("K_0[2,2] = %02x\n",x2);
											printf("K_0[1,2] = %02x\n",x3);
											printf("K_0[0,2] = %02x\n",x4);
											printf("Z_0[0,1] = %02x\n",x5);
											printf("Z_0[0,0] = %02x\n",x6);
											printf("K_1[0,0] = %02x\n",x7);
											printf("K_0[1,3] = %02x\n",x8);
											printf("K_0[0,0] = %02x\n",x9);
											printf("K_1[1,0] = %02x\n",x10);
											printf("K_0[2,3] = %02x\n",x11);
											printf("K_0[1,0] = %02x\n",x12);
											printf("K_1[2,0] = %02x\n",x13);
											printf("K_0[3,3] = %02x\n",x14);
											printf("K_0[2,0] = %02x\n",x15);
											printf("K_1[3,0] = %02x\n",x16);
											printf("K_0[3,0] = %02x\n",x17);
											printf("K_0[0,3] = %02x\n",x18);
											printf("K_1[0,1] = %02x\n",x19);
											printf("K_0[0,1] = %02x\n",x20);
											printf("K_1[1,1] = %02x\n",x21);
											printf("K_0[1,1] = %02x\n",x22);
											printf("K_1[2,1] = %02x\n",x23);
											printf("K_0[2,1] = %02x\n",x24);
											printf("K_1[3,1] = %02x\n",x25);
											printf("K_0[3,1] = %02x\n",x26);
											printf("K_1[0,2] = %02x\n",x27);
											printf("K_1[1,2] = %02x\n",x28);
											printf("K_1[2,2] = %02x\n",x29);
											printf("K_1[3,2] = %02x\n",x30);
											printf("K_1[0,3] = %02x\n",x31);
											printf("K_1[1,3] = %02x\n",x32);
											printf("K_1[2,3] = %02x\n",x33);
											printf("K_1[3,3] = %02x\n",x34);
											printf("K_2[0,0] = %02x\n",x35);
											printf("K_2[1,0] = %02x\n",x36);
											printf("K_2[2,0] = %02x\n",x37);
											printf("K_2[3,0] = %02x\n",x38);
											printf("K_2[0,1] = %02x\n",x39);
											printf("K_2[1,1] = %02x\n",x40);
											printf("K_2[2,1] = %02x\n",x41);
											printf("K_2[3,1] = %02x\n",x42);
											printf("K_2[0,2] = %02x\n",x43);
											printf("K_2[1,2] = %02x\n",x44);
											printf("K_2[2,2] = %02x\n",x45);
											printf("K_2[3,2] = %02x\n",x46);
											printf("K_2[0,3] = %02x\n",x47);
											printf("K_2[1,3] = %02x\n",x48);
											printf("K_2[2,3] = %02x\n",x49);
											printf("K_2[3,3] = %02x\n",x50);
											printf("K_3[0,0] = %02x\n",x51);
											printf("K_3[1,0] = %02x\n",x52);
											printf("K_3[2,0] = %02x\n",x53);
											printf("K_3[3,0] = %02x\n",x54);
											printf("K_3[0,1] = %02x\n",x55);
											printf("K_3[1,1] = %02x\n",x56);
											printf("K_3[2,1] = %02x\n",x57);
											printf("K_3[3,1] = %02x\n",x58);
											printf("K_3[0,2] = %02x\n",x59);
											printf("K_3[1,2] = %02x\n",x60);
											printf("K_3[2,2] = %02x\n",x61);
											printf("K_3[3,2] = %02x\n",x62);
											printf("K_3[0,3] = %02x\n",x63);
											printf("K_3[1,3] = %02x\n",x64);
											printf("K_3[2,3] = %02x\n",x65);
											printf("K_3[3,3] = %02x\n",x66);
											printf("K_4[0,0] = %02x\n",x67);
											printf("K_4[1,0] = %02x\n",x68);
											printf("K_4[2,0] = %02x\n",x69);
											printf("K_4[3,0] = %02x\n",x70);
											printf("K_4[0,1] = %02x\n",x71);
											printf("K_4[1,1] = %02x\n",x72);
											printf("K_4[2,1] = %02x\n",x73);
											printf("K_4[3,1] = %02x\n",x74);
											printf("K_4[0,2] = %02x\n",x75);
											printf("K_4[1,2] = %02x\n",x76);
											printf("K_4[2,2] = %02x\n",x77);
											printf("K_4[3,2] = %02x\n",x78);
											printf("K_4[0,3] = %02x\n",x79);
											printf("K_4[1,3] = %02x\n",x80);
											printf("K_4[2,3] = %02x\n",x81);
											printf("K_4[3,3] = %02x\n",x82);
											printf("K_5[0,0] = %02x\n",x83);
											printf("K_5[1,0] = %02x\n",x84);
											printf("K_5[2,0] = %02x\n",x85);
											printf("K_5[3,0] = %02x\n",x86);
											printf("K_5[0,1] = %02x\n",x87);
											printf("K_5[1,1] = %02x\n",x88);
											printf("K_5[2,1] = %02x\n",x89);
											printf("K_5[3,1] = %02x\n",x90);
											printf("K_5[0,2] = %02x\n",x91);
											printf("K_5[1,2] = %02x\n",x92);
											printf("K_5[2,2] = %02x\n",x93);
											printf("K_5[3,2] = %02x\n",x94);
											printf("K_5[0,3] = %02x\n",x95);
											printf("K_5[1,3] = %02x\n",x96);
											printf("K_5[2,3] = %02x\n",x97);
											printf("K_5[3,3] = %02x\n",x98);
											printf("AK_1[3,3] = %02x\n",x99);
											printf("AK_1[2,3] = %02x\n",x100);
											printf("AK_1[1,3] = %02x\n",x101);
											printf("AK_1[0,3] = %02x\n",x102);
											printf("SB_1[3,3] = %02x\n",x103);
											printf("AK_1[3,0] = %02x\n",x104);
											printf("AK_1[2,0] = %02x\n",x105);
											printf("AK_1[1,0] = %02x\n",x106);
											printf("AK_1[0,0] = %02x\n",x107);
											printf("SB_1[2,0] = %02x\n",x108);
											printf("AK_1[3,1] = %02x\n",x109);
											printf("AK_1[2,1] = %02x\n",x110);
											printf("AK_1[1,1] = %02x\n",x111);
											printf("AK_1[0,1] = %02x\n",x112);
											printf("SB_1[1,1] = %02x\n",x113);
											printf("AK_1[3,2] = %02x\n",x114);
											printf("AK_1[2,2] = %02x\n",x115);
											printf("AK_1[1,2] = %02x\n",x116);
											printf("AK_1[0,2] = %02x\n",x117);
											printf("SB_1[0,2] = %02x\n",x118);
											printf("SB_2[3,3] = %02x\n",x119);
											printf("SB_2[3,2] = %02x\n",x120);
											printf("SB_2[3,1] = %02x\n",x121);
											printf("SB_2[3,0] = %02x\n",x122);
											printf("SB_2[2,3] = %02x\n",x123);
											printf("SB_2[2,2] = %02x\n",x124);
											printf("SB_2[2,1] = %02x\n",x125);
											printf("SB_2[2,0] = %02x\n",x126);
											printf("SB_2[1,3] = %02x\n",x127);
											printf("SB_2[1,2] = %02x\n",x128);
											printf("SB_2[1,1] = %02x\n",x129);
											printf("SB_2[1,0] = %02x\n",x130);
											printf("SB_2[0,3] = %02x\n",x131);
											printf("SB_2[0,2] = %02x\n",x132);
											printf("SB_2[0,1] = %02x\n",x133);
											printf("SB_2[0,0] = %02x\n",x134);
											printf("AK_2[3,3] = %02x\n",x135);
											printf("AK_2[2,3] = %02x\n",x136);
											printf("AK_2[1,3] = %02x\n",x137);
											printf("AK_2[0,3] = %02x\n",x138);
											printf("AK_2[3,2] = %02x\n",x139);
											printf("AK_2[2,2] = %02x\n",x140);
											printf("AK_2[1,2] = %02x\n",x141);
											printf("AK_2[0,2] = %02x\n",x142);
											printf("AK_2[3,1] = %02x\n",x143);
											printf("AK_2[2,1] = %02x\n",x144);
											printf("AK_2[1,1] = %02x\n",x145);
											printf("AK_2[0,1] = %02x\n",x146);
											printf("AK_2[3,0] = %02x\n",x147);
											printf("AK_2[2,0] = %02x\n",x148);
											printf("AK_2[1,0] = %02x\n",x149);
											printf("AK_2[0,0] = %02x\n",x150);
											printf("SB_3[3,3] = %02x\n",x151);
											printf("SB_3[3,2] = %02x\n",x152);
											printf("SB_3[3,1] = %02x\n",x153);
											printf("SB_3[3,0] = %02x\n",x154);
											printf("SB_3[2,3] = %02x\n",x155);
											printf("SB_3[2,2] = %02x\n",x156);
											printf("SB_3[2,1] = %02x\n",x157);
											printf("SB_3[2,0] = %02x\n",x158);
											printf("SB_3[1,3] = %02x\n",x159);
											printf("SB_3[1,2] = %02x\n",x160);
											printf("SB_3[1,1] = %02x\n",x161);
											printf("SB_3[1,0] = %02x\n",x162);
											printf("SB_3[0,3] = %02x\n",x163);
											printf("SB_3[0,2] = %02x\n",x164);
											printf("SB_3[0,1] = %02x\n",x165);
											printf("SB_3[0,0] = %02x\n",x166);
											printf("AK_3[3,3] = %02x\n",x167);
											printf("AK_3[2,3] = %02x\n",x168);
											printf("AK_3[1,3] = %02x\n",x169);
											printf("AK_3[0,3] = %02x\n",x170);
											printf("AK_3[3,2] = %02x\n",x171);
											printf("AK_3[2,2] = %02x\n",x172);
											printf("AK_3[1,2] = %02x\n",x173);
											printf("AK_3[0,2] = %02x\n",x174);
											printf("AK_3[3,1] = %02x\n",x175);
											printf("AK_3[2,1] = %02x\n",x176);
											printf("AK_3[1,1] = %02x\n",x177);
											printf("AK_3[0,1] = %02x\n",x178);
											printf("AK_3[3,0] = %02x\n",x179);
											printf("AK_3[2,0] = %02x\n",x180);
											printf("AK_3[1,0] = %02x\n",x181);
											printf("AK_3[0,0] = %02x\n",x182);
											printf("SB_4[3,3] = %02x\n",x183);
											printf("SB_4[3,2] = %02x\n",x184);
											printf("SB_4[3,1] = %02x\n",x185);
											printf("SB_4[3,0] = %02x\n",x186);
											printf("SB_4[2,3] = %02x\n",x187);
											printf("SB_4[2,2] = %02x\n",x188);
											printf("SB_4[2,1] = %02x\n",x189);
											printf("SB_4[2,0] = %02x\n",x190);
											printf("SB_4[1,3] = %02x\n",x191);
											printf("SB_4[1,2] = %02x\n",x192);
											printf("SB_4[1,1] = %02x\n",x193);
											printf("SB_4[1,0] = %02x\n",x194);
											printf("SB_4[0,3] = %02x\n",x195);
											printf("SB_4[0,2] = %02x\n",x196);
											printf("SB_4[0,1] = %02x\n",x197);
											printf("SB_4[0,0] = %02x\n",x198);
											printf("AK_4[3,3] = %02x\n",x199);
											printf("AK_4[2,2] = %02x\n",x200);
											printf("AK_4[1,1] = %02x\n",x201);
											printf("AK_4[0,0] = %02x\n",x202);
											printf("SB_5[3,3] = %02x\n",x203);
											printf("SB_5[2,2] = %02x\n",x204);
											printf("SB_5[1,1] = %02x\n",x205);
											printf("SB_5[0,0] = %02x\n",x206);
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
	int j_13;
	for (j_13 = 1; j_13 <= Alloue_13; j_13++) free(espace_13[j_13]);
	free(L_13);
}

int Generator(unsigned char Known[27]/*, unsigned char y[207]*/)
{
	const unsigned char x0=1;
	const unsigned char x47=1+(rand()%255);
	const unsigned char x48=1+(rand()%255);
	const unsigned char x49=1+(rand()%255);
	const unsigned char x50=1+(rand()%255);
	const unsigned char x63=1+(rand()%255);
	const unsigned char x64=1+(rand()%255);
	const unsigned char x65=1+(rand()%255);
	const unsigned char x66=1+(rand()%255);
	const unsigned char x151=1+(rand()%255);
	const unsigned char x152=1+(rand()%255);
	const unsigned char x153=1+(rand()%255);
	const unsigned char x154=1+(rand()%255);
	const unsigned char x155=1+(rand()%255);
	const unsigned char x156=1+(rand()%255);
	const unsigned char x157=1+(rand()%255);
	const unsigned char x158=1+(rand()%255);
	const unsigned char x159=1+(rand()%255);
	const unsigned char x160=1+(rand()%255);
	const unsigned char x161=1+(rand()%255);
	const unsigned char x162=1+(rand()%255);
	const unsigned char x163=1+(rand()%255);
	const unsigned char x164=1+(rand()%255);
	const unsigned char x165=1+(rand()%255);
	const unsigned char x166=1+(rand()%255);
	const unsigned char x8=1+(rand()%255);
	const unsigned char x11=1+(rand()%255);
	const unsigned char x14=1+(rand()%255);
	const unsigned char x18=1+(rand()%255);
	const unsigned char x31=1+(rand()%255);
	const unsigned char x32=1+(rand()%255);
	const unsigned char x33=1+(rand()%255);
	const unsigned char x34=1+(rand()%255);
	const unsigned char x79=x18 ^ Multiply(0x10,x0) ^ S(x64);
	const unsigned char x80=x8 ^ S(x65);
	const unsigned char x81=x11 ^ S(x66);
	const unsigned char x82=x14 ^ S(x63);
	const unsigned char x119=R(Multiply(0x0b,x166) ^ Multiply(0x0d,x162) ^ Multiply(0x09,x158) ^ Multiply(0x0e,x154) ^ Multiply(0x0e,x66) ^ Multiply(0x09,x65) ^ Multiply(0x0d,x64) ^ Multiply(0x0b,x63) ^ Multiply(0x0e,x50) ^ Multiply(0x09,x49) ^ Multiply(0x0d,x48) ^ Multiply(0x0b,x47) ^ Multiply(0x0e,x34) ^ Multiply(0x09,x33) ^ Multiply(0x0d,x32) ^ Multiply(0x0b,x31) ^ Multiply(0x0b,x18) ^ Multiply(0x0e,x14) ^ Multiply(0x09,x11) ^ Multiply(0x0d,x8) ^ Multiply(0x58,x0) ^ Multiply(0x09,S(x50)) ^ Multiply(0x0d,S(x49)) ^ Multiply(0x0b,S(x48)) ^ Multiply(0x0e,S(x47)));
	const unsigned char x120=R(Multiply(0x0b,x163) ^ Multiply(0x0d,x159) ^ Multiply(0x09,x155) ^ Multiply(0x0e,x151) ^ Multiply(0x0e,x50) ^ Multiply(0x09,x49) ^ Multiply(0x0d,x48) ^ Multiply(0x0b,x47));
	const unsigned char x121=R(Multiply(0x0b,x164) ^ Multiply(0x0d,x160) ^ Multiply(0x09,x156) ^ Multiply(0x0e,x152) ^ Multiply(0x0e,x50) ^ Multiply(0x09,x49) ^ Multiply(0x0d,x48) ^ Multiply(0x0b,x47) ^ Multiply(0x0e,x34) ^ Multiply(0x09,x33) ^ Multiply(0x0d,x32) ^ Multiply(0x0b,x31));
	const unsigned char x122=R(Multiply(0x0b,x165) ^ Multiply(0x0d,x161) ^ Multiply(0x09,x157) ^ Multiply(0x0e,x153) ^ Multiply(0x0e,x50) ^ Multiply(0x09,x49) ^ Multiply(0x0d,x48) ^ Multiply(0x0b,x47) ^ Multiply(0x0b,x18) ^ Multiply(0x0e,x14) ^ Multiply(0x09,x11) ^ Multiply(0x0d,x8));
	const unsigned char x123=R(Multiply(0x9b,x161) ^ Multiply(0x76,x157) ^ Multiply(0x5b,x153) ^ Multiply(0x5b,x50) ^ Multiply(0x76,x49) ^ Multiply(0x9b,x48) ^ Multiply(0x5b,x14) ^ Multiply(0x76,x11) ^ Multiply(0x9b,x8) ^ Multiply(0xb7,S(x122)));
	const unsigned char x124=R(Multiply(0x9b,x162) ^ Multiply(0x76,x158) ^ Multiply(0x5b,x154) ^ Multiply(0x5b,x66) ^ Multiply(0x76,x65) ^ Multiply(0x9b,x64) ^ Multiply(0x5b,x50) ^ Multiply(0x76,x49) ^ Multiply(0x9b,x48) ^ Multiply(0x5b,x34) ^ Multiply(0x76,x33) ^ Multiply(0x9b,x32) ^ Multiply(0x5b,x14) ^ Multiply(0x76,x11) ^ Multiply(0x9b,x8) ^ Multiply(0xb7,S(x119)) ^ Multiply(0x76,S(x50)) ^ Multiply(0x9b,S(x49)) ^ Multiply(0x5b,S(x47)));
	const unsigned char x125=R(Multiply(0x9b,x159) ^ Multiply(0x76,x155) ^ Multiply(0x5b,x151) ^ Multiply(0x5b,x50) ^ Multiply(0x76,x49) ^ Multiply(0x9b,x48) ^ Multiply(0xb7,S(x120)));
	const unsigned char x126=R(Multiply(0x9b,x160) ^ Multiply(0x76,x156) ^ Multiply(0x5b,x152) ^ Multiply(0x5b,x50) ^ Multiply(0x76,x49) ^ Multiply(0x9b,x48) ^ Multiply(0x5b,x34) ^ Multiply(0x76,x33) ^ Multiply(0x9b,x32) ^ Multiply(0xb7,S(x121)));
	const unsigned char x127=R(Multiply(0x8c,x156) ^ Multiply(0x8d,x152) ^ Multiply(0x8d,x50) ^ Multiply(0x8c,x49) ^ Multiply(0x8d,x34) ^ Multiply(0x8c,x33) ^ Multiply(0x8e,S(x126)) ^ Multiply(0x8e,S(x121)));
	const unsigned char x128=R(Multiply(0x8c,x157) ^ Multiply(0x8d,x153) ^ Multiply(0x8d,x50) ^ Multiply(0x8c,x49) ^ Multiply(0x8d,x14) ^ Multiply(0x8c,x11) ^ Multiply(0x8e,S(x123)) ^ Multiply(0x8e,S(x122)));
	const unsigned char x129=R(Multiply(0x8c,x158) ^ Multiply(0x8d,x154) ^ Multiply(0x8d,x66) ^ Multiply(0x8c,x65) ^ Multiply(0x8d,x50) ^ Multiply(0x8c,x49) ^ Multiply(0x8d,x34) ^ Multiply(0x8c,x33) ^ Multiply(0x8d,x14) ^ Multiply(0x8c,x11) ^ Multiply(0x8e,S(x124)) ^ Multiply(0x8e,S(x119)) ^ Multiply(0x8c,S(x50)) ^ Multiply(0x8d,S(x47)));
	const unsigned char x130=R(Multiply(0x8c,x155) ^ Multiply(0x8d,x151) ^ Multiply(0x8d,x50) ^ Multiply(0x8c,x49) ^ Multiply(0x8e,S(x125)) ^ Multiply(0x8e,S(x120)));
	const unsigned char x131=R(Multiply(0xf6,x151) ^ Multiply(0xf6,x50) ^ Multiply(0xf6,S(x130)) ^ Multiply(0xf6,S(x125)) ^ Multiply(0xf7,S(x120)));
	const unsigned char x132=R(Multiply(0xf6,x152) ^ Multiply(0xf6,x50) ^ Multiply(0xf6,x34) ^ Multiply(0xf6,S(x127)) ^ Multiply(0xf6,S(x126)) ^ Multiply(0xf7,S(x121)));
	const unsigned char x133=R(Multiply(0xf6,x153) ^ Multiply(0xf6,x50) ^ Multiply(0xf6,x14) ^ Multiply(0xf6,S(x128)) ^ Multiply(0xf6,S(x123)) ^ Multiply(0xf7,S(x122)));
	const unsigned char x134=R(Multiply(0xf6,x154) ^ Multiply(0xf6,x66) ^ Multiply(0xf6,x50) ^ Multiply(0xf6,x34) ^ Multiply(0xf6,x14) ^ Multiply(0xf6,S(x129)) ^ Multiply(0xf6,S(x124)) ^ Multiply(0xf7,S(x119)) ^ Multiply(0xf6,S(x47)));
	const unsigned char x183=x66 ^ Multiply(0x03,S(x163)) ^ S(x162) ^ S(x157) ^ Multiply(0x02,S(x152));
	const unsigned char x184=x66 ^ x50 ^ Multiply(0x03,S(x164)) ^ S(x159) ^ S(x158) ^ Multiply(0x02,S(x153));
	const unsigned char x185=x66 ^ x34 ^ Multiply(0x03,S(x165)) ^ S(x160) ^ S(x155) ^ Multiply(0x02,S(x154));
	const unsigned char x186=x66 ^ x50 ^ x34 ^ x14 ^ Multiply(0x03,S(x166)) ^ S(x161) ^ S(x156) ^ Multiply(0x02,S(x151));
	const unsigned char x187=x65 ^ S(x163) ^ S(x162) ^ Multiply(0x02,S(x157)) ^ Multiply(0x03,S(x152));
	const unsigned char x188=x65 ^ x49 ^ S(x164) ^ S(x159) ^ Multiply(0x02,S(x158)) ^ Multiply(0x03,S(x153));
	const unsigned char x189=x65 ^ x33 ^ S(x165) ^ S(x160) ^ Multiply(0x02,S(x155)) ^ Multiply(0x03,S(x154));
	const unsigned char x190=x65 ^ x49 ^ x33 ^ x11 ^ S(x166) ^ S(x161) ^ Multiply(0x02,S(x156)) ^ Multiply(0x03,S(x151));
	const unsigned char x191=x64 ^ S(x163) ^ Multiply(0x02,S(x162)) ^ Multiply(0x03,S(x157)) ^ S(x152);
	const unsigned char x192=x64 ^ x48 ^ S(x164) ^ Multiply(0x02,S(x159)) ^ Multiply(0x03,S(x158)) ^ S(x153);
	const unsigned char x193=x64 ^ x32 ^ S(x165) ^ Multiply(0x02,S(x160)) ^ Multiply(0x03,S(x155)) ^ S(x154);
	const unsigned char x194=x64 ^ x48 ^ x32 ^ x8 ^ S(x166) ^ Multiply(0x02,S(x161)) ^ Multiply(0x03,S(x156)) ^ S(x151);
	const unsigned char x195=x63 ^ Multiply(0x02,S(x163)) ^ Multiply(0x03,S(x162)) ^ S(x157) ^ S(x152);
	const unsigned char x196=x63 ^ x47 ^ Multiply(0x02,S(x164)) ^ Multiply(0x03,S(x159)) ^ S(x158) ^ S(x153);
	const unsigned char x197=x63 ^ x31 ^ Multiply(0x02,S(x165)) ^ Multiply(0x03,S(x160)) ^ S(x155) ^ S(x154);
	const unsigned char x198=x63 ^ x47 ^ x31 ^ x18 ^ Multiply(0x02,S(x166)) ^ Multiply(0x03,S(x161)) ^ S(x156) ^ S(x151);
	const unsigned char x206=x63 ^ x47 ^ x31 ^ x18 ^ Multiply(0x10,x0) ^ Multiply(0x02,S(x198)) ^ Multiply(0x03,S(x193)) ^ S(x188) ^ S(x183) ^ S(x64);
	const unsigned char x1=x66 ^ x14 ^ S(x47);
	const unsigned char x2=x65 ^ x11 ^ S(x50);
	const unsigned char x3=x64 ^ x8 ^ S(x49);
	const unsigned char x4=x63 ^ x18 ^ Multiply(0x08,x0) ^ S(x48);
	const unsigned char x5=Multiply(0x0b,x4) ^ Multiply(0x0d,x3) ^ Multiply(0x09,x2) ^ Multiply(0x0e,x1);
	const unsigned char x6=Multiply(0x09,x4) ^ Multiply(0x0e,x3) ^ Multiply(0x0b,x2) ^ Multiply(0x0d,x1);
	const unsigned char x7=x47 ^ x31 ^ x4 ^ Multiply(0x04,x0) ^ S(x32);
	const unsigned char x9=x7 ^ Multiply(0x02,x0) ^ S(x8);
	const unsigned char x10=x48 ^ x32 ^ x3 ^ S(x33);
	const unsigned char x12=x10 ^ S(x11);
	const unsigned char x13=x49 ^ x33 ^ x2 ^ S(x34);
	const unsigned char x15=x13 ^ S(x14);
	const unsigned char x16=x50 ^ x34 ^ x1 ^ S(x31);
	const unsigned char x17=x16 ^ S(x18);
	const unsigned char x19=x31 ^ x18 ^ x4;
	const unsigned char x20=x19 ^ x7;
	const unsigned char x21=x32 ^ x8 ^ x3;
	const unsigned char x22=x21 ^ x10;
	const unsigned char x23=x33 ^ x11 ^ x2;
	const unsigned char x24=x23 ^ x13;
	const unsigned char x25=x34 ^ x14 ^ x1;
	const unsigned char x26=x25 ^ x16;
	const unsigned char x27=x19 ^ x4;
	const unsigned char x28=x21 ^ x3;
	const unsigned char x29=x23 ^ x2;
	const unsigned char x30=x25 ^ x1;
	const unsigned char x35=x7 ^ Multiply(0x04,x0) ^ S(x32);
	const unsigned char x36=x10 ^ S(x33);
	const unsigned char x37=x13 ^ S(x34);
	const unsigned char x38=x16 ^ S(x31);
	const unsigned char x39=x19 ^ x7 ^ Multiply(0x04,x0) ^ S(x32);
	const unsigned char x40=x21 ^ x10 ^ S(x33);
	const unsigned char x41=x23 ^ x13 ^ S(x34);
	const unsigned char x42=x25 ^ x16 ^ S(x31);
	const unsigned char x43=x7 ^ x4 ^ Multiply(0x04,x0) ^ S(x32);
	const unsigned char x44=x10 ^ x3 ^ S(x33);
	const unsigned char x45=x13 ^ x2 ^ S(x34);
	const unsigned char x46=x16 ^ x1 ^ S(x31);
	const unsigned char x51=x7 ^ Multiply(0x0c,x0) ^ S(x48) ^ S(x32);
	const unsigned char x52=x10 ^ S(x49) ^ S(x33);
	const unsigned char x53=x13 ^ S(x50) ^ S(x34);
	const unsigned char x54=x16 ^ S(x47) ^ S(x31);
	const unsigned char x55=x19 ^ Multiply(0x08,x0) ^ S(x48);
	const unsigned char x56=x21 ^ S(x49);
	const unsigned char x57=x23 ^ S(x50);
	const unsigned char x58=x25 ^ S(x47);
	const unsigned char x59=x19 ^ x7 ^ x4 ^ Multiply(0x0c,x0) ^ S(x48) ^ S(x32);
	const unsigned char x60=x21 ^ x10 ^ x3 ^ S(x49) ^ S(x33);
	const unsigned char x61=x23 ^ x13 ^ x2 ^ S(x50) ^ S(x34);
	const unsigned char x62=x25 ^ x16 ^ x1 ^ S(x47) ^ S(x31);
	const unsigned char x67=x7 ^ Multiply(0x1c,x0) ^ S(x64) ^ S(x48) ^ S(x32);
	const unsigned char x68=x10 ^ S(x65) ^ S(x49) ^ S(x33);
	const unsigned char x69=x13 ^ S(x66) ^ S(x50) ^ S(x34);
	const unsigned char x70=x16 ^ S(x63) ^ S(x47) ^ S(x31);
	const unsigned char x71=x19 ^ x7 ^ Multiply(0x14,x0) ^ S(x64) ^ S(x32);
	const unsigned char x72=x21 ^ x10 ^ S(x65) ^ S(x33);
	const unsigned char x73=x23 ^ x13 ^ S(x66) ^ S(x34);
	const unsigned char x74=x25 ^ x16 ^ S(x63) ^ S(x31);
	const unsigned char x75=x4 ^ Multiply(0x18,x0) ^ S(x64) ^ S(x48);
	const unsigned char x76=x3 ^ S(x65) ^ S(x49);
	const unsigned char x77=x2 ^ S(x66) ^ S(x50);
	const unsigned char x78=x1 ^ S(x63) ^ S(x47);
	const unsigned char x83=x7 ^ Multiply(0x3c,x0) ^ S(x80) ^ S(x64) ^ S(x48) ^ S(x32);
	const unsigned char x84=x10 ^ S(x81) ^ S(x65) ^ S(x49) ^ S(x33);
	const unsigned char x85=x13 ^ S(x82) ^ S(x66) ^ S(x50) ^ S(x34);
	const unsigned char x86=x16 ^ S(x79) ^ S(x63) ^ S(x47) ^ S(x31);
	const unsigned char x87=x19 ^ Multiply(0x28,x0) ^ S(x80) ^ S(x48);
	const unsigned char x88=x21 ^ S(x81) ^ S(x49);
	const unsigned char x89=x23 ^ S(x82) ^ S(x50);
	const unsigned char x90=x25 ^ S(x79) ^ S(x47);
	const unsigned char x91=x19 ^ x4 ^ Multiply(0x30,x0) ^ S(x80) ^ S(x64);
	const unsigned char x92=x21 ^ x3 ^ S(x81) ^ S(x65);
	const unsigned char x93=x23 ^ x2 ^ S(x82) ^ S(x66);
	const unsigned char x94=x25 ^ x1 ^ S(x79) ^ S(x63);
	const unsigned char x95=x19 ^ x18 ^ x4 ^ Multiply(0x20,x0) ^ S(x80);
	const unsigned char x96=x21 ^ x8 ^ x3 ^ S(x81);
	const unsigned char x97=x23 ^ x11 ^ x2 ^ S(x82);
	const unsigned char x98=x25 ^ x14 ^ x1 ^ S(x79);
	const unsigned char x99=x119 ^ x25 ^ x14 ^ x1;
	const unsigned char x100=x123 ^ x23 ^ x11 ^ x2;
	const unsigned char x101=x127 ^ x21 ^ x8 ^ x3;
	const unsigned char x102=x131 ^ x19 ^ x18 ^ x4;
	const unsigned char x103=Multiply(0x0b,x102) ^ Multiply(0x0d,x101) ^ Multiply(0x09,x100) ^ Multiply(0x0e,x99);
	const unsigned char x104=x122 ^ x16;
	const unsigned char x105=x126 ^ x13;
	const unsigned char x106=x130 ^ x10;
	const unsigned char x107=x134 ^ x7;
	const unsigned char x108=Multiply(0x0d,x107) ^ Multiply(0x09,x106) ^ Multiply(0x0e,x105) ^ Multiply(0x0b,x104);
	const unsigned char x109=x121 ^ x25;
	const unsigned char x110=x125 ^ x23;
	const unsigned char x111=x129 ^ x21;
	const unsigned char x112=x133 ^ x19;
	const unsigned char x113=Multiply(0x09,x112) ^ Multiply(0x0e,x111) ^ Multiply(0x0b,x110) ^ Multiply(0x0d,x109);
	const unsigned char x114=x120 ^ x25 ^ x1;
	const unsigned char x115=x124 ^ x23 ^ x2;
	const unsigned char x116=x128 ^ x21 ^ x3;
	const unsigned char x117=x132 ^ x19 ^ x4;
	const unsigned char x118=Multiply(0x0e,x117) ^ Multiply(0x0b,x116) ^ Multiply(0x0d,x115) ^ Multiply(0x09,x114);
	const unsigned char x135=Multiply(0x03,S(x131)) ^ S(x130) ^ S(x125) ^ Multiply(0x02,S(x120));
	const unsigned char x136=S(x131) ^ S(x130) ^ Multiply(0x02,S(x125)) ^ Multiply(0x03,S(x120));
	const unsigned char x137=S(x131) ^ Multiply(0x02,S(x130)) ^ Multiply(0x03,S(x125)) ^ S(x120);
	const unsigned char x138=Multiply(0x02,S(x131)) ^ Multiply(0x03,S(x130)) ^ S(x125) ^ S(x120);
	const unsigned char x139=Multiply(0x03,S(x132)) ^ S(x127) ^ S(x126) ^ Multiply(0x02,S(x121));
	const unsigned char x140=S(x132) ^ S(x127) ^ Multiply(0x02,S(x126)) ^ Multiply(0x03,S(x121));
	const unsigned char x141=S(x132) ^ Multiply(0x02,S(x127)) ^ Multiply(0x03,S(x126)) ^ S(x121);
	const unsigned char x142=Multiply(0x02,S(x132)) ^ Multiply(0x03,S(x127)) ^ S(x126) ^ S(x121);
	const unsigned char x143=Multiply(0x03,S(x133)) ^ S(x128) ^ S(x123) ^ Multiply(0x02,S(x122));
	const unsigned char x144=S(x133) ^ S(x128) ^ Multiply(0x02,S(x123)) ^ Multiply(0x03,S(x122));
	const unsigned char x145=S(x133) ^ Multiply(0x02,S(x128)) ^ Multiply(0x03,S(x123)) ^ S(x122);
	const unsigned char x146=Multiply(0x02,S(x133)) ^ Multiply(0x03,S(x128)) ^ S(x123) ^ S(x122);
	const unsigned char x147=Multiply(0x03,S(x134)) ^ S(x129) ^ S(x124) ^ Multiply(0x02,S(x119));
	const unsigned char x148=S(x134) ^ S(x129) ^ Multiply(0x02,S(x124)) ^ Multiply(0x03,S(x119));
	const unsigned char x149=S(x134) ^ Multiply(0x02,S(x129)) ^ Multiply(0x03,S(x124)) ^ S(x119);
	const unsigned char x150=Multiply(0x02,S(x134)) ^ Multiply(0x03,S(x129)) ^ S(x124) ^ S(x119);
	const unsigned char x167=Multiply(0x03,S(x163)) ^ S(x162) ^ S(x157) ^ Multiply(0x02,S(x152));
	const unsigned char x168=S(x163) ^ S(x162) ^ Multiply(0x02,S(x157)) ^ Multiply(0x03,S(x152));
	const unsigned char x169=S(x163) ^ Multiply(0x02,S(x162)) ^ Multiply(0x03,S(x157)) ^ S(x152);
	const unsigned char x170=Multiply(0x02,S(x163)) ^ Multiply(0x03,S(x162)) ^ S(x157) ^ S(x152);
	const unsigned char x171=Multiply(0x03,S(x164)) ^ S(x159) ^ S(x158) ^ Multiply(0x02,S(x153));
	const unsigned char x172=S(x164) ^ S(x159) ^ Multiply(0x02,S(x158)) ^ Multiply(0x03,S(x153));
	const unsigned char x173=S(x164) ^ Multiply(0x02,S(x159)) ^ Multiply(0x03,S(x158)) ^ S(x153);
	const unsigned char x174=Multiply(0x02,S(x164)) ^ Multiply(0x03,S(x159)) ^ S(x158) ^ S(x153);
	const unsigned char x175=Multiply(0x03,S(x165)) ^ S(x160) ^ S(x155) ^ Multiply(0x02,S(x154));
	const unsigned char x176=S(x165) ^ S(x160) ^ Multiply(0x02,S(x155)) ^ Multiply(0x03,S(x154));
	const unsigned char x177=S(x165) ^ Multiply(0x02,S(x160)) ^ Multiply(0x03,S(x155)) ^ S(x154);
	const unsigned char x178=Multiply(0x02,S(x165)) ^ Multiply(0x03,S(x160)) ^ S(x155) ^ S(x154);
	const unsigned char x179=Multiply(0x03,S(x166)) ^ S(x161) ^ S(x156) ^ Multiply(0x02,S(x151));
	const unsigned char x180=S(x166) ^ S(x161) ^ Multiply(0x02,S(x156)) ^ Multiply(0x03,S(x151));
	const unsigned char x181=S(x166) ^ Multiply(0x02,S(x161)) ^ Multiply(0x03,S(x156)) ^ S(x151);
	const unsigned char x182=Multiply(0x02,S(x166)) ^ Multiply(0x03,S(x161)) ^ S(x156) ^ S(x151);
	const unsigned char x199=Multiply(0x03,S(x195)) ^ S(x194) ^ S(x189) ^ Multiply(0x02,S(x184));
	const unsigned char x200=S(x196) ^ S(x191) ^ Multiply(0x02,S(x190)) ^ Multiply(0x03,S(x185));
	const unsigned char x201=S(x197) ^ Multiply(0x02,S(x192)) ^ Multiply(0x03,S(x187)) ^ S(x186);
	const unsigned char x202=Multiply(0x02,S(x198)) ^ Multiply(0x03,S(x193)) ^ S(x188) ^ S(x183);
	const unsigned char x203=x14 ^ Multiply(0x03,S(x195)) ^ S(x194) ^ S(x189) ^ Multiply(0x02,S(x184)) ^ S(x63);
	const unsigned char x204=x2 ^ S(x196) ^ S(x191) ^ Multiply(0x02,S(x190)) ^ Multiply(0x03,S(x185)) ^ S(x66) ^ S(x50);
	const unsigned char x205=x21 ^ x10 ^ S(x197) ^ Multiply(0x02,S(x192)) ^ Multiply(0x03,S(x187)) ^ S(x186) ^ S(x65) ^ S(x33);
	Known[0]=x0; /* 1 */
	Known[1]=x205; /* SB_5[1,1] */
	Known[2]=x203; /* SB_5[3,3] */
	Known[3]=x204; /* SB_5[2,2] */
	Known[4]=x187; /* SB_4[2,3] */
	Known[5]=x191; /* SB_4[1,3] */
	Known[6]=x195; /* SB_4[0,3] */
	Known[7]=x185; /* SB_4[3,1] */
	Known[8]=x167; /* AK_3[3,3] */
	Known[9]=x119; /* SB_2[3,3] */
	Known[10]=x121; /* SB_2[3,1] */
	Known[11]=x124; /* SB_2[2,2] */
	Known[12]=x126; /* SB_2[2,0] */
	Known[13]=x127; /* SB_2[1,3] */
	Known[14]=x129; /* SB_2[1,1] */
	Known[15]=x132; /* SB_2[0,2] */
	Known[16]=x134; /* SB_2[0,0] */
	Known[17]=x5; /* Z_0[0,1] */
	Known[18]=x6; /* Z_0[0,0] */
	Known[19]=x86; /* K_5[3,0] */
	Known[20]=x84; /* K_5[1,0] */
	Known[21]=x47; /* K_2[0,3] */
	Known[22]=x46; /* K_2[3,2] */
	Known[23]=x36; /* K_2[1,0] */
	Known[24]=x66; /* K_3[3,3] */
	Known[25]=x14; /* K_0[3,3] */
	Known[26]=x1; /* K_0[3,2] */
	return 1;
	return 0;
}

int main(int argc, char** argv)
{
	unsigned char Known[27];
   srand(getpid()); /* Init PRNG */
	MakeTableMul2_8();
	/* assign values */
	Generator(Known);
	/* Attack */
	Attack(Known);
	return 0;
}
