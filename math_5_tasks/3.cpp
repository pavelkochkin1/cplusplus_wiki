#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //третья задача
    int n; cout << "Enter N "; cin >> n;
    int a[n], s1 = 0, s2 = 0, s = 0;
    string an = "yes";
    bool isSaw = true;
    for(int i = 0; i < n; i++){
         cin >> a[i];
         s += a[i];
    }
    for(int i = 1; i < n - 1 and isSaw == true; i++){
        if((a[i-1] < a[i] and a[i+1] < a[i] or a[i-1] > a[i] and a[i+1] > a[i]) == false){
            isSaw = false;
            an = "no";
        }
    }

    cout << "Answer is " << an; 

    return 0;
}