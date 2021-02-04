#include <iostream>
#include <ctime>
#define I (10)
using namespace std;

int Foo (int mas[],int N){
	if (N>0){
		if (N == 1) {
			if (mas[0] > 0) {
				return mas[0];
			}
			else return 0;
		}
		if (N > 1) {
			if (mas[N - 1] > 0) {
				return mas[N-1] + Foo(mas, N - 1);
			}
			else return Foo(mas,N-1);
		}
	}
}

int main()
{
	srand(time (NULL));
	int mas[I]{};
	for (int i = 0; i < I; i++) {
		mas[i] = rand()%200-100;
	}

	int N = sizeof(mas) / sizeof(int);
	int sum = 0;
	cout << Foo(mas,N);
	return 0;
}