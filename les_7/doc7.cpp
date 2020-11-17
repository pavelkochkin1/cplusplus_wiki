#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

void Create_ar(int* A,int n){
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
}

void Show_mas(int* A, int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
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

bool E_prime(int* A, int n){
    for(int i = 0; i < n; i++){
        if(isPrime(A[i])){
            return true;
        }
    }
    return false;
}

bool even_number(int k){
    if(k % 2 == 0) return true;
    else return false;
}

bool even_A(int* A,int n){
    bool isEven = true;
    for(int i = 0; i < n; i++){
        if(!even_number(A[i])) return false;
    }
    return true;
}

int Even_sum(int* A, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(even_number(A[i])) sum+=A[i];
    }
    return sum;
}

void Shift(int* A,int n){
    int k = A[n - 1];
    for(int i = n - 1; i > 0; i--){
        A[i] = A[i - 1];
    }
    A[0] = k;
}

void mult_num(int* A, int n, int m){
    for(int i = 0; i < n; i++){
        A[i] *= m;
    }
}




int main(){
    int n; cout << "Enter N "; cin >> n; 
    int* A = new int [n];
    Create_ar(A, n);

    if(even_A(A, n)) Shift(A, n);
    else{
        if(E_prime(A, n) and n >= 3) swap(A[2], A[3]);
    }

    int m;
    cout << "Enter num for multiply "; cin >> m;

    mult_num(A, n, m);
    Show_mas(A, n);



    return 0;
}