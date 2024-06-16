#include "Vector.h"
#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    // Создание векторов
    Vector v1, v2;
    input >> v1 >> v2;

    
    output << "v1 < v2: " << (v1 < v2) << std::endl;

    int arr[] = {1, 2, 3};
    output << "v1 < arr: " << v1.isLessThan(arr, 3) << std::endl;

    // Использование конструктора копирования
    Vector v3 = v1; // Копирование v1 в v3
    output << "v3 (после копирования): " << v3 << std::endl;

    // Использование конструктора перемещения
    Vector v4(std::move(v2)); // Перемещение v2 в v4
    output << "v4 (после перемещения): " << v4 << std::endl;
    output << "v2 (после перемещения): " << v2 << std::endl; // v2 должен быть пустым

    // Использование оператора присваивания с копированием
    Vector v5;
    v5 = v1; // Копирование v1 в v5
    output << "v5 (после присваивания с копированием): " << v5 << std::endl;

    // Использование оператора присваивания с перемещением
    Vector v6;
    v6 = std::move(v3); // Перемещение v3 в v6
    output << "v6 (после присваивания с перемещением): " << v6 << std::endl;
    output << "v3 (после присваивания с перемещением): " << v3 << std::endl; // v3 должен быть пустым

    input.close();
    output.close();
    return 0;
}