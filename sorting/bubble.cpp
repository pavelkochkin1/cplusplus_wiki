#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int A[], int n);
void display_array(int M[], int n);

int main()
{
    int a[10]{2, 5, 7, 60, 5, -4, 10, 8, 8, 4};
    
    bubble_sort(a, sizeof(a)/sizeof(a[0]));

    display_array(a, sizeof(a)/sizeof(a[0]));

}

void bubble_sort(int A[], int n){
   int i, j;
   bool isSwap = true;
   for(i = 1; i < n && isSwap; i++){
           isSwap = false;
           for(j = 0; j < n - i; j++){
               if(A[j] > A[j + 1]){
                   isSwap = true;
                   swap(A[j], A[j + 1]);
               }
           }
   }
}


void display_array(int* M, int n){
    for(int i = 0; i < n; i++){
        cout << M[i] << " ";
    }
}

