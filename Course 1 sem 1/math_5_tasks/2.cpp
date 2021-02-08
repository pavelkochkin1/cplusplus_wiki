#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //Вторая задача
    int n; cout << "Enter N "; cin >> n;
    int a[n], s1 = 0, s2 = 0, s = 0;
    bool isNull = false;
    for(int i = 0; i < n; i++){
         cin >> a[i];
         s += a[i];
    }
   for(int i = 0; i < n and isNull == false; i++){
       if(a[i] == 0){
           isNull = true;
       }
       s1 += a[i];
   }
   isNull = false;
   for(int i = n - 1; i >= 0 and isNull == false; i--){
       if(a[i] == 0){
           isNull = true;
       }
       s2 += a[i];
   }

    cout << "Sum is " << s - s2 - s1; 

    return 0;
}