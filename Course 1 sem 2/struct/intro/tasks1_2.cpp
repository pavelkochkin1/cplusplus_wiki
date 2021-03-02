#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct empl{
        string name; // фамилия
        int age; // возраст
        string spec; // специальность
        int money; // оклад
};

void input(empl* A, int n){
    //заполнение структуры
    cout << "Enter: name age spec money"<< endl;
    for(int i = 0; i < n; i++){
        cin >> A[i].name >> A[i].age >> A[i].spec >> A[i].money;
    }
}

void age35(empl* A, int n){
    // сортировка структуры по общему весу
    cout << endl;
    cout << "Worker with age more 35: ";
    for(int i = 0; i < n; i++){
        if(A[i].age > 35) cout << A[i].name << " ";
    }
    cout << endl;
}

void averageMoney(empl* A, int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += A[i].money;
    }
    cout << "Average earning: " << s / n << endl;
}

void ageSort(empl* A, int n){
    empl tmp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i].age > A[j].age){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

void output(empl* A, int n){
    // вывод структуры
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << A[i].name << " " << A[i].age << " " << A[i].spec << " " << A[i].money << endl;
    }
}

int main(){
    int n;
    cout << "Enter n: "; cin >> n;

    empl* S = new empl[n];

    input(S, n);
    age35(S, n);
    averageMoney(S, n);
    ageSort(S, n);
    output(S, n);


    return 0;
}