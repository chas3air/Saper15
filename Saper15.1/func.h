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

void devString(string in, string* arr);