#include "Saper15.h"

int main() {
	Saper15 encode;
	string line;
	cout << "Saper15.1" << endl;
	cout << "Enter line: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);
	cout << encode.HashString(line);
}