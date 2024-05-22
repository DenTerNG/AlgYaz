#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Класс для представления выставочного экспоната
class Exhibit {
private:
    string name;  // Название экспоната
    int durationDays;  // Время экспонирования (в днях)
    double costPerDay; // Стоимость одного дня экспонирования

public:
    // Конструктор для инициализации полей класса
    Exhibit(const string& name, int durationDays, double costPerDay)
        : name(name), durationDays(durationDays), costPerDay(costPerDay) {}

    // Метод для расчета общей стоимости экспонирования
    double calculateTotalCost() const {
        return durationDays * costPerDay;
    }

    // Метод для вывода параметров экспоната на консоль
    void print() const {
        cout << "Название экспоната: " << name << "\n"
             << "Дни экспонирования: " << durationDays << "\n"
             << "Стоимость за день: " << costPerDay << "\n"
             << "Общая стоимость: " << calculateTotalCost() << "\n";
    }

    // Метод для записи параметров экспоната в файл
    void printToFile(ofstream& outFile) const {
        outFile << "Название экспоната: " << name << "\n"
                << "Дни экспонирования: " << durationDays << "\n"
                << "Стоимость за день: " << costPerDay << "\n"
                << "Общая стоимость: " << calculateTotalCost() << "\n";
    }

    // Методы доступа для получения значений полей
    const string& getName() const {
        return name;
    }

    int getDurationDays() const {
        return durationDays;
    }

    double getCostPerDay() const {
        return costPerDay;
    }
};

// Функция для чтения данных экспонатов из файла
vector<Exhibit> readExhibitsFromFile(const string& filename) {
    vector<Exhibit> exhibits;
    ifstream file(filename); // Открытие файла для чтения
    if (file.is_open()) {
        string name;
        int durationDays;
        double costPerDay;
        // Чтение данных из файла и создание объектов Exhibit
        while (file >> name >> durationDays >> costPerDay) {
            exhibits.emplace_back(name, durationDays, costPerDay);
        }
        file.close(); // Закрытие файла после чтения данных
    } else {
        cerr << "Невозможно открыть файл: " << filename << endl;
    }
    return exhibits;
}

// Функция для вывода параметров всех экспонатов на консоль и запись их в файл
void printExhibits(const vector<Exhibit>& exhibits, const string& filename, const Exhibit* maxCostExhibit) {
    ofstream outFile(filename); // Открытие файла для записи
    if (!outFile.is_open()) {
        cerr << "Невозможно открыть файл для записи: " << filename << endl;
        return;
    }

    // Проход по всем экспонатам и вывод данных
    for (const auto& exhibit : exhibits) {
        exhibit.print(); // Вывод на консоль
        exhibit.printToFile(outFile); // Запись данных в файл
    }

    outFile << "\n\nЭкспонат с максимальной стоимостью:\n";
    maxCostExhibit->printToFile(outFile); // Запись данных самого дорогого экспоната в файл

    outFile.close(); // Закрытие файла после записи данных
}

// Функция для нахождения экспоната с максимальной стоимостью экспонирования
const Exhibit* findMaxCostExhibit(const vector<Exhibit>& exhibits) {
    if (exhibits.empty()) return nullptr; // Проверка на пустой вектор

    const Exhibit* maxCostExhibit = &exhibits[0]; // Инициализация максимального экспоната
    // Поиск экспоната с максимальной стоимостью
    for (const auto& exhibit : exhibits) {
        if (exhibit.calculateTotalCost() > maxCostExhibit->calculateTotalCost()) {
            maxCostExhibit = &exhibit;
        }
    }
    return maxCostExhibit;
}

// Главная функция программы
int main() {
    const string inputFile = "input.txt"; // Имя входного файла
    const string outputFile = "output.txt"; // Имя выходного файла

    // Чтение данных из файла
    vector<Exhibit> exhibits = readExhibitsFromFile(inputFile);

    // Нахождение экспоната с максимальной стоимостью
    const Exhibit* maxCostExhibit = findMaxCostExhibit(exhibits);

    // Вывод параметров всех экспонатов на консоль и запись в файл
    printExhibits(exhibits, outputFile, maxCostExhibit);

    // Вывод на консоль информации о самом дорогом экспонате
    if (maxCostExhibit) {
        cout << "Экспонат с максимальной стоимостью:\n";
        maxCostExhibit->print(); // Вывод параметров экспоната с максимальной стоимостью
    }

}
