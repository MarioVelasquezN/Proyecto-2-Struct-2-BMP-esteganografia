#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <cstring>
#include "mybmp.h"

using namespace std;

void MyBMP::ReadHeader() {
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char *)&reg_header, sizeof(reg_header));

}

void MyBMP::OpenBmp(const char * filename) {
	file_name = (char *)filename;
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	ReadHeader();
	
}

void MyBMP::PrintHeader() {
	char type[3];
	
	type[0] = reg_header.BMP_TYPE[0];
	type[1] = reg_header.BMP_TYPE[1];
	type[2] = '\0';
	
	cout << "*********************Header***********************" << endl;
	cout << "Tipo: " << type << endl;
	cout << "Size: " << reg_header.SIZE << endl;
	cout << "Reservado 1: " << reg_header.RESERVED1 << endl;
	cout << "Reservado 2: " << reg_header.RESERVED2 << endl;
	cout << "Offset: " << reg_header.OFFSET << endl;
	cout << "*****************Info Header************************" << endl;
	cout << "Size: " << reg_header.size_ih << endl;
	cout << "Width: " << reg_header.with_ih << endl;
	cout << "heght: " << reg_header.heght_ih << endl;
	cout << "Plane: " << reg_header.planes_ih << endl;
	cout << "Bit count: " << reg_header.bit_count_ih << endl;
	cout << "Compression: " << reg_header.compression_ih << endl;
	cout << "Imagen Size: " << reg_header.imageSize_ih << endl;
	cout << "XpixelsPerM: " << reg_header.XpixelsPerM_ih << endl;
	cout << "YPixelsPerM: " << reg_header.YpixelsPerM_ih << endl;
	cout << "ColorUsed: " << reg_header.ColorUsed_ih << endl;
	cout << "ColorImportant: " << reg_header.ColorImportant_ih << endl;
	cout << "******************Color Table**************************" << endl;
	
	file_bmp.seekg(reg_header.OFFSET);
	static const int umbral = 90;
	static const int reduccionX = 6, reduccionY = 4;
	static unsigned char colores[9] = " bgfrRGB";
	unsigned char* imgn=0;
	for (uint32_t i = reg_header.heght_ih; i > 0; i--)
	{
		for (uint32_t j = 0; j < reg_header.with_ih; j++)
		{

			file_bmp.read((char*)&red, sizeof(char));
			file_bmp.read((char*)&green, sizeof(char));
			file_bmp.read((char*)&blue, sizeof(char));
			vectorRgb.push_back(red);
			vectorRgb.push_back(green);
			vectorRgb.push_back(blue);
		}
	}
}