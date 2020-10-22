#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //четвертая задача
    int n, k = 0, max = 0, num = 0, index = 0; cout << "Enter N "; cin >> n;
    int a[n];
    // num номер последнего элемента наибольшей последовательности
    // index номер первого элемента последовательности
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
            num = i + 1;
        }
    }
    index = num - max + 1;
    cout << "Max: ";
    for (int i = index; i < max + index; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Num: " << num << endl;
    cout << "Max: " << max << endl;
    cout << "index: " << index << endl;


    return 0;
}