#include "Saper15.h"

Saper15::Saper15() : hash{ "undefined" }, deHash{ "undefined" } {
	fstream file;
	for (int i = 65; i <= 90; i++) {
		this->symbols += (static_cast<char>(i));
	}

	for (int i = 97; i <= 122; i++) {
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

string Saper15::GetSymbols() const
{
	return this->symbols;
}

string Saper15::GetASCII() const
{
	return this->acsii;
}

string Saper15::HashLine(string str)
{
	string hashedLine;
	for (int i = 0; i < str.size(); i++) {
		int index = IndexOf(this->symbols, str[i]);
		hashedLine += this->acsii[index];
	}
	return hashedLine;
}

string Saper15::DeHashLine(string str)
{
	string deHashLine;

	for (int i = 0; i < str.size(); i++) {
		int index = IndexOf(this->acsii, str[i]);
		deHashLine += this->symbols[index];
	}

	return deHashLine;
}
