#include "Saper15.h"

Saper15::Saper15() : ascii{ "" }, symbols{ "" } {
	fstream file;
	//this->symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !#$%&'()*+,-./:;<=>?@[]^`-|{}~0123456789_";

	string line;

	file.open("shuffled.txt");
	if (!file.is_open()) this->ascii = "";
	while (getline(file, line)) {
		this->ascii += line;
	}
	file.close();

	file.open("ascii.txt");
	if (!file.is_open()) this->symbols = "";
		while (getline(file, line)) {
		this->symbols += line;
	}
	file.close();
}

string Saper15::GetSymbols() const { // возвращает символы все возможные символы
	return this->symbols;
}

string Saper15::GetASCII() const { // возвращает перемешанные символы ascii
	return this->ascii;
}

string Saper15::HashLine(string str) {
	if (this->ascii.size() < 1 or this->symbols.size() < 1)
		return "";

	string hashedLine;
	for (int i = 0; i < str.size(); i++) {
		int index = IndexOf(this->symbols, str[i]);
		hashedLine += this->ascii[index];
	}
	return hashedLine;
}

string Saper15::DeHashLine(string str) {
	if (this->ascii.size() < 1 or this->symbols.size() < 1)
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