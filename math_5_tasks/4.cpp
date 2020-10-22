#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //четвертая задача
    int n, k = 0; cout << "Enter N "; cin >> n;
    int a[n], b[n], index = 0; //в массиве В будут храниться повторяющиеся числа
    bool eq = false, isInB = false;
    for(int i = 0; i < n; i++){
         cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n and eq == false; j++){
            if(a[i] == a[j]){
                isInB = false;
                for(int p = 0; p <= index and isInB == false; p++){
                    if(a[i] == b[p]){
                        isInB = true;
                    }
                }
                if(isInB == false){
                    b[index] = a[i];
                    k++;
                    index++;
                }
                eq = true;
            }
        }
        eq = false;
    }

    cout << k <<" numbers: ";

    for(int i = 0; i < index; i++){
        cout << b[i] << " ";
    }


    return 0;
}