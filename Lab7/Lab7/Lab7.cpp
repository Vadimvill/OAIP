// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Stack.h"
#include <iostream>

int main()
{
    Stack<int> stack;
    StackManipulator<int> stackManipulator(stack);
    std::cout << "Input stack of int, to stop input -1\n";
    int i = 0;
    while (true) {
        std::cin >> i;
        stack.push(i);
        if (stack.top() == -1) {
            stack.pop();
            break;
        }
    }
    if (stack.empty()) {
        return 1;
    }
    std::cout << "\n Original : \n";
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nInput first index \b";
    std::cin >> i;
    stackManipulator.sortElements(stack.begin()+(i-1), stack.end());
    std::cout << "\n Sorted : \n";
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it<<' ';
    }
    std::cout << "\ninput search element\n";
    std::cin >> i;
    std::cout << stackManipulator.findElement(i,stack.begin(),stack.end());
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
