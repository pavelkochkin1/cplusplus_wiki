#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Point{
        int num; //номер пассажира
        int x; // колво вещей
        int y; // общий вес
};

void Input(Point* A, int n){
    //заполнение структуры
    for(int i = 0; i < n; i++){
        cin >> A[i].num >> A[i].x >> A[i].y;
    }
}

void Sort(Point* A, int n){
    // сортировка структуры по общему весу
    Point tmp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i].x > A[j].x){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

void output(Point* A, int n){
    // вывод структуры
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << A[i].num << " " << A[i].x << " " << A[i].y << endl;
    }
}


int main(){
    int n;
    cout << "Enter n: "; cin >> n;

    Point* P = new Point[n];

    Input(P, n);
    Sort(P, n);
    output(P, n);

    return 0;
}