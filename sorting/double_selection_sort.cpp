#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void double_selection_sort(int* A, int n){

    int max,min,max_index,min_index,i,j,k;

    k = n - 1;
    for(i = 0; i <= k; i++)
    {   
        max = min = A[i];
        max_index = min_index = i;
            for(j = i + 1; j <= k; j++)
            {
                if(A[j] > max)
                {
                    max = A[j];
                    max_index = j;
                }
                if(A[j] < min)
                {
                    min = A[j];
                    min_index = j;
                }
            }

        if(max_index == i && min_index != k)   //куча if-ов для обработки пограничных значений
        {
            swap(&A[k], &A[max_index]);
            swap(&A[i], &A[min_index]);
        }

        if(min_index == k && max_index != i)
        {
            swap(&A[i], &A[min_index]);
            swap(&A[k], &A[max_index]);
        }

        if(min_index == k && max_index == i)
            swap(&A[k], &A[i]);

        if(min_index != k && max_index != i)
        {
            swap(&A[k], &A[max_index]);
            swap(&A[i], &A[min_index]);
        }
        k--; //сокращаем границу цикла
    
    }
}



int main(){
    int a[10]{2, 5, 7, 60, 5, -4, 10, 8, 8, 4};

    double_selection_sort(a, 10);

    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }


}