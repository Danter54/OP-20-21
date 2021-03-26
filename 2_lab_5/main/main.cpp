#include "Function.h"

#define ONE_AS_TWO

int main()
{
	int* array1 = new int[N*N];
	int** array2 = new int* [N];
	for (int i = 0; i < N; i++) {
		array2[i] = new int[N];		//σβκοφσκοφ
	}


#ifdef ONE_AS_TWO

	printf("One as two: \n");

	One_as_two(array1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%4d",*(array1+i*N+j));
		}
		printf("\n");
	}

#else

	printf("Two as two: \n");

	Two_as_two(array2);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%4d",*(*(array2+i)+j));
		}
		printf("\n");
	}


#endif



	delete[] array1;
	for (int i = 0; i < N; i++) {
		delete[] array2[i];
	}
	delete[] array2;

	return 0;
}