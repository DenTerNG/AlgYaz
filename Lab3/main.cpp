#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	float mas[10] = {1,2,3,4,5,6,7,8,9,10};
	float a;

	std::cout << "������� 1" << std::endl;
	for (int i = 0;i < 10;i++) {
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0;i < 10;i++) {
		mas[i] *= 2;
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "������� ����� �: ";
	std::cin >> a;
	for (int i = 0;i < 10;i++) {
		mas[i] -= a;
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	int del = mas[0];
	for (int i = 0;i < 10;i++) {
		mas[i] /= del;
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "������� 2" << std::endl;
	long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	for (int j = 0;j < 10;j++) {
		sum1 += mas[j];
		sum2 += std::pow(mas[j], 2);
		if (j < 6)
			sum3 += mas[j];
	}
	std::cout << "����� ��������� ������� �����: " << sum1 << std::endl;
	std::cout << "����� ��������� ��������� ������� �����: " << sum2 << std::endl;
	std::cout << "����� ������ 6-� ��������� ������� �����: " << sum3 << std::endl;
	int k1, k2, s1, s2, s3;
	std::cout << "������� ����� k1: "; std::cin >> k1;
	std::cout << "������� ����� k2: "; std::cin >> k2;
	for (int i = 0;k1 < k2;k1++) {
		sum4 += mas[k1];
	}
	std::cout << "����� ��������� � k1 �� k2 �����: " << sum4 << std::endl;
	std::cout << "C������ �������������� ������� �����: " << sum4/10.0 << std::endl;
	std::cout << "������� ����� s1: "; std::cin >> s1;
	std::cout << "������� ����� s2: "; std::cin >> s2;
	s3 = s2 - s1;
	for (int i = 0;s1 < s2;s1++) {
		sum5 += mas[s1];
	}
	std::cout << "C������ �������������� � s1 �� s2 ������� �����: " << sum5/s3 << std::endl;
	std::cout << "������� 3" << std::endl;
	float mas1[20];
	std::cout << "��� ������: ";
	for (int i = 0;i < 20;i++) {
		mas1[i] = 1 + rand() % 50;
		std::cout << mas1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "���������� ������ � ��������� 3 ���������� �������, �������: ";
	int el1, el2, el3;
	el1 = mas1[17]; el2 = mas1[18]; el3 = mas1[19]; mas1[17] = mas1[0];mas1[18] = mas1[1];mas1[19] = mas1[2];
	mas1[0] = el1;mas1[1] = el2;mas1[2] = el3;
	for (int i = 0;i < 20;i++) {
		std::cout << mas1[i] << " ";
	}
	std::cout << "������� 4" << std::endl;
	std::vector<int> mas2 = { 1,2,3,-4,5,6,-7,8,9,11 };+
	for (int i = 0;i < mas2.size();i++) {
		if (mas2[i] < 0) {
			mas2.erase(mas2.cbegin() + i);
			break;
		}
	}
	int kk = 0;
	for (int i = mas2.size()-1; i>0;i-=1) {
		kk += 1;
		if (mas2[i] % 2==0) {
			mas2.erase(mas2.cend() - kk);
			break;
		}
	}
	for (int i = 0;i < mas2.size();i++) {
		std::cout << mas2[i] << " ";
	}
	std::cout << "������� 5" << std::endl;
	std::string c; std::cin >> c;
	if (c.length() % 2 == 0) {
		std::cout << "׸���" << std::endl;
	}
	else {
		std::cout << "�������" << std::endl;
	}
	std::cout << "������� 6" << std::endl;
	std::string surn1; std::cin >> surn1;
	std::string surn2; std::cin >> surn2;
	if (surn1.length() > surn2.length()) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	std::cout << "������� 7" << std::endl;
	std::string the_longest, the_shortest;
	std::string c1; std::cin >> c1;
	std::string c2; std::cin >> c2;
	std::string c3; std::cin >> c3;
	if (c1.length() > c2.length()) {
		if (c2.length() >= c3.length()) {
			the_longest = c1;
			the_shortest = c3;
		}
		else {
			the_longest = c1;
			the_shortest = c2;
		}

	}
	else if (c2.length() >= c1.length()) {
		if (c1.length() >= c3.length()) {
			the_longest = c2;
			the_shortest = c3;
		}
		else {
			the_longest = c2;
			the_shortest = c1;
		}
	}
	else if (c3.length() >= c1.length()) {
		if (c1.length() >= c2.length()) {
			the_longest = c3;
			the_shortest = c2;
		}
		else {
			the_longest = c3;
			the_shortest = c1;
		}

	}
	std::cout << "long: " << the_longest << std::endl;
	std::cout << "short: " << the_shortest << std::endl;
	std::cout << "������� 8" << std::endl;
	std::string word, zv; std::cin >> word;
	for (int i = 0;i < word.length();i++) {
		zv += "*";
	}
	std::cout << zv << word << zv << std::endl;
	std::cout << "������� 9" << std::endl;
	std::string pred; std::cin >> pred;
	double suma=0;
	for (int i = 0;i < pred.length();i++) {
		if (pred[i] == 'a') {
			suma += 1;
		}
	}
	std::cout << "���� � �����: " << (suma/pred.length())*100 << "%" << std::endl;
	std::cout << "������� 10" << std::endl; // ������� 10
	std::string str = "Can you can a can as a canner can can a can?";
	std::vector<char> v1(str.cbegin(), str.cend());
	std::vector<char> v2;
	int i = 1;
	while (i < v1.size()) {
		if ((v1[i] == 'C' || v1[i] == 'c') && v1[i + 1] == 'a' && v1[i + 2] == 'n') {
			v2.push_back('n');
			v2.push_back('e');
			v2.push_back('w');
			v2.push_back('_');
			v2.push_back('w');
			v2.push_back('o');
			v2.push_back('r');
			v2.push_back('d');
			i += 3;
		}
		else {
			v2.push_back(v1[i]);
			i += 1;
		}
	}






	return 0;
}