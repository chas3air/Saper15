#include "Saper15.h"

Saper15::Saper15() : ascii{ "" }, symbols{ "" } {
	fstream file;
	this->symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !\"#$ % &'()*+,-./:;<=>?@[]^_`-|{}~0123456789";

	string line;

	file.open("ascii.txt");
	if (!file.is_open()) this->ascii = "";
	while (getline(file, line)) {
		this->ascii += line;
	}
	file.close();
}

string Saper15::GetSymbols() const {
	return this->symbols;
}

string Saper15::GetASCII() const {
	return this->ascii;
}

string Saper15::HashLine(string str) {
	if (this->ascii.size() < 1)
		return "";

	string hashedLine;
	for (int i = 0; i < str.size(); i++) {
		int index = IndexOf(this->symbols, str[i]);
		hashedLine += this->ascii[index];
	}
	return hashedLine;
}

string Saper15::DeHashLine(string str) {
	if (this->ascii.size() < 1)
		return "";

	string deHashLine;
	for (int i = 0; i < str.size(); i++) {
		int index = IndexOf(this->ascii, str[i]);
		deHashLine += this->symbols[index];
	}
	return deHashLine;

}

int Saper15::IndexOf(string main, char in) {
	for (int i = 0; i < main.size(); i++) {
		if (main[i] == in) {
			return i;
		}
	}

	return -1;
}