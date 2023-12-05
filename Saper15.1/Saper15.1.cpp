#include "Saper15.h"
#include <ctime>

int main() {
	cout << "Current version Saper15.5" << endl;
	Saper15 obj;
	fstream file;
	string line;
	string* arrOfString = new string[20];
	int count = 0;


	file.open("encoded.txt");
	while (getline(file, line)) {
		arrOfString[count++] = obj.DeHashLine(line);
	}
	file.close();

	for (int i = 0; i < count; i++) {
		cout << arrOfString[i] << endl;
	}

	return 0;
}