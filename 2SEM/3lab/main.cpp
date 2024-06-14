#include <iostream>
#include <string>

// Базовый класс "автомобиль"
class Car {
protected:
    std::string model;
    int maxSpeed;

public:
    Car(const std::string& model, int maxSpeed) : model(model), maxSpeed(maxSpeed) {}

    // Функция для печати параметров автомобиля
    void printParams() const {
        std::cout << "Model: " << model << ", Max Speed: " << maxSpeed << " km/h" << std::endl;
    }

    // Виртуальная функция для динамического полиморфизма
    virtual void printParamsDynamic() const {
        std::cout << "Dynamic - Model: " << model << ", Max Speed: " << maxSpeed << " km/h" << std::endl;
    }
};

// Производный класс "автобус"
class Bus : public Car {
private:
    int maxPassengers;

public:
    Bus(const std::string& model, int maxSpeed, int maxPassengers)
        : Car(model, maxSpeed), maxPassengers(maxPassengers) {}

    // Переопределенная функция печати параметров автобуса (статический полиморфизм)
    void printParams() const {
        Car::printParams(); // Вызов функции из базового класса
        std::cout << "Max Passengers: " << maxPassengers << std::endl;
    }

    // Переопределенная виртуальная функция для динамического полиморфизма
    void printParamsDynamic() const override {
        Car::printParamsDynamic(); // Вызов функции из базового класса
        std::cout << "Dynamic - Max Passengers: " << maxPassengers << std::endl;
    }
};

int main() {
    // Создание объекта базового класса
    Car car("Toyota Camry", 220);
    car.printParams();
    car.printParamsDynamic();

    // Создание объекта производного класса
    Bus bus("Mercedes-Benz Tourismo", 180, 50);
    bus.printParams();
    bus.printParamsDynamic();

    // Демонстрация динамического полиморфизма
    Car* carPtr = &bus;
    carPtr->printParamsDynamic(); // Вызов переопределенной функции из производного класса

    return 0;
}