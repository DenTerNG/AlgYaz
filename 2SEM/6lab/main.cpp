#include <iostream>
#include <stdexcept>

// Класс исключения для неправильных массивов Фибоначчи
class InvalidFibonacciArrayException : public std::invalid_argument {
public:
    // Конструктор, принимающий сообщение об ошибке, массив и его размер
    InvalidFibonacciArrayException(const std::string& message, int* array, size_t size)
        : std::invalid_argument(message), invalidArray(array), invalidSize(size) {}

    // Метод для вывода деталей исключения
    void printDetails() const {
        std::cerr << "Invalid Fibonacci Array Exception: " << what() << std::endl;
        std::cerr << "Invalid Array: ";
        for (size_t i = 0; i < invalidSize; ++i) {
            std::cerr << invalidArray[i] << " ";
        }
        std::cerr << std::endl;
    }

private:
    int* invalidArray; // Указатель на недопустимый массив
    size_t invalidSize; // Размер недопустимого массива
};

// Класс для массива, который должен быть последовательностью Фибоначчи
class FibonacciArray {
public:
    // Конструктор, принимающий массив и его размер
    FibonacciArray(int* array, size_t size) : array(array), size(size) {
        // Проверка, является ли массив последовательностью Фибоначчи
        if (!isFibonacciSequence()) {
            // Выброс исключения, если массив не является последовательностью Фибоначчи
            throw InvalidFibonacciArrayException("Array is not a Fibonacci sequence", array, size);
        }
    }

    // Метод для вывода содержимого массива
    void printArray() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* array; // Указатель на массив
    size_t size; // Размер массива

    // Метод для проверки, является ли массив последовательностью Фибоначчи
    bool isFibonacciSequence() const {
        if (size < 2) return false; // Массив слишком мал для последовательности Фибоначчи
        for (size_t i = 2; i < size; ++i) {
            if (array[i] != array[i - 1] + array[i - 2]) {
                return false; // Текущий элемент не равен сумме двух предыдущих
            }
        }
        return true;
    }
};

int main() {
    try {
        // Попытка создать объект с валидным массивом Фибоначчи
        int validArray[] = {0, 1, 1, 2, 3, 5, 8, 13};
        FibonacciArray validFibArray(validArray, 8);
        validFibArray.printArray();
    } catch (const InvalidFibonacciArrayException& e) {
        // Обработка исключения для невалидного массива
        e.printDetails();
    }

    try {
        // Попытка создать объект с невалидным массивом Фибоначчи
        int invalidArray[] = {0, 1, 1, 2, 3, 6, 8, 13};
        FibonacciArray invalidFibArray(invalidArray, 8);
        invalidFibArray.printArray();
    } catch (const InvalidFibonacciArrayException& e) {
        // Обработка исключения для невалидного массива
        e.printDetails();
    }

    return 0;
}