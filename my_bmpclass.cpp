#include "my_bmp.h"

using namespace std;

void MyBMP::ReadHeader() {
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read(buffer, sizeof(buffer));
	bmp_header.setHeaderBuffer(buffer);
}

void MyBMP::OpenBmp(const char * filename) {
	file_name = (char *)filename;
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	ReadHeader();
}

void MyBMP::printHeader() {
	cout << "************Header********************" << endl;
	cout << "Tipo: " << bmp_header.BmpType << endl;
	cout << "Size: " << bmp_header.BmpSize << endl;
	cout << "Reserved1: " << bmp_header.RESERVED1 << endl;
	cout << "Reserved2: " << bmp_header.RESERVED2 << endl;
	cout << "DataOffset: " << bmp_header.OFFSET << endl;
	cout << "***************Info Header*****************" << endl;
	cout << "Size: " << bmp_header.size_ih << endl;
	cout << "Width: " << bmp_header.with_ih << endl;
	cout << "heght: " << bmp_header.heght_ih << endl;
	cout << "Plane: " << bmp_header.planes_ih << endl;
	cout << "Bit count: " << bmp_header.bit_count_ih << endl;
	cout << "Compression: " << bmp_header.compression_ih << endl;
	cout << "Imagen Size: " << bmp_header.imageSize_ih << endl;
	cout << "XpixelsPerM: " << bmp_header.XpixelsPerM_ih << endl;
	cout << "YPixelsPerM: " << bmp_header.YpixelsPerM_ih << endl;
	cout << "ColorUsed: " << bmp_header.ColorUsed_ih << endl;
	cout << "ColorImportant: " << bmp_header.ColorImportant_ih << endl;
	cout << "******************COLOR TABLE**************************" << endl;

	for (uint32_t i = bmp_header.with_ih; i > 0; i--)
	{
		for (uint32_t z = 0; z < bmp_header.heght_ih; z++)
		{
			file_bmp.read((char*)&bmp_header.red, sizeof(char));
			file_bmp.read((char*)&bmp_header.green, sizeof(char));
			file_bmp.read((char*)&bmp_header.blue, sizeof(char));
			RGB.push_back(bmp_header.red);
			RGB.push_back(bmp_header.green);
			RGB.push_back(bmp_header.blue);
			cout << "RED GREEN BLUE :" << bmp_header.red <<" "<< bmp_header.green <<" "<<bmp_header.blue<<endl;
		}
	}

}

BMPHeader::BMPHeader() {
	init();
}

BMPHeader::BMPHeader(const char* buffer) {
	setHeaderBuffer(buffer);
	unPack();
}

void BMPHeader::setHeaderBuffer(const char* buffer) {
	memcpy(bufferHeader, buffer, 54);
	unPack();
}

void BMPHeader::init() {
	BmpType[2] = '\0';
	BmpSize = 0;
	RESERVED1 = 0;
	RESERVED2 = 0;
	OFFSET = 0;
	size_ih = 0;
	with_ih = 0;
	heght_ih = 0;
	planes_ih = 0;
	bit_count_ih = 0;
	compression_ih = 0;
	imageSize_ih = 0;
	XpixelsPerM_ih = 0;
	YpixelsPerM_ih = 0;
	ColorUsed_ih = 0;
	ColorImportant_ih = 0;
}

void BMPHeader::unPack() {
	char *c = bufferHeader;

	memcpy(&BmpType, c, 2);
	memcpy(&BmpSize, c+=2, 4);
	memcpy(&RESERVED1, c+=4, 2);
	memcpy(&RESERVED2, c+=2, 2);
	memcpy(&OFFSET, c+=2, 4);
	//infoheader
	memcpy(&size_ih, c+=4, 4);
	memcpy(&with_ih, c += 4, 4);
	memcpy(&heght_ih, c += 4, 4);
	memcpy(&planes_ih, c += 4, 2);
	memcpy(&bit_count_ih, c += 2, 2);
	memcpy(&compression_ih, c += 2, 4);
	memcpy(&imageSize_ih, c += 4, 4);
	memcpy(&XpixelsPerM_ih, c += 4, 4);
	memcpy(&YpixelsPerM_ih, c += 4, 4);
	memcpy(&ColorUsed_ih, c += 4, 4);
	memcpy(&ColorImportant_ih, c += 4, 4);

}