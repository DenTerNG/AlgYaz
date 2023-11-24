#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;



void Task1(){
    cout << "Задание 1" << endl;
    int N = 6, a = 2;
    int d[N]{4, 2, 3, 9, 6, 7, 2};
    cout << "Массив до: " << endl;
    for (int i = 0; i <= N; ++i){
        cout << d[i] << endl;
        d[i] = (d[i] * 2 - a) / d[0];
    }
    cout << "Массив после: " << endl;
    for (int i = 0; i <= N; ++i){
        cout << d[i] << endl;
    }

}

void Task2(){
    cout << "Задание 2" << endl;
    int N = 6, a = 0, k1, k2, b = 0, s1, s2;
    int d[N]{4, 2, 3, 9, 6, 7, 2};
    for (int i = 0; i <= N; ++i) {
        a += d[i];
    }
    cout << a << endl;

    a = 0;
    for (int i = 0; i <= N; ++i) {
        a += pow(d[i], 2);
    }
    cout << a << endl;

    a = 0;
    for (int i = 0; i <= 6; ++i) {
        a += d[i];
    }
    cout << a << endl;

    a = 0;
    cout << "Введите k1 и k2 через пробел" << endl;
    cin >> k1 >> k2;
    for (int i = k1; i <= k2; ++i) {
        a += d[i];
    }
    cout << a << endl;

    a = 0;
    for (int i = 0; i <= N; ++i) {
        a += d[i];
    }
    b = a / N;
    cout << b << endl;

    a = 0;
    b = 0;
    cout << "Введите s1 и s2 через пробел" << endl;
    cin >> s1 >> s2;
    for (int i = s1; i <= s2; ++i) {
        a += d[i];
    }
    b = a / N;
    cout << b << endl;
}

void Task3(){
    cout << "Задание 3" << endl;
    int N = 19, a;
    int d[N]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <= N; ++i) {
        if (i == 0) {
            a = d[i];
            d[i] = d[17];
            d[17] = a;
        }
        if (i == 1) {
            a = d[i];
            d[i] = d[18];
            d[18] = a;
        }
        if (i == 2) {
            a = d[i];
            d[i] = d[19];
            d[19] = a;
        }
        cout << d[i] << " ";
    }
}

void Task4 () {
    cout << "Задание 4" << endl;
    int N = 6, a, b, ai, bi;
    int d[N]{4, -2, 3, -9, 6, 6, 1};
    int d1[N-2];
    for (int i = 0; i <= N; ++i) {
        if (d[i] < 0) {
            a = d[i];
            ai = i;
            break;
        }
    }
    for (int i = 0; i <= N; ++i) {
        if (d[i] % 2 == 0){
            b = d[i];
            bi = i;
        }
    }

}

void Task5 (){
    cout << "Задание 5" << endl;
    cout << "Введите две фамилии через пробел: ";
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length()) {
        cout << true << endl;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    cout << "Please enter task number " << endl;
    int task_number = 0;
    cin >> task_number;
    switch (task_number) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
    }

    return 0;
}