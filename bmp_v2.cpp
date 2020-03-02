#include "mybmp.h"

using namespace std;

int main() {
	MyBMP f;
	cout << "Bmp file:"; // force output

	f.OpenBmp("m.bmp");
	//f.estructColorRGB(filename);
	f.PrintHeader();
}
