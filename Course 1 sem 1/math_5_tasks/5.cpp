#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //четвертая задача
    int n, k = 0, max = 0, last = 0, first = 0; cout << "Enter N "; cin >> n;
    int a[n];
    // last номер последнего элемента наибольшей последовательности
    // first номер первого элемента последовательности
    // max длина наибольшей последовательности

    for(int i = 0; i < n; i++){
         cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        if(a[i] > 0 and a[i + 1] > 0){
            k++;
        }
        else{
            k = 0;
        }
        if(k > max){
            max = k;
            last = i + 1;
        }
    }
    first = last - max + 1;
    cout << "Max: ";
    for (int i = first - 1; i < max + first; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}