#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int** Creation(int n, int m){
    int** A = new int* [n];
    for(int i = 0; i < n; i++){
        A[i] = new int [m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            A[i][j] = 0;
        }
    }
    return A;
}

void deliting(int** M, int n, int m){
    for(int i = 0; i < n; i++){
        delete[] M[i];
    }
    delete[] M;
}

void filling(int** M, int n, int m){
    cout << endl << "Start filling" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
        }
    }
    cout << "Completed filling" << endl;
}

bool warning(int n, int m){
    if(n!=m){
        return false;
    }
    return true;
}

int sum_main_diag(int** M, int n, int m){
    if(warning(n, m)){
        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += M[i][i];
        return sum;
    }else{
        cout << "ERROR: Wrong dimension";
        return 0;
    }
}

int sum_side_diag(int** M, int n, int m){
    if(warning(n, m)){
        int sum = 0;
        for (int i=0;i<n;i++)
            sum += M[i][n-1-i];
        return sum;
    }else{
        cout << "ERROR: Wrong dimension";
        return 0;
    }
}

void swap_main_side_diag(int** M, int n, int m){
    if(warning(n, m)){
    int i, j, k;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j){
                    k = M[i][j];
                    M[i][j] = M[i][n - j - 1];
                    M[i][n - j - 1] = k;
                }
            }
        }
    }else{
        cout << "ERROR: Wrong dimension";
    }
}

bool isEven(int k){
    if(k % 2 != 0){
        return true;
    }
    return false;
}

void dif_signs_pairs(int** M, int n, int m){
    int k;
    for(int i = 0; i < n; i++){
        k = 0;
        for(int j = 0; j < m - 1; j++){
            if(M[i][j] > 0 and M[i][j + 1] > 0 or M[i][j] < 0 and M[i][j + 1] < 0){
                k++;
            }
        }
        if(k > 0){
            cout << i << " line has " << k << " pairs of numbers with different signs." << endl;
        }
    }
    cout << endl;
}

int fibonacci(int number){
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return fibonacci(number-1) + fibonacci(number-2);
}

int* fibonacci_array(int n){
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        A[i] = fibonacci(i);
    }
    return A;
}

bool check_fib(int** M, int n, int m){
    int* A = fibonacci_array(n);
    bool fib;
    for(int j = 0; j < m; j++){
        fib = true;
        for(int i = 0; i < n and fib == true; i++){
            if(A[i] != M[i][j]){
                fib = false;
            }
        }
        if(fib){
            return fib;
        }
    }
    return fib;
}

void adding_num(int** M, int n, int m, int k){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            M[i][j] += k;
        }
    }
}

void printing(int** M, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int na,ma,nb,mb,nc,mc;

    //first task
    cout << "Enter n and m for matrix A "; cin >> na >> ma;
    int** A = Creation(na, ma);
    filling(A, na, ma);

    cout << "Enter n and m for matrix B "; cin >> nb >> mb;
    int** B = Creation(nb, mb);
    filling(B, nb, mb);

    cout << "Enter n and m for matrix C "; cin >> nc >> mc;
    int** C = Creation(nc, mc);
    filling(C, nc, mc);
    
    //second task
    cout << "First task with matrix A " << endl;
    int sum = sum_main_diag(A, na, ma) + sum_side_diag(A, na, ma);
    if(isEven(sum)){
        swap_main_side_diag(A, na, ma);
    }
    printing(A, na, ma);
    cout << endl;

    //fourth task
    cout << "Second task with matrix B " << endl;
    dif_signs_pairs(B, nb, mb);
    cout << endl;

    //fivth task
    cout << "Third task with matrix C " << endl;
    bool C_fib = check_fib(C, nc, mc);
    if(C_fib){
        adding_num(C, nc, mc, sum_side_diag(C, nc, mc));
    }
    printing(C, nc, mc);
    cout << endl;

    //last task
    deliting(A, na, ma);
    deliting(B, nb, mb);
    deliting(C, nc, mc);




}