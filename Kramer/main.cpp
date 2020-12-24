// README need to create input.txt file.
// In first line need to write dimension.
// Ignore one line and write matrix from left part of system.
// Ignore one more line and write right part of system in a line.
// Save this file.
#include <iostream>
#include <fstream>
using namespace std;

int** Matr_Creation(int n){
    // Matrix creation
    int** M = new int* [n];
    for(int i = 0; i < n; i++)
        M[i] = new int [n];
    return M;
}

int* Ar_Creation(ifstream& fin, int n){
    //array creation
    int* A = new int [n];
    for(int i = 0; i < n; i++){
        fin >> A[i];
    }
    return A;
}

void filling(ifstream& fin, int** M, int n){
    // matrix filling
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> M[i][j];
        }
    }
}

void out(ofstream& fout, double* A, int n){
    // output of answers
    for(int i = 0; i < n; i++){
        fout << "X_" << i + 1 << " = " << A[i] << endl;
    }
}

void clearMemory_matr(int** M, int n){
    // clearing of matrix memory
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete [] M;        
}

void clearMemory_ar(int* A, int n){
    // clearing of array memory
    for (int i = 0; i < n; i++) {
        delete [] A;
    }       
}

// getting matrix without i line and j column
void GetMatr(int** M, int** A, int i, int j, int m) {
    int ki, kj, di = 0, dj; // di - line offset, dj - column offset
    for (ki = 0; ki < m - 1; ki++) { // checking line's index
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++) { // checking column's index
            if (kj == j) dj = 1;
            A[ki][kj] = M[ki + di][kj + dj];
        }
    }
}
// recursive calculation of the determinant.
int Determinant(int** M, int n) {
    int i, j, d, k, m;
    int** A = Matr_Creation(n - 1); // for func GetMatr()
    j = 0; d = 0;
    k = 1; //(-1) to the i power
    m = n - 1;
    if (n < 1) cout << "The determinant cannot be calculated!";
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
            k = -k; // power control
        }
    }
    cout << d << endl; // message in console for debug

    clearMemory_matr(A, n);

    return(d);
}

int** Swap(int** M,int* A, int n, int i){
    // func to replace a column of a matrix with another column
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

    fin.ignore(); // ignoring empty line    

    int** Alpaca = Matr_Creation(n);
    filling(fin, Alpaca, n);

    fin.ignore(); // ignoring empty line

    int det_m = Determinant(Alpaca, n);
    if(det_m != 0){
        int* Seal = Ar_Creation(fin, n);
        out(fout, answeres(Alpaca, Seal, n, det_m), n);
        clearMemory_ar(Seal, n);
    }else{
        fout << "The determinant of the system is equal to zero, the Kramer method is not suitable.";
    }
    clearMemory_matr(Alpaca, n);
}