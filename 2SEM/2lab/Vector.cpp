#include "Vector.h"

// Конструктор по умолчанию, инициализирует вектор нулевым размером и нулевым указателем на данные
Vector::Vector() : data(nullptr), size(0) {}

// Конструктор, принимающий массив и его размер, инициализирует вектор данными из массива
Vector::Vector(int* arr, int n) : size(n) {
    data = new int[size]; // Выделяет память для массива данных
    for (int i = 0; i < size; ++i) {
        data[i] = arr[i]; // Копирует данные из входного массива в вектор
    }
}

// Конструктор копирования, создает копию другого вектора
Vector::Vector(const Vector& other) : size(other.size) {
    data = new int[size]; // Выделяет память для массива данных
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i]; // Копирует данные из другого вектора
    }
}

// Конструктор перемещения, передает ресурсы из другого вектора
Vector::Vector(Vector&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr; // Устанавливает указатель на данные другого вектора в nullptr
    other.size = 0; // Устанавливает размер другого вектора в 0
}

// Деструктор, освобождает выделенную память
Vector::~Vector() {
    delete[] data; // Освобождает память, выделенную для массива данных
}

// Оператор доступа по индексу, возвращает ссылку на элемент по указанному индексу
int& Vector::operator[](int index) {
    return data[index]; // Возвращает ссылку на элемент массива данных
}

// Оператор присваивания с копированием, копирует данные из другого вектора
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) { // Проверяет, не присваивается ли вектор самому себе
        delete[] data; // Освобождает текущие данные
        size = other.size; // Копирует размер
        data = new int[size]; // Выделяет память для нового массива данных
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i]; // Копирует данные из другого вектора
        }
    }
    return *this; // Возвращает ссылку на текущий объект
}

// Оператор присваивания с перемещением, передает ресурсы из другого вектора
Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) { // Проверяет, не присваивается ли вектор самому себе
        delete[] data; // Освобождает текущие данные
        data = other.data; // Передает указатель на данные
        size = other.size; // Передает размер
        other.data = nullptr; // Устанавливает указатель на данные другого вектора в nullptr
        other.size = 0; // Устанавливает размер другого вектора в 0
    }
    return *this; // Возвращает ссылку на текущий объект
}

// Оператор сравнения меньше, сравнивает текущий вектор с другим вектором
bool Vector::operator<(const Vector& other) const {
    for (int i = 0; i < size && i < other.size; ++i) {
        if (data[i] >= other.data[i]) return false; // Сравнивает элементы векторов
    }
    return size < other.size; // Возвращает результат сравнения размеров векторов
}

// Функция сравнения меньше, сравнивает текущий вектор с массивом
bool Vector::isLessThan(int* arr, int n) const {
    for (int i = 0; i < size && i < n; ++i) {
        if (data[i] >= arr[i]) return false; // Сравнивает элементы вектора с элементами массива
    }
    return size < n; // Возвращает результат сравнения размеров вектора и массива
}

// Оператор ввода, считывает данные в вектор из потока ввода
std::istream& operator>>(std::istream& is, Vector& v) {
    is >> v.size; // Считывает размер вектора
    v.data = new int[v.size]; // Выделяет память для массива данных
    for (int i = 0; i < v.size; ++i) {
        is >> v.data[i]; // Считывает элементы вектора
    }
    return is; // Возвращает поток ввода
}

// Оператор вывода, выводит данные вектора в поток вывода
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << v.size << " "; // Выводит размер вектора
    for (int i = 0; i < v.size; ++i) {
        os << v.data[i] << " "; // Выводит элементы вектора
    }
    return os; // Возвращает поток вывода
}