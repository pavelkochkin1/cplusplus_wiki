#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <stdio.h>
using namespace std;

int** Matr_Creation(int n){
    int** M = new int* [n];
    for(int i = 0; i < n; i++)
        M[i] = new int [n];
    return M;
}

int* Ar_Creation(ifstream& fin, int n){
    int* A = new int [n];
    for(int i = 0; i < n; i++){
        fin >> A[i];
    }
    return A;
}

void filling(ifstream& fin, int** M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> M[i][j];
        }
    }
}

void out(ofstream& fout, double* A, int n){
    for(int i = 0; i < n; i++){
        fout << "X_" << i + 1 << " = " << A[i] << endl;
    }
}

void clearMemory(int** M, int n){
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete [] M;        
}

// Получение матрицы без i-й строки и j-го столбца
void GetMatr(int** M, int** A, int i, int j, int m) {
    int ki, kj, di = 0, dj;
    for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            A[ki][kj] = M[ki + di][kj + dj];
        }
    }
}
// Рекурсивное вычисление определителя
int Determinant(int** M, int n) {
    int i, j, d, k, m;
    int** A;
    A = new int*[n];
    for (i = 0; i < n; i++)
        A[i] = new int[n];
    j = 0; d = 0;
    k = 1; //(-1) в степени i
    m = n - 1;
    if (n < 1) cout << "Определитель вычислить невозможно!";
    if (n == 1) {
        d = M[0][0];
        return(d);
    }
    if (n == 2) {
        d = M[0][0] * M[1][1] - (M[1][0] * M[0][1]);
        return(d);
    }
    if (n > 2) {
        for (i = 0; i < n; i++) {
            GetMatr(M, A, i, 0, n);
            d += k * M[i][0] * Determinant(A, m);
            k = -k; //контроль степени
        }
    }
    cout << d << endl;
    return(d);
}

int** Swap(int** M,int* A, int n, int i){
    int ai = 0;
    int** new_M = Matr_Creation(n);
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(k == i){
                new_M[j][k] = A[ai];
                ai++;
            }else
                new_M[j][k] = M[j][k];
        }
    }
    return new_M;
}

double* answeres(int** M, int* A,int n, int det_m){
    int x;
    double* Ans = new double [n];
    for(int i = 0; i < n; i++){
        Ans[i] = double(Determinant(Swap(M, A, n, i), n)) / double(det_m);
    }
    return Ans;
}

int main(){
    int n;

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n;

    int** M = Matr_Creation(n);
    filling(fin, M, n);

    fin.ignore();

    int* A = Ar_Creation(fin, n);
    out(fout, answeres(M, A, n, Determinant(M, n)), n);
}