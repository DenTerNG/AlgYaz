#include "Vector.h"
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    int size1, size2;
    inputFile >> size1 >> size2;

    Vector v1(size1), v2(size2);
    inputFile >> v1 >> v2;

    outputFile << (v1 < v2) << std::endl;

    int arr[] = {1, 2, 3};
    outputFile << (arr < v1) << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}