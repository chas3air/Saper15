#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

inline int IndexOf(string main, char in) {
	for (int i = 0; i < main.size(); i++) {
		if (main[i] == in) {
			return i;
		}
	}
	return -1;
}

class Saper15
{
private:
	string hash;
	string deHash;
	string acsii;
	string symbols;

public:
	Saper15() : hash{ "undefined" }, deHash{ "undefined" } {
		fstream file;
		for (int i = 65; i <= 90; i++) {
			this->symbols += (static_cast<char>(i));
		}

		for (int i = 97; i <= 122; i++) {
			this->symbols += (static_cast<char>(i));
		}

		for (int i = 192; i <= 255; i++) {
			this->symbols += (static_cast<char>(i));
		}

		for (int i = 32; i <= 47; i++) {
			this->symbols += static_cast<char>(i);
		}

		for (int i = 58; i <= 64; i++) {
			this->symbols += static_cast<char>(i);
		}

		for (int i = 91; i <= 96; i++) {
			this->symbols += static_cast<char>(i);
		}

		this->symbols += '-';
		this->symbols += '¹';
		this->symbols += '|';
		this->symbols += '\t';
		this->symbols += '{';
		this->symbols += '}';
		this->symbols += '~';
		for (int i = 48; i <= 57; i++) {
			this->symbols += static_cast<char>(i);
		}


		string line;

		file.open("ascii.txt");
		if (!file.is_open()) this->acsii = "";
		while (getline(file, line)) {
			this->acsii += line;
		}
		file.close();
	}

	string GetSymbols() {
		return this->symbols;
	}

	string GetASCII() {
		return this->acsii;
	}

	string HashString(string str) {
		string hashedLine;
		try {
			for (int i = 0; i < str.size(); i++) {
				int index = IndexOf(this->symbols, str[i]);
				hashedLine += this->acsii[index];
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		return hashedLine;
	}

	string DeHashLine(string str) {
		string deHashLine;

		for (int i = 0; i < str.size(); i++) {
			int index = IndexOf(this->acsii, str[i]);
			deHashLine += this->symbols[index];
		}

		return deHashLine;
	}
};