#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <algorithm>

std::mutex mtx; // Мьютекс для синхронизации доступа к выводу
std::condition_variable cv; // Условная переменная для оповещения главного потока
bool thread1_finished = false; // Флаг завершения первого потока
bool thread2_finished = false; // Флаг завершения второго потока

void sort_and_print(const std::string& name, std::vector<double>& arr, int start, int end) {
    std::sort(arr.begin() + start, arr.begin() + end);
    {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = start; i < end; ++i) {
            std::cout << name << ": " << arr[i] << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    } // Мьютекс освобождается при выходе из блока
    if (name == "thread1") {
        thread1_finished = true;
    } else if (name == "thread2") {
        thread2_finished = true;
    }
    cv.notify_one(); // Оповещение о завершении потока
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);

    const int size = 20;
    std::vector<double> arr(size);
    for (auto& num : arr) {
        num = dis(gen);
    }

    std::thread thread1(sort_and_print, "thread1", std::ref(arr), 0, size / 2);
    std::thread thread2(sort_and_print, "thread2", std::ref(arr), size / 2, size);
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (!(thread1_finished && thread2_finished)) {
            cv.wait(lock); // Ожидание завершения первых двух потоков
        }
    }
    std::thread thread3(sort_and_print, "thread3", std::ref(arr), 0, size);
    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "Main thread: All threads finished." << std::endl;
}