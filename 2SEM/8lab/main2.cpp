#include <iostream>
#include <memory>

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

// Шаблон "умного" указателя MyShared
template<class T>
class MyShared {
    T * p; // Указатель на управляемый объект
    int * count; // Счетчик ссылок
public:
    // Конструктор
    explicit MyShared(T *p = nullptr) : p(p), count(new int(1)) {}

    // Деструктор
    ~MyShared() {
        if (--(*count) == 0) {
            delete p;
            delete count;
        }
    }

    // Метод get
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

    // Конструктор копирования
    MyShared(const MyShared &other) : p(other.p), count(other.count) {
        ++(*count);
    }

    // Оператор присваивания копирования
    MyShared & operator=(const MyShared &other) {
        if (this != &other) {
            if (--(*count) == 0) {
                delete p;
                delete count;
            }
            p = other.p;
            count = other.count;
            ++(*count);
        }
        return *this;
    }

    // Оператор перемещения
    MyShared(MyShared &&other) noexcept : p(other.p), count(other.count) {
        other.p = nullptr;
        other.count = nullptr;
    }

    // Оператор присваивания перемещения
    MyShared & operator=(MyShared &&other) noexcept {
        if (this != &other) {
            if (--(*count) == 0) {
                delete p;
                delete count;
            }
            p = other.p;
            count = other.count;
            other.p = nullptr;
            other.count = nullptr;
        }
        return *this;
    }
};

// Глобальная шаблонная функция Make_MyShared
template<typename T, typename... Args>
MyShared<T> Make_MyShared(Args&&... args) {
    return MyShared<T>(new T(std::forward<Args>(args)...));
}

int main() {
    // Создание указателя на объект MyPoint с помощью Make_MyShared
    auto point1 = Make_MyShared<MyPoint>(10, 20);
    auto point2 = point1; // Копирование указателя
    std::cout << "Point coordinates: (" << point2->x << ", " << point2->y << ")" << std::endl;
    return 0;
}