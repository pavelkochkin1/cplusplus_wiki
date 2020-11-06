#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int a[], int n);
void display_array(int M[], int n);

int main()
{
    int a[10]{2, 5, 7, 60, 5, 4, 10, 8, 8, 4};
    
    bubble_sort(a, sizeof(a)/sizeof(a[0]));

    display_array(a, sizeof(a)/sizeof(a[0]));

}

void bubble_sort(int a[], int n){
    int j;
    bool isSwap = true; //optimisation 
    while(isSwap){    
        // for(i = 0; i < n - 1; i++){
            isSwap = false;

            for(j = 0; j < n - 1; j++){
                if(a[j] > a[j + 1]){
                    isSwap = true;
                    swap(a[j], a[j + 1]);
                }
            }
        //}    
    }
}

void display_array(int* M, int n){
    for(int i = 0; i < n; i++){
        cout << M[i] << " ";
    }
}

