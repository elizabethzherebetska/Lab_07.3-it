#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int SumPositiveColumns(int** a, const int rowCount, const int colCount);
void MinSumOfDiagonals(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 10;

    int rowCount, colCount;
    cout << "Enter row count (k): ";
    cin >> rowCount;
    cout << "Enter column count (n): ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);

    Print(a, rowCount, colCount);

    int sum = SumPositiveColumns(a, rowCount, colCount);
    cout << "Sum of elements in columns without negative elements: " << sum << endl;

    MinSumOfDiagonals(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumPositiveColumns(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int j = 0; j < colCount; j++) {
        bool hasNegative = false;
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative) {
            for (int i = 0; i < rowCount; i++) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

void MinSumOfDiagonals(int** a, const int rowCount, const int colCount) {
    int minSum = INT_MAX;

    for (int startCol = 1; startCol < colCount; startCol++) {
        int sum = 0;
        for (int i = 0, j = startCol; i < rowCount && j >= 0; i++, j--) {
            sum += abs(a[i][j]);
        }
        if (sum < minSum)
            minSum = sum;
    }

    for (int startRow = 1; startRow < rowCount; startRow++) {
        int sum = 0;
        for (int i = startRow, j = colCount - 1; i < rowCount && j >= 0; i++, j--) {
            sum += abs(a[i][j]);
        }
        if (sum < minSum)
            minSum = sum;
    }

    cout << "Minimum sum of diagonals parallel to the secondary diagonal: " << minSum << endl;
}
