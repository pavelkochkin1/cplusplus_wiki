#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;

void Create(ifstream& fin, int* A, int n){
    for(int i = 0; i < n; i++){
        fin >> A[i];
    }
}

void Show(ofstream& fout, int* A, int n){
    for(int i = 0; i < n; i++){
        fout << A[i] << " ";
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    int* A = new int [n];
    Create(fin, A, n);
    Show(fout, A, n);



}