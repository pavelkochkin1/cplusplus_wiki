#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main(){

    //fourth task
    int i, j, n, index = 0; cout << "Enter N "; cin >> n;
    int a[n], b[n];
    bool isInB = false;
    for(int i = 0; i < n; i++){
         cin >> a[i];
    }

    
    for(i = 0; i < n; i++){
        isInB = false;
        for(j = 0; !isInB and j < index; j++){
            if(a[i] == b[j]){
                isInB = true;
            }
        }

        for(j = i + 1; !isInB and j < n; j++){
            if(a[i] == a[j]){
                b[index] = a[i];
                index++;
                isInB = true;
            }
        }
    }

    cout << index << " numbers are repeated several times." << endl << "These are numbers ";
    for(i = 0; i < index; i++){
        cout << b[i] << " ";
    }
    

    return 0;
}