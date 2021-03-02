#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct bag{
    int num; // номер багажа
    int count; // колво вещей
    int mas; // вес вещей
};

void input(bag* A, int n){
    //заполнение структуры
    cout << "Enter: num count mas"<< endl;
    for(int i = 0; i < n; i++){
        cin >> A[i].num >> A[i].count >> A[i].mas;
    }
}

void minCountMas(bag* A, int n){
    // сортировка структуры по общему весу
    cout << endl;
    cout << "Num of min mas and count: ";
    int min_mas = A[0].mas, min_count = A[0].count, i_mas=0, i_count = 0;
    for(int i = 1; i < n; i++){
        if(A[i].mas  < min_mas){
            i_mas = i;
            min_mas = A[i].mas;
        }
        if(A[i].count  < min_count){
            i_count = i;
            min_count = A[i].count;
        }
    }
    if(i_mas == i_count) cout << "Code of min mas and min count: " << A[i_mas].num;
    else cout << "No min mas and count";
    cout << endl;
}


int main(){
    int n;
    cout << "Enter n: "; cin >> n;

    bag* S = new bag[n];

    input(S, n);
    minCountMas(S, n);

    return 0;
}