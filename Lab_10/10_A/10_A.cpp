#include <iostream>
using namespace std;


char MoreLess(int a, int b){
	if (a > b) {
		return '>';
	}
	else if (a < b) {
		return '<';
	}
	else return '=';
}
int main()
{
	while (true) {
		setlocale(LC_ALL, "Ru");
		int a, b;
		cout << "Введие 2 числа: ";
		cin >> a >> b;
		cout<< "Ответ: " << a <<' '<< MoreLess(a, b) << ' ' << b<<endl;
	}
}