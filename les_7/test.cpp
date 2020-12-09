#include <iostream>
#include <math.h>
using namespace std;

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


int main(){
    int* A = fibonacci_array(13);
    for(int i = 0; i < 13; i++){
        cout << A[i] << " ";
    }
}