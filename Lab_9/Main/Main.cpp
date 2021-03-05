#include <iostream>
#include <iomanip>
#define n (10)
using namespace std;

int main() {
    int arr[n][n]{}, count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            arr[i - j][j] = count++;
        }
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i <= n-1 - j; i++) {
            arr[(n-1) - i][j + i] = count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}