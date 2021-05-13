#include "Header_Includer.h"

using namespace std;

class SUM {
private:
	int x;
	int y;
	int sum;

public:
	SUM() {
		x = y = sum = 0;
	}

	SUM(int valueX, int valueY) {
		x = valueX;
		y = valueY;
	}



	int value_X;
	int value_Y;

	void Init_XY() {
		cout << "Введите X -> ";
		cin >> value_X;

		cout << "Введите Y -> ";
		cin >> value_Y;
		
		x = value_X;
		y = value_Y;
	}

	void Print() {
		cout << "===========" << endl;
		cout << "Print()" << endl;
		cout << "X -> " << x << endl;
		cout << "Y -> " << y << endl;
		cout << "Sum -> " << sum << endl;
		cout << "===========" << endl;

	}

	void Sum_XY() {
		sum = x + y;
		cout << "===========" <<endl;
		cout << "Sum_XY()" << endl;
		cout << "Sum -> " << sum << endl;
		cout << "===========" << endl;
	}

};





int main() {
	setlocale(LC_ALL, "RU");

	SUM obj1;

	obj1.Init_XY();
	obj1.Sum_XY();
	obj1.Print();

	SUM obj2;
	SUM* p_obj = &obj2;

	p_obj->Init_XY();
	p_obj->Sum_XY();
	p_obj->Print();


	return 0;
}

	


	


