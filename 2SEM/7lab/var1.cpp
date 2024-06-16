#include <iostream>
#include <vector>
#include <future> 
#include <chrono> 
#include <random>
#include <algorithm>
#include <thread>


void sort_and_print(const std::string& name, std::vector<double>& arr, int start, int end) {
    std::sort(arr.begin() + start, arr.begin() + end);
    for (int i = start; i < end; ++i) {
        std::cout << name << ": " << arr[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Задержка в 10 мс
    }
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

    auto future1 = std::async(sort_and_print, "thread1", std::ref(arr), 0, size / 2);
    auto future2 = std::async(sort_and_print, "thread2", std::ref(arr), size / 2, size);
    future1.get();
    future2.get();

    auto future3 = std::async(sort_and_print, "thread3", std::ref(arr), 0, size);
    future3.get();

    std::cout << "Main thread: All threads finished." << std::endl;
}