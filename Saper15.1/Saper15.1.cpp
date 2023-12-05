#include "Saper15.h"

int main() {
	system("chcp 1251");
	Saper15 encode;
	string line;
	cout << "Saper15.2" << endl;
	cout << encode.GetSymbols() << endl;
	cout << "Enter line: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);
	cout << encode.HashString(line);
}