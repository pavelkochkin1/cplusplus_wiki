#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

void stupid_sort(int* A, int n){
    int i = 0, temp;
    while(i < n - 1){
        if(A[i + 1] < A[i]){
            temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
            i = 0;
        }
        else i++;
    }
}

int main(){

    int A[10]{2, 5, 7, 60, 5, 4, 10, 8, 8, 4};

    stupid_sort(A, 10);

    for(int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }

}