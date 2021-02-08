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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
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

bool isPrime(int k){
    for(int i = 2; i <= sqrt(k); i++){
    if(k % i == 0){
        return false;
        }
    }
    return true;
}

void filling_prime(int** M, int n, int m){
    deliting(M, 3, 3);
    int k = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            while(!isPrime(k)){
                k++;
            }
            M[i][j] = k;
            k++;
        }
    }
}

bool isEven(int k){
    if(k % 2 == 0){
        return true;
    }
    return false;
}

int column_sum(int** M, int n, int k){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += M[n][k];
    }
    return sum;
}

int line_sum(int** M, int m, int k){
    int sum = 0;
    for(int i = 0; i < m; i++){
        sum += M[k][m];
    }
    return sum;
}

void multiply(int line_A, int column_A, int line_B, int column_B, int** A, int** B, int** C){
    if(column_A != line_B){
        cout << "ERROR - can't multiply" << endl;
    }
    int clA_lnB = column_A;
    for(int i = 0; i < line_A; i++){
        for(int j = 0; j < column_B; j++){
            for(int k = 0; k < clA_lnB; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int min_line_sum(int** M, int n, int m){
    int index = 0;
    int min = line_sum(M, m, 0);
    int  sum = 0;
    for(int i = 1; i < n; i++){
        sum = line_sum(M, m, i);
        if(sum < min){
            min = sum;
            index = i;
        }
    }
    return index;
}

int max_line_sum(int** M, int n, int m){
    int index = 0;
    int max = line_sum(M, m, 0);
    int  sum = 0;
    for(int i = 1; i < n; i++){
        sum = line_sum(M, m, i);
        if(sum > max){
            max = sum;
            index = i;
        }
    }
    return index;
}

void swap_lines_by_sum(int** M, int n, int m){
    int index_min = min_line_sum(M, n, m);
    int index_max = max_line_sum(M, n, m);

    for(int i = 0; i < m; i++){
        swap(M[index_max][i], M[index_min][i]);
    }
}

bool isPolindrome(int** M, int n, int k){
    bool isPolin = true;
    for(int i = 0; i < n / 2 and isPolin; i++){
        if(M[i][k] != M[n - i - 1][k]){
            isPolin = false;
        }
    }
    return isPolin;
}

int* all_polin(int **M, int n, int m){
    int count = 0;
    int* B = new int [m];
    for(int i = 0; i < m; i++){
        B[i] = -1;
    }
    int index = -1;
    for(int i = 0; i < m; i++){
        if(isPolindrome(M, n, i)){
            index++;
            B[index] = i;
        }
    }
    return B;
}

int count_polin(int **M, int n, int m){
    int count = 0;
    int* B = new int [m];
    int index = -1;
    for(int i = 0; i < m; i++){
        if(isPolindrome(M, n, i)){
            count++;
        }
    }
    return count;
}

int column_polin(int** M, int n, int m){
    bool isPolind = true;
    
}

int count_prime_column(int** M, int n, int k){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(M[i][k])){
            count++;
        }
    }
    return count;
}







int main(){

    int n, m, nc, mc;
    cout << "Enter N"; cin >> n;
    cout << "Enter M"; cin >>m;

    //Creation
    int** A = Creation(n, m);
    int** B = Creation(n, m);
    cout << "Enter N for C matrix"; cin >> nc;
    cout << "Enter M for C matrix"; cin >> mc;
    int** C = Creation(nc, mc);
    int** D = Creation(n, m);
    int** E = Creation(m, n);


    //Filling
    filling(A, n, m);
    cout << "End filling" << endl;
    filling(B, n, m);
    cout << "End filling" << endl;
    filling(C, nc, mc);
    cout << "End filling" << endl;
    filling_prime(D, n, m);
    cout << "End filling" << endl;

    //printing
    printing(A, n, m);
    printing(B, n, m);
    printing(C, nc, mc);
    printing(D, n, m);

    //multiply
    multiply(n, m, n, m, A, B, E);
    printing(E,m, n);

    int* K = all_polin(C, nc, mc);
    int count = count_polin(C, nc, mc);
    if(count > 0){
        cout << "Polindrome column's indexes: ";
        int index = 0;
        while(K[index] != -1){
            cout << K[index];
            index++;
        }
    }else{
        cout << "No polindrome in C";
    }
    if(count == 1){
        cout << "Sum of C polindrome column "<< column_sum(C, n, K[0]);
    }else if(count > 2){
        int index = 0;
        int k = 0;
        while(K[index] != -1){
            for(int i = 0; i < nc; i++){
                if(isPrime(C[i][K[index]])){
                    k++;
                }
            }
            index++;
        }
        cout << "Count of prime numbers is C polindrome columns is " << k;
    }

    //swap A
    swap_lines_by_sum(A, n, m);
    printing(A, n, m);

    //delition
    deliting(A,n, m);
    deliting(B, n, m);
    deliting(C, n, m);
    deliting(D, n, m);
    deliting(E, m, n);



}