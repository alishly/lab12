#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include "windows.h"

// STL2Seq3
void Zad1() {

    std::cout << " STL2Seq3 ";
    std::vector<int> V;
    int n;

    std::cout << "Введите количество элементов (четное число): ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << " Количество элементов должно быть четным!\n";
        return;
    }

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        V.push_back(x);
    }

    std::cout << "Результат: ";


    for (size_t i = n / 2; i < V.size(); ++i) {
        std::cout << V[i] << " ";
    }

    for (size_t i = 0; i < n / 2; ++i) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;
}

// STL2Seq10
void Zad2() {

    std::cout << " STL2Seq10 ";
    std::list<int> L;
    int n;

    std::cout << "Введите количество элементов (кратно 3): ";
    std::cin >> n;

    if (n % 3 != 0) {
        std::cout << "Количество элементов должно быть кратно 3!\n";
        return;
    }

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        L.push_back(x);
    }


    std::list<int> firstThird;
    auto it = L.begin();
    for (int i = 0; i < n / 3; ++i) {
        firstThird.push_front(*it);
        ++it;
    }


    L.insert(L.end(), firstThird.begin(), firstThird.end());

    std::cout << "Результат: ";
    for (int x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// STL2Seq28
void Zad3() {

    std::cout << "STL2Seq28 ";
    std::deque<int> D;
    int n;

    std::cout << "Введите количество элементов (кратно 4): ";
    std::cin >> n;

    if (n % 4 != 0) {
        std::cout << " Количество элементов должно быть кратно 4!\n";
        return;
    }

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        D.push_back(x);
    }


    auto i = D.begin();
    for (int k = 0; k < n / 4; ++k) {
        ++i;
        i = D.erase(i);
    }

    std::cout << "Результат: ";
    for (int x : D) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


void Zad4() {

    std::cout << " STL1Iter10 ";
    int n;

    std::cout << "Введите количество элементов (не менее 2): ";
    std::cin >> n;

    if (n < 2) {
        std::cout << " Количество элементов должно быть не менее 2!\n";
        return;
    }

    std::cout << "Введите " << n << " вещественных чисел: ";


    std::vector<double> numbers;


    for (int i = 0; i < n; ++i) {
        double x;
        std::cin >> x;
        numbers.push_back(x);
    }

    //  выходной итератор
    std::ostream_iterator<double> output(std::cout, " ");



    int index = 1;
    auto isOddPosition = [&index](double) mutable {
        return (index++ % 2 != 0);
    };

    std::remove_copy_if(numbers.begin(), numbers.end(), output, isOddPosition);
    std::cout << std::endl;
}

int main() {
    int choice;

    SetConsoleOutputCP(65001);
    SetConsoleOutputCP(CP_UTF8);

    SetConsoleCP(65001);
    SetConsoleCP(CP_UTF8);

    do {
        std::cout << "меню"<<std::endl;
        std::cout << "1 - STL2Seq3 "<<std::endl;
        std::cout << "2 - STL2Seq10 "<<std::endl;
        std::cout << "3 - STL2Seq28 "<<std::endl;
        std::cout << "4 - STL1Iter10 "<<std::endl;
        std::cout << "0 - Выход "<<std::endl;
        std::cout << "Выберите задание: "<<std::endl;
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            case 1:
                Zad1();
                break;
            case 2:
                Zad2();
                break;
            case 3:
                Zad3();
                break;
            case 4:
                Zad4();
                break;
            default:
                std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}