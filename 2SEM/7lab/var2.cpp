#include <iostream>
#include <vector>
#include <thread> // Для использования потоков
#include <chrono>
#include <random>
#include <algorithm>

// Функция для сортировки и печати части массива
void sort_and_print(const std::string& name, std::vector<double>& arr, int start, int end) {
    std::sort(arr.begin() + start, arr.begin() + end); // Сортировка части массива
    for (int i = start; i < end; ++i) {
        std::cout << name << ": " << arr[i] << std::endl; // Печать отсортированных элементов
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Задержка в 10 мс
    }
}

int main() {
    std::random_device rd; // Генератор случайных чисел
    std::mt19937 gen(rd()); // Мастер-генератор для ГПСЧ
    std::uniform_real_distribution<> dis(1.0, 100.0); // Распределение для генерации чисел

    const int size = 20; // Размер массива
    std::vector<double> arr(size); // Создание массива
    for (auto& num : arr) {
        num = dis(gen); // Заполнение массива случайными числами
    }

    // Создание и запуск потоков для сортировки и печати
    std::thread thread1(sort_and_print, "thread1", std::ref(arr), 0, size / 2);
    std::thread thread2(sort_and_print, "thread2", std::ref(arr), size / 2, size);
    thread1.join(); // Ожидание завершения первого потока
    thread2.join(); // Ожидание завершения второго потока

    // Запуск третьего потока после завершения первых двух
    std::thread thread3(sort_and_print, "thread3", std::ref(arr), 0, size);
    thread3.join(); // Ожидание завершения третьего потока

    std::cout << "Main thread: All threads finished." << std::endl; // Сообщение о завершении всех потоков
}