#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <vector>
using namespace std;

#pragma pack(push, 1)
struct BMP_HEADER {
	//header 0-13
	char BMP_TYPE[2];
	uint32_t SIZE;//4
	uint16_t RESERVED1;//2
	uint16_t RESERVED2;
	uint32_t OFFSET;
	//info header 14-40
	uint32_t size_ih;
	uint32_t with_ih;
	uint32_t heght_ih;
	uint16_t planes_ih;//2
	uint16_t bit_count_ih;//2
	uint32_t compression_ih;
	uint32_t imageSize_ih;
	uint32_t XpixelsPerM_ih;
	uint32_t YpixelsPerM_ih;
	uint32_t ColorUsed_ih;
	uint32_t ColorImportant_ih;
};
#pragma pack(pop)

struct RGB_Color {
	int red;
	int green;
	int blue;
};


class MyBMP {
private:
	//info color
	/*unsigned short red;
	unsigned short green;
	unsigned short blue;
	unsigned short reserved;*/
	
	char *file_name;
	ifstream file_bmp;
	BMP_HEADER reg_header;
	//BMP_COLOR *color_RGB;

	void ReadHeader();

public:
	vector <int> vectorRgb;
	int red;
	int green;
	int blue;
	int reserved;
	//void estructColorRGB(const char*);
	void OpenBmp(const char * );
	void PrintHeader();
};