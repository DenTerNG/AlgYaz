#include <iostream>
#include <windows.h>

using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int k;
   cout << "Введите число, для кото ого будет составлена таблица умножения: " << endl;
    cin >> k;
    for (int i = 0; i <= 9; ++i){
        cout << i << "x" << k << "=" << i * k << endl;
    }
    return 0;
}
