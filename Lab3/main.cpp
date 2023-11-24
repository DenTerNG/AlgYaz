#include <iostream>

using namespace std;



void Task1(){
    cout << "Задание 1" << endl;
    int N = 6, a = 2;
    int d[N]{4, 2, 3, 9, 6, 7, 2};
    cout << "Массив до: " << endl;
    for (int i = 0; i <= N; ++i){
        cout << d[i] << endl;
        d[i] = (d[i] * 2 - a) / a;
    }
    cout << "Массив после: " << endl;
    for (int i = 0; i <= N; ++i){
        cout << d[i] << endl;
    }

}

void Task2(){
    int N = 8;
    int array_sum = 0;
    int k1 = 2;
    int k2 = 6;
    int sred = 0;
    int s1 = 3;
    int s2 = 7;

}

void Task3(){

}

int main(){
    cout << "Please enter task number " << endl;
    setlocale(LC_ALL, "Russian");
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
    }

    return 0;
}