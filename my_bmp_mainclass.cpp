#include "my_bmp.h"

using namespace std;

int main() {
	MyBMP f;
	char filename[20];
	cout << "Bmp file:" << flush; // force output
	cin >> filename;

	f.OpenBmp(filename);
	f.printHeader();
}
