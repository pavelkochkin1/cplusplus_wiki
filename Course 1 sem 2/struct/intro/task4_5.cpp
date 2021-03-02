#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct stud{
    string name;
    int math;
    int inf;
    int ph;
};

void input(stud* A, int n){
    //заполнение структуры
    cout << "Enter: name math inf ph"<< endl;
    for(int i = 0; i < n; i++){
        cin >> A[i].name >> A[i].math >> A[i].inf >> A[i].ph;
    }
}

void losers(stud* A, int n){
    cout << endl << "Name of losers:" << endl;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(A[i].inf == 2 or A[i].math == 2 or A[i].ph == 2){
            count++;
            cout << A[i].name << endl;
        }
    }
    cout << "Count of losers: " << count;
}

void Average(stud* A, int n){
    float aMath = 0, aInf = 0, aPh = 0;
    for(int i = 0; i < n; i++){
        aMath += A[i].math;
        aInf += A[i].inf;
        aPh += A[i].ph;
    }
    cout << endl << "Math average mark: " << aMath / n; 
    cout << endl << "Inf average mark: " << aInf / n; 
    cout << endl << "Ph average mark: " << aPh / n; 
}

int main(){
    int n;
    cout << "Enter n: "; cin >> n;
    stud* A = new stud[n];

    input(A, n);
    Average(A, n);
    losers(A, n);

    return 0;
}