#include <iostream>

// Класс для демонстрации, например, точка на плоскости
class MyPoint {
public:
    int x, y;
    MyPoint(int x = 0, int y = 0) : x(x), y(y) {
        std::cout << "Point created at (" << x << ", " << y << ")" << std::endl;
    }
    ~MyPoint() {
        std::cout << "Point destroyed at (" << x << ", " << y << ")" << std::endl;
    }
};

// Шаблон "умного" указателя MyUnique
template<class T>
class MyUnique {
    T * p; // Указатель на управляемый объект
public:
    // Конструктор, принимающий "сырой" указатель
    explicit MyUnique(T *p = nullptr) : p(p) {}

    // Деструктор, освобождающий ресурсы
    ~MyUnique() {
        delete p;
    }

    // Метод get, возвращающий "сырой указатель"
    T * get() const {
        return p;
    }

    // Оператор разыменования
    T & operator*() {
        return *p;
    }

    // Оператор ->
    T * operator->() {
        return p;
    }

    // Запрет копирования
    MyUnique(const MyUnique &) = delete;
    MyUnique & operator=(const MyUnique &) = delete;

    // Оператор перемещения
    MyUnique(MyUnique &&other) noexcept : p(other.p) {
        other.p = nullptr;
    }

    // Оператор присваивания перемещения
    MyUnique & operator=(MyUnique &&other) noexcept {
        if (this != &other) {
            delete p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }
};

// Глобальная шаблонная функция Make_MyUnique
template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
    return MyUnique<T>(new T(std::forward<Args>(args)...));
}

int main() {
    // Создание указателя на объект MyPoint с помощью Make_MyUnique
    auto point = Make_MyUnique<MyPoint>(10, 20);
    std::cout << "Point coordinates: (" << point->x << ", " << point->y << ")" << std::endl;
    return 0;
}