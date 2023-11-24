#include <iostream>
#include <windows.h>

using namespace std;




void condtr(){
    cout << "condition is true" << endl;
}

void condfal(){
    cout << "condition is false" << endl;
}

int main(){
    int X, Y, Z;
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите числа X, Y, Z через пробел: " << endl;
    cin >> X >> Y >> Z;
    if (X % 2 == 1 && Y % 2 == 1){
        condtr();
    }
    else{
        condfal();
    }
    if ((X < 20 && Y >= 20) || (X >= 20 && Y < 20)){
        condtr();
    }
    else{
        condfal();
    }
    if (X == 0 || Y == 0){
        condtr();
    }
    else{
        condfal();
    }
    if (X < 0 && Y < 0 && Z < 0){
        condtr();
    }
    else{
        condfal();
    }
    if ((X % 5 == 0 && Y  % 5 != 0 && Z % 5 != 0) || (X % 5 != 0 && Y % 5 == 0 && Z & 5 != 0) || (X % 5 != 0 && Y % 5 != 0 && Z % 5 == 0)){
        condtr();
    }
    else{
        condfal();
    }
    if (X > 100 || Y > 100 || Z > 100){
        condtr();
    }
    else{
        condfal();
    }
    
}

