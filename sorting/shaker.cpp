#include<iostream>
using namespace std;
void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void shaker_sort(int A[], int n) {
   int i, j, k;
   bool first = true, second = true;
   for(i = 0; i < n && first && second;) {
        first = false;
        second = false;
        for(j = i + 1; j < n; j++) {
            if(A[j] < A[j - 1]){
                swap(&A[j], &A[j - 1]);
                first = true;
            }
        }
        n--;
        for(k = n - 1; k > i; k--) {
            if(A[k] < A[k - 1])
                swap(&A[k], &A[k - 1]);
                second = true;
        }
        i++;
   }
}

int main() {
    int i;
    int a[10]{2, 5, 7, 60, 5, -4, 10, 8, 8, 4};
   
   shaker_sort(a, 10);
   cout<<"\nSorted Data ";
   for (i = 0; i < 10; i++)
      cout << a[i] << " ";
   return 0;
}