#include "func.h"

void devString(string in, string* arr) {
	int c = 0;
	string tmp;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] != ' ')
			tmp += in[i];
		else {
			arr[c] = tmp;
			tmp = "";
			c++;
		}
	}
	arr[c] = tmp;
	//(*count) = ++c;
}