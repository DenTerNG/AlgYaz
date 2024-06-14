#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    int* data;
    int size;

public:
    Vector();
    Vector(int size);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    int& operator[](int index);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    friend std::istream& operator>>(std::istream& is, Vector& vector);

    friend bool operator<(const Vector& lhs, const Vector& rhs);
    friend bool operator<(const int* lhs, const Vector& rhs);
};

#endif // VECTOR_H