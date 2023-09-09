#include <iostream>
#include <string>




std::string repeat_str(std::string str, int num);

std::string spces_str(std::string str);

bool is_spam(std::string msg);


int main() {
	system("chcp 1251>nul");
	int n, m;
	std::string str;

	//Задача 0. Повторение строки.//Решение с помощью конкатинации строк
	std::cout << "Задача 0.\nВведите строку:";
	std::getline(std::cin, str);
	std::cout << "Введите кол-во повторений -> ";
	std::cin >> n;
	std::cin.ignore();
	std::cout << repeat_str(str, n) << "\n\n";

	//Задача 1. Пробелы в строке
	std::cout << "Задача 1.\nВведите строку -> ";
	std::getline(std::cin, str);
	std::cout << spces_str(str) << "\n\n";
	

	//Задача 2.Проверка на спам.
	std::cout << "Задача 2.\nВведите строку -> ";
	std::getline(std::cin, str);
	if (is_spam(str))
		std::cout << "Обнаружен спам!\n\n";
	else
		std::cout << "Спама не обнаружено.\n\n";

	//Задача 3. URL адрес
	std::cout << "Задача 3.\nURL адрес:\n";
	std::string URL = "https://vk.com/home/music";
	std::cout << URL << std::endl;

	int domen_index = URL.find("://")+3;
	int path_index = URL.find('/', domen_index)+1;

	std::string protocol = URL.substr(0, domen_index - 3);
	std::string domen = URL.substr(domen_index, path_index - 1-domen_index);
	std::string path = URL.substr(path_index);

	std::cout << "Протокол: " << protocol << std::endl;
	std::cout << "Домен: " << domen << std::endl;
	std::cout << "Путь: " << path << std::endl;


	return 0;
}

bool is_spam(std::string msg) {
	for (int i = 0; i < msg.length(); i++)
		msg[i] = std::tolower(msg[i]);

	const int spams_number = 4;
	std::string spams[spams_number]{
		"100% free",
		"sales increas",
		"only today",
		"black friday"
	};
	for (int i = 0; i < spams_number; i++)
		if (msg.find(spams[i]) < msg.length())
			return true;
	return false;
}

std::string spces_str(std::string str) {
	for (int i = str.length() - 1; i >= 1; i--)
		str.insert(i, " ");//метод insert вставляет пробел в позицию i
	return str;
}


std::string repeat_str(std::string str, int num) {
	std::string tmp;//""
	for (int i = 0; i < num; i++)
		tmp += str;
	return tmp;
}