#include <iostream>
#include <string>

using namespace std;

//сортировка по процентам
//vector в deque

class Credit{
public:
    string name;
    unsigned float credit_sum;
    string currency;
    unsigned float interest;
    Credit(string n, unsigned float cr_sum, string cur, float inter){
        name = n;
        credit_sum = cr_sum;
        currency = cur;
        interest = inter;
    }   

};

int main()
{
    return 0;
}
