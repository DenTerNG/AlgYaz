#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;
//using byte = unsigned char;

void positive_result(){
    cout << "Фигура угрожает полю." << endl;
}

void negative_result(){
    cout << "Фигура не угрожает полю." << endl;
}

pair <int, int> first_input(){
    int a = 0, b = 0;
    cout << "Введите координаты первой шахматной фигуры через пробел: " << endl;
    cin >> a >> b;
    if ((a > 0) && (b > 0) && (a <= 8) && (b <= 8)){
        return make_pair(a, b);
        }
    else{
        cout << "Некорректный ввод. Ошибка." << endl;
        exit(0);
    }

}

pair <int, int> second_input(){
   int a = 0, b = 0;
    cout << "Введите координаты второй шахматной фигуры через пробел: " << endl;
    cin >> a >> b;
    if ((a > 0) && (b > 0) && (a <= 8) && (b <= 8)){
        return make_pair(a, b);
        }
    else{
        cout << "Некорректный ввод. Ошибка." << endl;
        exit(0);
    }

}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    pair <int, int> positionA;
    pair <int, int> positionB;
    //про ладью
    positionA = first_input();
    positionB = second_input();
    if (positionA.first == positionB.first || positionA.second == positionB.second){
        positive_result();
    }
    else{
        negative_result();
    }
    //про слона
    positionA = first_input();
    positionB = second_input();
    if ((abs(positionA.first - positionB.first) / abs(positionA.second - positionB.second)) == 1){
        positive_result();
    }
    else{
        negative_result();
    }
//    про короля
    positionA = first_input();
    positionB = second_input();
    if ((positionA.first + 1 == positionB.first) || (positionA.first - 1 == positionB.first) || (positionA.second + 1 == positionB.second) || (positionA.second - 1 == positionB.second) || (positionB.second == positionA.first + 1) || (positionB.second == positionA.first - 1)){
        positive_result();
    }
    else{
        negative_result();
    }
//    про ферзя
    positionA = first_input();
    positionB = second_input();
    if (((abs(positionA.first - positionB.first) / abs(positionA.second - positionB.second)) == 1 ) ||(positionA.first + 1 == positionB.first) || (positionA.first - 1 == positionB.first) || (positionA.second + 1 == positionB.second) || (positionA.second - 1 == positionB.second)){
        positive_result();
    }
    else{
        negative_result();
    }
    //про пешку
    positionA = first_input();
    positionB = second_input();
    cout << positionA.first << " " << positionA.second << endl;
    cout << positionB.first << " " << positionB.second << endl;
    if (positionA.first + 1 == positionB.second || positionA.second + 1 == positionB.first){
        positive_result();
    }
    else{
        negative_result();
    }
    return 0;
}
