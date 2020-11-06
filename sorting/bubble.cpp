#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int a[], int n);

int main()
{
    int a[10]{2, 5, 7, 60, 5, 4, 10, 8, 8, 4};
    
    bubble_sort(a, 10);

    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }

}

void bubble_sort(int a[], int n){
    int j;
    bool isSwap = true;
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

