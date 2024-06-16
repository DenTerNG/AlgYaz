#pragma once
#include <iostream>
#include <fstream>

class Vector {
private:
    int* data;
    int size;

public:
    // Конструкторы
    Vector();
    Vector(int* arr, int n);
    Vector(const Vector& other); // Конструктор копирования
    Vector(Vector&& other) noexcept; // Конструктор перемещения

    // Деструктор
    ~Vector();

    // Операции
    int& operator[](int index);
    Vector& operator=(const Vector& other); // Присваивание с копированием
    Vector& operator=(Vector&& other) noexcept; // Присваивание с перемещением
    bool operator<(const Vector& other) const;

    // Ввод/вывод
    friend std::istream& operator>>(std::istream& is, Vector& v);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // Геттеры
    int getSize() const { return size; }

    // Сравнение с массивом
    bool isLessThan(int* arr, int n) const;
};