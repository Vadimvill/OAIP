#include <deque>

#include <iostream>
int checkInt(int i,int type) {
	if (type == 1) {
		while (true) {
			std::cin >> i;
			if (std::cin.fail()) {
				std::cout << "Error\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		return i;
	}
	if (type == 0) {
		while (true) {
			std::cin >> i;
			if (std::cin.fail() || i < 0) {
				std::cout << "Error\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		return i;
	}

}
void menuShow() {
	std::cout << '\n';
	std::cout << "1.Push" << std::endl;
	std::cout << "2.Pop" << std::endl;
	std::cout << "3.Resize" << std::endl;
	std::cout << "4.Assigh" << std::endl;
	std::cout << "5.Clear list" << std::endl;
	std::cout << "6.Find" << std::endl;
	std::cout << "7.Exit" << std::endl;
	std::cout << "Choice:" << std::endl;
}
void printDeque(std::deque<int> deq) {
    for (int i = 0;i < deq.size();i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << '\n';
}
int main()
{
	int i = 0;
	std::deque<int> deq;
	int menuValue = 0;
	while (menuValue != 7) {
		printDeque(deq);
		std::cout << std::endl;
		menuShow();
		std::cin >> menuValue;
		if (menuValue == 1) {
			deq.push_back(checkInt(i, 1));
		}
		if (menuValue == 2) {
			if (deq.size() != 0) {
				std::cout << "Pop" << std::endl;
				deq.pop_front();
			}
		}
		if (menuValue == 3) {

			std::cout << "Enter value" << std::endl;
			i = checkInt(i, 0);
			deq.resize(i);
		}
		if (menuValue == 4) {
			int value, n;
			std::cout << "Enter n" << std::endl;
			n = checkInt(i, 0);
			std::cout << "Enter value" << std::endl;
			value = checkInt(i, 1);
			deq.assign(n, value);
		}
		if (menuValue == 5) {
			deq.clear();
		}
		if (menuValue == 6) {
			int value;
			std::cout << "Enter value" << std::endl;
			std::cin >> value;
			auto start = deq.begin();
			auto end = deq.end();
			auto isFound = std::find(start, end, value);
			if (isFound == end) {
				std::cout << "Not found!" << std::endl;
			}
			else {
				std::cout << "Found: " << *isFound << std::endl;
			}
		}
	}
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
