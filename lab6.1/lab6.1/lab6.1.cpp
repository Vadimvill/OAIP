// lab6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SaveClasses.h"
int main()
{
    List<Computer>* list = new List<Computer>();
    //SaverText saverText("C:\\lab6\\list.bin", list);
    //SaverBin saver("C:\\lab6\\list.bin", list);
    std::cout << "Select type of save(1-text,2-binary)\n";
    Saver* saver;
    int i = 0;
    while (true) {
        try {
            std::cin >> i;
            if (i == 1) 
                saver = new SaverText("C:\\lab6\\list.txt", list);
            else if (i == 2)
                saver = new SaverBin("C:\\lab6\\list.bin", list);
            else {
                std::cout << "Error\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
           
            break;
        }
        catch (...) {
            std::cout << "Error\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
    while (true)
    {
        std::cout << " 1. Push Computer\n 2. Push Desktop\n 3. Push Laptop\n 4. Push Monoblock\n 5. Push Portable\n 6. Push Tablet\n 7. Remove Element\n 8. Print List\n 9. Save\n 10. Load\n";
        while (true) {
            try {
                std::cin >> i;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            catch (...) {
                std::cout << "Error\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
        std::cout << "\n\n\n";
        if (i == 1) {
            std::string model;
            std::string owner;
            std::cout << "Input model\n";
            std::getline(std::cin, model);
            std::cout << "Input owner\n";
            std::getline(std::cin, owner);
            list->addNode(new NodeOfList<Computer>(new Computer(model.c_str(), owner.c_str())));
        }     
        else if (i == 2) {
            std::string model;
            std::string owner;
            std::string box;
            std::cout << "Input model\n";
            std::getline(std::cin, model);
            std::cout << "Input owner\n";
            std::getline(std::cin, owner);
            std::cout << "Input box name\n";
            std::getline(std::cin,box);
            list->addNode(new NodeOfList<Computer>(new Desktop(model.c_str(), owner.c_str(),box.c_str())));
        }    
        else if (i == 3) {
            std::string model;
            std::string owner;
            std::string box;
            std::cout << "Input model\n";
            std::getline(std::cin, model);
            std::cout << "Input owner\n";
            std::getline(std::cin, owner);
            int power = 0;
            double screenSize = 0;
            std::cout << "Input power\n";
            while (true) {
                std::cin >> power;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error\n";
                    continue;
                }
                break;
            }
            int countOfKeys = 0;
            std::cout << "Input count of keys\n";
            while (true) {
                std::cin >> countOfKeys;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error\n";
                    continue;
                }
                break;
            }
            std::cout << "Input ScreenSize\n";
            while (true) {
                std::cin >> screenSize;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error\n";
                    continue;
                }
                break;
            }
            list->addNode(new NodeOfList<Computer>(new Laptop(model.c_str(), owner.c_str(), power, screenSize,countOfKeys)));
        }
        else if (i == 4) {
            std::string model;
            std::string owner;
            std::string box;
            std::cout << "Input model\n";
            std::getline(std::cin, model);
            std::cout << "Input owner\n";
            std::getline(std::cin, owner);
            std::cout << "Input box name\n";
            std::getline(std::cin, box);
            int screenSize = 0;
            std::cout << "Input ScreenSize\n";
            while (true) {
                std::cin >> screenSize;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error\n";
                    continue;
                }
                break;
            }
            list->addNode(new NodeOfList<Computer>(new Monoblock(model.c_str(), owner.c_str(), box.c_str(),screenSize)));
        }

        else if (i == 5) {
            std::string model;
            std::string owner;
            std::string box;
            std::cout << "Input model\n";
            std::getline(std::cin, model);
            std::cout << "Input owner\n";
            std::getline(std::cin, owner);
            int power = 0;
            double screenSize = 0;
            std::cout << "Input power\n";
            while (true) {
                std::cin >> power;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error\n";
                    continue;
                }
                break;
            }
            std::cout << "Input ScreenSize\n";
            while (true) {
                std::cin >> screenSize;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error\n";
                    continue;
                }
                break;
            }
            list->addNode(new NodeOfList<Computer>(new Portable(model.c_str(), owner.c_str(), power, screenSize)));
        }

        else if (i == 6) {
        std::string model;
        std::string owner;
        std::string modem;
        std::cout << "Input model\n";
        std::getline(std::cin, model);
        std::cout << "Input owner\n";
        std::getline(std::cin, owner);
        std::cout << "Input modem\n";
        std::getline(std::cin, modem);
        int power = 0;
        double screenSize = 0;
        std::cout << "Input power\n";
        while (true) {
            std::cin >> power;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error\n";
                continue;
            }
            break;
        }
        std::cout << "Input ScreenSize\n";
        while (true) {
            std::cin >> screenSize;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error\n";
                continue;
            }
            break;
        }
        list->addNode(new NodeOfList<Computer>(new Tablet(model.c_str(), owner.c_str(), power, screenSize,modem.c_str())));
        }
        else if (i == 7) {
        std::cout << "Input index\n";
        int index = 0;
        while (true) {
            std::cin >> index;
            if (std::cin.fail() || index < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error\n";
                continue;
            }
            break;
        }
        try {
            list->removeNode(index);
        }
        catch (int code) {
            std::cout << "Error of bound\n";
        }
        
        }
        else if (i == 8) {
        for (int i = 0;i < list->getSize();i++) {
            std::cout << std::to_string(i) + ".\n" + list->getNode(i)->date->createPrintString() << '\n';
        }
        }

        else if (i == 9) {
        std::cout << "\n\n\n";
        saver->save();
        list->clear();
        }

        else if (i == 10) {
        std::cout << "\n\n\n";
        list->clear();
        saver->load();
        }
        else {

        }

    }
  
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
