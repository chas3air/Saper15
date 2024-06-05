#include "func.h"
#include "Saper15.h"

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Current version Saper15.8" << endl;
	Saper15 obj;
	cout << "Hello, world" << endl;
 	string hashed =  obj.HashLine("Hello, world");
	std::cout << hashed << std::endl;
	std::cout << obj.DeHashLine(hashed) << std::endl;
	

	system("pause");
}