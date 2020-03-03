#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <vector>
using namespace std;

class BMPHeader {
private:
	char bufferHeader[54];
	void unPack();
	void init();
public:
	//header
	char BmpType[3];
	uint32_t BmpSize;
	uint16_t RESERVED1;
	uint16_t RESERVED2;
	uint32_t OFFSET;
	//info header
	uint32_t size_ih;
	uint32_t with_ih;
	uint32_t heght_ih;
	uint16_t planes_ih;
	uint16_t bit_count_ih;
	uint32_t compression_ih;
	uint32_t imageSize_ih;
	uint32_t XpixelsPerM_ih;
	uint32_t YpixelsPerM_ih;
	uint32_t ColorUsed_ih;
	uint32_t ColorImportant_ih;
	//color table
	uint16_t red;
	uint16_t blue;
	uint16_t green;

	BMPHeader();
	void setHeaderBuffer(const char *);
	BMPHeader(const char *);
};

class MyBMP {
private:
	char *file_name;
	char buffer[54];
	ifstream file_bmp;
	BMPHeader bmp_header;
	void ReadHeader();
	vector <uint16_t> RGB;

public:
	void OpenBmp(const char * filename);
	void printHeader();

};