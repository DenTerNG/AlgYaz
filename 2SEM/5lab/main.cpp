#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <functional>

class BankCredit {
public:
    // Конструктор для инициализации объекта BankCredit с заданными параметрами
    BankCredit(const std::string& name, double amount, const std::string& currency, double rate)
        : name(name), amount(amount), currency(currency), rate(rate) {}

    // Конструктор копирования для создания копии объекта BankCredit
    BankCredit(const BankCredit& other)
        : name(other.name), amount(other.amount), currency(other.currency), rate(other.rate) {}

    // Оператор присваивания копированием для копирования значений из другого объекта BankCredit
    BankCredit& operator=(const BankCredit& other) {
        if (this != &other) {
            name = other.name;
            amount = other.amount;
            currency = other.currency;
            rate = other.rate;
        }
        return *this;
    }

    // Перегруженный оператор < для сравнения объектов по ставке кредита
    bool operator<(const BankCredit& other) const {
        return rate < other.rate;
    }

    // Методы доступа
    const std::string& getName() const { return name; }
    double getAmount() const { return amount; }
    const std::string& getCurrency() const { return currency; }
    double getRate() const { return rate; }

    // Объявление оператора << как друга класса
    friend std::ostream& operator<<(std::ostream& os, const BankCredit& credit);

private:
    std::string name; // Название кредита
    double amount; // Сумма кредита
    std::string currency; // Тип валюты
    double rate; // Ставка в процентах годовых
};

// Определение перегруженного оператора <<
std::ostream& operator<<(std::ostream& os, const BankCredit& credit) {
    os << credit.getName() << " " << credit.getAmount() << " " << credit.getCurrency() << " " << credit.getRate();
    return os;
}

// Хеш-функция для unordered_set
struct BankCreditHash {
    std::size_t operator()(const BankCredit& bc) const {
        using std::size_t;
        using std::hash;
        using std::string;

        size_t res = 17;
        res = res * 31 + hash<string>()(bc.getName());
        res = res * 31 + hash<double>()(bc.getAmount());
        res = res * 31 + hash<string>()(bc.getCurrency());
        res = res * 31 + hash<double>()(bc.getRate());
        return res;
    }
};

// Оператор равенства для unordered_set
struct BankCreditEqual {
    bool operator()(const BankCredit& lhs, const BankCredit& rhs) const {
        return lhs.getName() == rhs.getName() && lhs.getAmount() == rhs.getAmount() && lhs.getCurrency() == rhs.getCurrency() && lhs.getRate() == rhs.getRate();
    }
};

int main() {
    std::ifstream input("input.txt"); // Открытие файла для чтения
    std::ofstream output("output.txt"); // Открытие файла для записи

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<BankCredit> creditsVector; // Вектор для хранения объектов BankCredit
    std::set<BankCredit> creditsSet; // Множество для хранения объектов BankCredit (сортировка по ставке)
    std::unordered_set<BankCredit, BankCreditHash, BankCreditEqual> creditsUnorderedSet; // Неупорядоченное множество для хранения объектов BankCredit

    std::string name;
    double amount, rate;
    std::string currency;

    // Чтение данных из файла и заполнение контейнеров
    while (input >> name >> amount >> currency >> rate) {
        BankCredit credit(name, amount, currency, rate);
        creditsVector.push_back(credit);
        creditsSet.insert(credit);
        creditsUnorderedSet.insert(credit);
    }

    if (input.bad()) {
        std::cerr << "Error reading file!" << std::endl;
        return 1;
    }

    // Вывод исходного вектора в файл
    output << "Original Vector:\n";
    for (const auto& credit : creditsVector) {
        output << credit << "\n";
    }

    // Вывод set в файл
    output << "Set:\n";
    for (const auto& credit : creditsSet) {
        output << credit << "\n";
    }

    // Вывод unordered_set в файл
    output << "Unordered Set:\n";
    for (const auto& credit : creditsUnorderedSet) {
        output << credit << "\n";
    }

    if (!output) {
        std::cerr << "Error writing to file!" << std::endl;
        return 1;
    }

    input.close(); // Закрытие файла для чтения
    output.close(); // Закрытие файла для записи

    return 0;
}