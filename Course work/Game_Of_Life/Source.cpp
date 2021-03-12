#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

#define FILL_CHAR 219
#define EMPTY_CHAR 255

void print(unsigned int generation, char* print_arr) {
    printf("Generation:%i\n%s\n", generation, print_arr);
}

bool equals(bool* array1, bool* array2, unsigned int n, unsigned int m) {
    for (unsigned int i = 0; i < n; i++) //
        for (unsigned int j = 0; j < m; j++)
            if (array1[i * m + j] != array2[i * m + j])
                return false;
    return true;
}
unsigned short inline get(bool* array, unsigned int n, unsigned int m, unsigned int x, unsigned int y) {
    if (x < 1 || y < 1 || x > m || y > n) return 0;
    return array[(y - 1) * m + (x - 1)];
}

void process_output(bool* array1, bool* array2, char* print_arr, unsigned int n, unsigned int m) {
#pragma omp parallel for
    for (__int64 i = 0; i < (__int64)n; i++)
    {
        for (unsigned int j = 0; j < m; j++) {
            unsigned short alive_near = get(array1, n, m, j, i) +
                get(array1, n, m, j, i + 1) +
                get(array1, n, m, j, i + 2) +
                get(array1, n, m, j + 1, i) +
                get(array1, n, m, j + 1, i + 2) +
                get(array1, n, m, j + 2, i) +
                get(array1, n, m, j + 2, i + 1) +
                get(array1, n, m, j + 2, i + 2);

            if (alive_near > 3)
            {
                array2[i * m + j] = false;
                print_arr[i * (m + 1) + j] = EMPTY_CHAR;
            }
            else if (alive_near > 2)
            {
                array2[i * m + j] = true;
                print_arr[i * (m + 1) + j] = FILL_CHAR;
            }
            else if (alive_near > 1)
            {
                array2[i * m + j] = array1[i * m + j];
                print_arr[i * (m + 1) + j] = array1[i * m + j] ? FILL_CHAR : EMPTY_CHAR;
            }
            else {
                array2[i * m + j] = false;
                print_arr[i * (m + 1) + j] = EMPTY_CHAR;
            }
        }
        print_arr[m + i * (m + 1)] = '\n';
    }
    print_arr[n * (m + 1) - 1] = '\0';
}

void process_no_output(bool* array1, bool* array2, unsigned int n, unsigned int m) {
#pragma omp parallel for
    for (__int64 i = 0; i < (__int64)n; i++)
    {
        for (unsigned int j = 0; j < m; j++) {
            unsigned short alive_near = get(array1, n, m, j, i) +
                get(array1, n, m, j, i + 1) +
                get(array1, n, m, j, i + 2) +
                get(array1, n, m, j + 1, i) +
                get(array1, n, m, j + 1, i + 2) +
                get(array1, n, m, j + 2, i) +
                get(array1, n, m, j + 2, i + 1) +
                get(array1, n, m, j + 2, i + 2);

            if (alive_near > 3
            {
                array2[i * m + j] = false;
            }
            else if (alive_near > 2)
            {
                array2[i * m + j] = true;
            }
            else if (alive_near > 1)
            {
                array2[i * m + j] = array1[i * m + j];
            }
            else {
                array2[i * m + j] = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream in("in.txt");
    unsigned int n;
    unsigned int m;
    unsigned int delay;
    unsigned int max_iterations;
    bool output;
    in >> n >> m >> delay >> max_iterations >> output;


    bool* array1 = new bool[n * m];
    bool* array2 = new bool[n * m];


    if (output)
    {
        char* print_arr = new char[n * (m + 1)];
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                in >> array1[i * m + j];
                print_arr[i * (m + 1) + j] = array1[i * m + j] ? FILL_CHAR : EMPTY_CHAR;
            }
            print_arr[m + i * (m + 1)] = '\n';
        }
        printf_s("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_arr[n * (m + 1) - 1] = '\0';

        print(0, print_arr);
        this_thread::sleep_for(chrono::milliseconds(delay));

        unsigned int generation = 0;

        while (true) {

            chrono::steady_clock::time_point start, end;
            start = chrono::steady_clock::now();

            process_output(array1, array2, print_arr, n, m);
            print(++generation, print_arr);

            if (equals(array1, array2, n, m) || max_iterations != 0 && generation >= max_iterations)
                break;

            end = chrono::steady_clock::now();

            __int64 time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            if (time < delay)
            {
                this_thread::sleep_for(
                    chrono::milliseconds(delay - time));
            }
            bool* temp = array1;
            array1 = array2;
            array2 = temp;
        }
    }


    else {
        chrono::steady_clock::time_point start, end;
        start = chrono::steady_clock::now();
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                in >> array1[i * m + j];
            }
        }
        unsigned int generation = 0;
        while (true) {
            process_no_output(array1, array2, n, m);
            generation++;
            if (equals(array1, array2, n, m) || max_iterations != 0 && generation >= max_iterations)
                break;

            bool* temp = array1;
            array1 = array2;
            array2 = temp;
        }
        end = chrono::steady_clock::now();
        __int64 time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        ofstream out("out.txt");
        out << "Time, milliseconds: " << time;
    }
    return 0;
}