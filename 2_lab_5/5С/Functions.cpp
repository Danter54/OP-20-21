

void Buble(int*array ,int size) {
	for (int i = 0; i < size-1; i++) {
		for (int j = (size - 1); j > i; j--) {
			if (array[j-1]>array[j]) {
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

void Insert(int* array, int size) {
	int bufer = 0;
	int i, j;
	for (i = 1; i < size; i++)
	{
		bufer = array[i]; 
		for (j = i - 1; j >= 0 && array[j] > bufer; j--)
			array[j + 1] = array[j];

		array[j + 1] = bufer; 
	}
}

void Gnom(int* array, int size) {
	int n = 0;

	while (n < size - 1) {
		if (*(array + n) <= *(array + n + 1)) {

			n++;
		}
		else {

			int x = *(array + n);
			*(array + n) = *(array + n + 1);
			*(array + n + 1) = x;
			n--;
		}
	}
}

void Selection(int* array, int size) {
	int min = 0; 
	int buf = 0;

	for (int i = 0; i < size; i++)
	{
		min = i; 
		for (int j = i + 1; j < size; j++)
			min = (array[j] < array[min]) ? j : min;
		
		if (i != min)
		{
			buf = array[i];
			array[i] = array[min];
			array[min] = buf;
		}
	}
}