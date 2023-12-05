#pragma once
#include "func.h"

class Saper15
{
private:
	string hash;
	string deHash;
	string acsii;
	string symbols;

public:
	Saper15();

	string GetSymbols() const;

	string GetASCII() const;

	string HashLine(string str);

	string DeHashLine(string str);
};