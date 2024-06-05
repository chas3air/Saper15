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
}

void shuffle(string filepath_read, string filepath_write) { // функция принимет два путя к файлам
    fstream file;                                           // из первого берется текст 
    file.open(filepath_read, std::ios::in);                 // во второй записывается перемешанные элементы из первого файла
    if(!file.is_open()){
        std::cout << "Error" << endl;
        return;
    }
    string res;
    string line;
    while (getline(file, line)) {
        res += line;
    }
    file.close();
    file.open(filepath_write, std::ios::out | std::ios::trunc);
    if (!file.is_open()){
        std::cout << "error" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    // Перемешиваем элементы строки
    for (int i = static_cast<int>(res.length()) - 1; i > 0; i--) {
        int j = g() % (i + 1);
        std::swap(res[i], res[j]);
    }
    file << res;
    file.close();
    std::cout << "Good" << endl;
}