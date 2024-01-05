#pragma once
#include <string>
#include <fstream>
using namespace std;

class Saper15
{
private:
	string ascii;
	string symbols;

public:
	Saper15();

	string GetSymbols() const;

	string GetASCII() const;

	string HashLine(string str);

	string DeHashLine(string str);

	int IndexOf(string main, char in);
};