#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo) {
    cout << "| " << setw(3) << a[rowNo][colNo] << " ";
    if (colNo < N - 1) 
        PrintRow(a, rowNo, N, colNo + 1);
}

void PrintRows(int** a, const int K, const int N, int rowNo) {
    PrintRow(a, rowNo, N, 0);
    cout << "|" << endl;

    if (rowNo < K - 1) {
        cout << "-";
        for (int j = 0; j < N; j++) {
            cout << "------"; 
        }
        cout << " " << endl; 
        PrintRows(a, K, N, rowNo + 1);
    }
}


void SearchMaxInEvenRow(int** a, const int N, int rowNo, int colNo, int& maxInRow) {
    if (a[rowNo][colNo] > maxInRow)
        maxInRow = a[rowNo][colNo];
    if (colNo < N - 1)
        SearchMaxInEvenRow(a, N, rowNo, colNo + 1, maxInRow);
}

void SearchMinOfMaxInEvenRows(int** a, const int K, const int N, int rowNo, int& minOfMax) {
    if (rowNo % 2 == 0) {
        int maxInRow = a[rowNo][0];
        SearchMaxInEvenRow(a, N, rowNo, 1, maxInRow);
        if (maxInRow < minOfMax)
            minOfMax = maxInRow;
    }
    if (rowNo < K - 1)
        SearchMinOfMaxInEvenRows(a, K, N, rowNo + 1, minOfMax);
}

int main() {
    srand((unsigned)time(NULL));
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;
    cout << endl;

    int** a = new int*[K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];

    int Low = -9, High = 9;
    CreateRows(a, K, N, Low, High, 0);

   
    for (int j = 0; j < N; j++)
        cout << "------";
    cout << endl;
    PrintRows(a, K, N, 0); 
    for (int j = 0; j < N; j++)
        cout << "------";
    cout << endl;

    int minOfMax = High + 1;  
    SearchMinOfMaxInEvenRows(a, K, N, 0, minOfMax);

    if (minOfMax != High + 1)
        cout << "minOfMax = " << minOfMax << endl;
    else
        cout << "No even rows found or all elements are invalid" << endl;

    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
