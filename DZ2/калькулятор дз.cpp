#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//нужно ввести переменную, которая указывает, принято ли было выражение со скобками или без, чтобы правильно его заменить
string expression;
string numbers("0123456789,"); //набор цифр для проверки
string ops("^*/+-");
string d;
int p1, p2; //первый и второй индекс вхождения подвыражения в выражения
//bool skobki = 0;

void calculator(string expression){
    string temp_expression = expression;
    if(((expression.find("^") != expression.npos) || (expression.find("*") != expression.npos) || (expression.find("/") != expression.npos) || (expression.find("+") != expression.npos) ||  ((expression.find("-") != expression.npos)&& (expression.rfind("-") != 0)))){
//        while(((temp_expression.find("^") != temp_expression.npos) || (temp_expression.find("*") != temp_expression.npos) || (temp_expression.find("/") != temp_expression.npos) || (temp_expression.find("+") != temp_expression.npos) ||  ((temp_expression.find("-") != temp_expression.npos)&& (temp_expression.rfind("-") != 0)))){
            int k1 = 0, k2 = 0; //счетчики для открытых и закрытых скобок
            if (temp_expression.find("(") != temp_expression.npos){ //в этом куске проверяем выражение на скобки
                cout << "обрабатываемое выражение (скобки): " << temp_expression << endl;

                for (int i = 0; i < temp_expression.length(); ++i){
                    if (temp_expression[i] == '('){
                        k1 = k1 + 1;
    //                    cout << "количество открытых скобок: " << k1 << endl;
                    }
                    if (temp_expression[i] == ')'){
                        k2 = k2 + 1;
    //                    cout << "количество закрытых скобок: " << k2 << endl;
                    }
                    if ((k1 == k2) && (k1 != 0)){
    //                    cout << "количество скобок сошлось." << endl;
                        p1 = temp_expression.find("(")+1; //берем выражение уже без скобок
                        p2 = i;
                        cout << "индексы подстроки: " << p1 << " " << p2 << endl;
                        break;
                    }
                }
                temp_expression = temp_expression.substr(p1, p2 - p1);
                calculator(temp_expression);
            }
            else{
    //            skobki = 0;
                cout << "обрабатываемое выражение (вычисления) : " << temp_expression << endl;
                for (int f = 0; f < ops.length(); ++f){
                    cout << "оператор: " << ops[f] << endl;
                    while (temp_expression.find(ops[f]) != temp_expression.npos){ // здесь ищем числа, окружающие нужный нам оператор

                                            int flag = 0;
                                            float a = 0, b = 0;
                                            int g2 = -1;
                                            string n("");
                                            string m(""); //строки для записи членов
                                            cout << "длина: " << temp_expression.length() << endl;
                                            for (int i = 0; i < temp_expression.length(); ++i){
                                                    cout << "i: " << i << endl;
                                                    cout << "флаг: " << flag << endl;
                                                    cout << "положение каретки: " << temp_expression[i] << endl;

                                                    if (flag == 0){
                                                        if ((numbers.find(temp_expression[i]) != numbers.npos) || ((i == 0) && (temp_expression[i] == '-')) ){
                                                            n = n.append(1, temp_expression[i]);
                                                            cout << "n: " << n << endl;
                                                            }
                                                        if ((ops.find(temp_expression[i]) != ops.npos) && (temp_expression[i] != ops[f]) && (i != 0)){
                                                            n = "";
                                                            }
                                                        if ((temp_expression[i] == ops[f]) && (i != 0)){
                                                            flag = 1;
                                                            a = stof(n);
                                                            g2 = i;
                                                            cout << "сохраненный n: " << n << endl;
                                                            }


                                                        }

                                                    if ((i == (temp_expression.length() - 1)) && (m == "")){
                                                            break;
                                                    }
                                                    if ((flag == 1) && (i != g2)){
                                                        if (i == (temp_expression.length() - 1)){
                                                                        m = m.append(1, temp_expression[i]);
                                                                        b = stof(m);
                                                                        cout << "сохраненный m: " << m << endl;
                                                                    }
                                                        else{
                                                            if (numbers.find(temp_expression[i]) != numbers.npos){
                                                                    m = m.append(1, temp_expression[i]);
                                                                    cout << "m: " << m << endl;

                                                            }
                                                            if ((ops.find(temp_expression[i]) != ops.npos)){
                                                                b = stof(m);
                                                                cout << "сохраненный m: " << m << endl;
                                                                break;
                                                            break;
                                                                }

                                                    }
                                                }

                                                }
                    cout << "a = " << a << endl;
                    cout << "b = " << b << endl;
                    float c = 0;
                    if (ops[f] == '^'){
                    cout << "выполняется возведение в степень" << endl;
                    c = pow(a, b);
                    }
                    if (ops[f] == '*'){
                    cout << "выполняется умножение" << endl;
                    c = a * b;
                    }
                    if (ops[f] == '/'){
                    cout << "выполняется деление" << endl;
                    c = a / b;
                    }
                    if (ops[f] == '+'){
                    cout << "выполняется сложение" << endl;
                    c = a + b;
                    }
                    if (ops[f] == '-'){
                    cout << "выполняется вычитание" << endl;
                    c = a - b;
                    }

                    cout << "c = " << c << endl;
                    string d = to_string(c);
                    temp_expression = temp_expression.replace(g2 - n.length(), n.length() + m.length() + 1, d);
                    cout << "выражение после замены: " << temp_expression << endl;
                    }

                        }

                }


//    }
            expression = expression.replace(p1 - 1, temp_expression.length() + 1, temp_expression);
            cout << "полное выражение после замены:" << expression << endl;
            calculator(expression);
    }
    else{
        cout << "результат: " << expression << endl;
    }
}



int main()
{

    setlocale(LC_ALL, "Russian");

    cout << "Введите математическое выражение: " << endl;
    cin >> expression;
    calculator(expression);
    return 0;
}


//    int t; // переменная приоритета операторов
//                            a = 0;
//                            b = 0;
//                            c = 0;
//реализовать запись двух чисел можно было бы через std::pair, либо через массив на две ячейки
