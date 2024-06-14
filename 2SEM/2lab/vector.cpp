#include "Vector.h"

Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector(int size) : size(size) {
    data = new int[size];
}

Vector::Vector(const Vector& other) : size(other.size) {
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

Vector::Vector(Vector&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

Vector::~Vector() {
    delete[] data;
}

int& Vector::operator[](int index) {
    return data[index];
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    for (int i = 0; i < vector.size; ++i) {
        os << vector.data[i] << ' ';
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vector) {
    for (int i = 0; i < vector.size; ++i) {
        is >> vector.data[i];
    }
    return is;
}

bool operator<(const Vector& lhs, const Vector& rhs) {
    for (int i = 0; i < lhs.size && i < rhs.size; ++i) {
        if (lhs.data[i] >= rhs.data[i]) {
            return false;
        }
    }
    return lhs.size < rhs.size;
}

bool operator<(const int* lhs, const Vector& rhs) {
    for (int i = 0; i < rhs.size; ++i) {
        if (lhs[i] >= rhs.data[i]) {
            return false;
        }
    }
    return true;
}