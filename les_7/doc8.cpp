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

void Deletion(int** A,int n,int m){
    for(int i = 0; i < n; i++){
        delete[] A[i];
    }
    delete[] A;
} 

void filling(int** A, int n, int m){
    for(int i = 0; i < n; i++){ 
        cout << "Enter " << i + 1 << " line: ";
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    cout << endl;
}

void printing(int** A, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int line_sum(int** A, int m,int k){
    int sum = 0;
    for(int i = 0; i < m; i++){
        sum += A[k][i];
    }
    return sum;
}

void Shift(int** A,int m, int i){
    int k = A[i][m - 1];
    for(int j = m - 1; j > 0; j--){
        A[i][j] = A[i][j - 1];
    }
    A[i][0] = k;
}

void Shift_even_sum(int** A, int m, int n){
    for(int i = 0; i < n; i++){
        if(line_sum(A, m, i) % 2 == 0) Shift(A, m, i);
    }
}

void addition_to_column(int** A, int n, int m, int k){
    for(int i = 0; i < n; i++){
        A[i][m] += k;
    }
}

bool isPrime(int k){
    for(int i = 2; i <= sqrt(k); i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}

bool E_prime(int** A, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!isPrime(A[i][j])){
                return false;
            }
        }
    }
    return true;
}

void addition_if_prime(int** A, int n, int m){
    int sum;
    for(int i = 0; i < n; i++){
        sum = line_sum(A, m, i);
        if(isPrime(sum)){
            for(int j = 0; j < m; j++){
                A[i][j] = A[i][j] + (2*sum);
            }
        }
    }
}

void multiply(int column_B, int line_A, int clA_lnB, int** A, int** B, int** C){

    for(int i = 0; i < line_A; i++){
        for(int j = 0; j < column_B; j++){
            for(int k = 0; k < clA_lnB; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int partition(int* targetA, int start, int end){
    int value = targetA[end];
    int position = start;

    for(int i = start; i < end; i++){
        if(targetA[i] <= value){
            swap(targetA[i], targetA[position]);
            position++;
        }
    }
    targetA[end] = targetA[position];
    targetA[position] = value;

    return position;
}

void quicksort(int* A, int start, int end){
    if(start >= end) return;

    int pivot = partition(A, start, end);
    quicksort(A, start, pivot - 1);
    quicksort(A, pivot + 1, end);
}

void sort(int** A, int n,int m, int j){
    if(j > m){
        cout << "Fewer columns in the matrix";
        return;
    }
    int B[n];
    for(int i = 0; i < n; i++){
        B[i] = A[i][j];
    }

    quicksort(B, 0, n - 1);

    for(int i = 0; i < n; i++){
        A[i][j] = B[n - 1 - i];
    }
}

int main(){
    int n, m;
    cout << "Enter N "; cin >> n;
    cout << "Enter M "; cin >> m;

    int** A = Creation(n, m);
    int** B = Creation(n, m);
    int** C = Creation(n, m);

    filling(A, n, m);
    filling(B, n, m);

    Shift_even_sum(A, n, m);
    printing(A, n, m);
    Shift_even_sum(B, n, m);
    printing(B, n, m);

    if(E_prime(A, n, m)){
        int k;
        cout << "Enter column for sorting "; cin >> k;
        sort(A, n, m, k);
        printing(A, n, m);
    }

    addition_if_prime(A, n, m);
    printing(A, n, m);
    
    if(E_prime(A, n, m) and (E_prime(B, n, m))){
        multiply(n, m, n, A, B, C);
        printing(C, n, m);
    }



    return 0;
}