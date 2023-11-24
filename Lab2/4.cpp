#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int k = 1, a, b;
    k = 1;
    cout << "Введите a, удовлетворяющее 1 < a < 20: " << endl;
    cin >> a;
    for (int i = a; i < 20; ++i){
        k = k * i;
    }
    cout << "Произведение чисел от " << a << " до 20 равно: " << k << endl;
    k = 1;
    cout << "Введите b, удовлетворяющее 1 < b < 20: " << endl;
    cin >> b;
    for (int i = 1; i <= b; ++i){
        k = k * i;
    }
    cout << "Произведение чисел от 1 до " << b << " равно: " << k << endl;
    k = 1;
    cout << "Введите a и b, удовлетворяющие условию b >= a, через пробел: " << endl;
    cin >> a >> b;
    for (a; a <= b; ++a){
        k = k * a;
    }
    cout << "Произведение чисел от " << a << " до " << b << " равно: " << k << endl;
}
