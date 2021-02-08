#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //Первая задача
    int n; cout << "Enter N "; cin >> n;
    int a[n], s = 0;
    bool isNull = false; //булевая для отслеживания нуля 
    for(int i = 0; i < n; i++){
         cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){ 
        if(a[i] == 0){
            for(int j = i - 1; j >= 0 and isNull == false; j--){
                if(a[j] == 0){  
                    isNull = true;
                }
                s += a[j];
            }
        }
    }
    cout << "Sum is " << s; 

    return 0;
}