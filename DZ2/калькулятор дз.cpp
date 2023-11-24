#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//нужно ввести переменную, которая указывает, принято ли было выражение со скобками или без, чтобы правильно его заменить

string expression;
string numbers("0123456789,."); //набор цифр для проверки
string ops("^*/+-"); // набор операторов для подстановки
string d; // строка для записи полученного значения вместо исходного выражения в строку
int p1, p2; //первый и второй индекс вхождения подвыражения в выражения
void calculator(string expression){
    string temp_expression = expression;
    while(((expression.find("^") != expression.npos) || (expression.find("*") != expression.npos) || (expression.find("/") != expression.npos) || (expression.find("+") != expression.npos) || (expression.find("-") != expression.npos)) && (expression.rfind("-") != 0)){
        int k1 = 0, k2 = 0; //счетчики для открытых и закрытых скобок
        if (temp_expression.find("(") != expression.npos){ //в этом куске проверяем выражение на скобки

            for (int i = 0; i < temp_expression.length(); ++i){
                if (temp_expression[i] == '('){
                    k1 = k1 + 1;
//                    cout << "open brackets: " << k1 << endl;
                }
                if (temp_expression[i] == ')'){
                    k2 = k2 + 1;
//                    cout << "closed brackets: " << k2 << endl;
                }
                if ((k1 == k2) && (k1 != 0)){
//                    cout << "brackets number is same." << endl;
                    p1 = temp_expression.find("(")+1; //берем выражение уже без скобок
                    p2 = i - 1;
//                    cout << "substring indexes: " << p1 << " " << p2 << endl;
                    break;
                }
            }
            temp_expression = temp_expression.substr(p1, p2 - p1 + 1);
            calculator(temp_expression);
        }
        else{
//            cout << "processed expression: " << temp_expression << endl;
            for (int f = 0; f < ops.length(); ++f){
//                cout << "operator: " << ops[f] << endl;
                while (temp_expression.find(ops[f]) != temp_expression.npos){ // здесь ищем числа, окружающие нужный нам оператор
                    int flag = 0;
                    float a = 0, b = 0;
                    int g2 = -1;
                    string n("");
                    string m(""); //строки для записи членов
                    cout << "length: " << temp_expression.length() << endl;
                    for (int i = 0; i < temp_expression.length(); ++i){
                        cout << "i: " << i << endl;
                        cout << "flag: " << flag << endl;
                        cout << "position: " << temp_expression[i] << endl;
                        if (flag == 0){
                            if ((numbers.find(temp_expression[i]) != numbers.npos) || ((i == 0) && (temp_expression[i] == '-')) ){
                                n = n.append(1, temp_expression[i]);
                                cout << "n: " << n << endl;
                            }
                            if ((ops.find(temp_expression[i]) != ops.npos) && (temp_expression[i] != ops[f]) && (i != 0)){
                                n = "";
                                cout << "n cleared" << endl;
                            }
                            if ((temp_expression[i] == ops[f]) && (i != 0)){
                                flag = 1;
                                a = stof(n);
                                g2 = i;
//                                                    cout << "saved n: " << n << endl;
//                                                    cout << "start index n:" << e1 << endl;
                            }
                        }
                        if ((flag == 1) && (i != g2)){
                            if (i == (temp_expression.length() - 1)){
                                m = m.append(1, temp_expression[i]);
                                b = stof(m);
                                cout << "saved m: " << m << endl;
                            }
                            else{
                                if (numbers.find(temp_expression[i]) != numbers.npos){
                                    m = m.append(1, temp_expression[i]);
                                    cout << "m: " << m << endl;
                                }
                                if ((ops.find(temp_expression[i]) != ops.npos)){
                                    b = stof(m);
                                    cout << "saved m: " << m << endl;
                                    break;
                                    break;
                                }

                            }
                        }
                        // сюда можно вставить свитч с операцией в зависимости от опертора.
                    }
                    cout << "a = " << a << endl;
                    cout << "b = " << b << endl;
                    float c = 0;
                    if (ops[f] == '^'){
                        cout << "sqrt" << endl;
                        c = pow(a, b);
                    }
                    if (ops[f] == '*'){
                        cout << "mult" << endl;
                        c = a * b;
                    }
                    if (ops[f] == '/'){
                        cout << "div" << endl;
                        c = a / b;
                    }
                    if (ops[f] == '+'){
                        cout << "sum" << endl;
                        c = a + b;
                    }
                    if (ops[f] == '-'){
                        cout << "sub" << endl;
                        c = a - b;
                    }

                    cout << "c = " << c << endl;
                    string d = to_string(c);
                    a = 0;
                    b = 0;
                    c = 0;
                    expression.replace(g2 - n.length(), n.length() + m.length() + 1, d);
                    cout << "after: " << expression << endl;
                    temp_expression = expression;
                }

            }
        }
    }
    cout << expression << endl;
}




int main()
{
    cout << "Insert text: " << endl;
    cin >> expression;
    calculator(expression);
    return 0;
}
