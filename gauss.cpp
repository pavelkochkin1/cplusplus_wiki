#include <iostream>
#include <math.h>
#include <cmath>
#include <conio.h>
using namespace std;

double** Creation(int n){
    //initialization
    int m = n + 1;
    double** A = new double* [n];
    for(int i = 0; i < n; i++){
        A[i] = new double [m];
    }
    return A;
}

void Deletion_mas(double** A,int n){
    int m = n + 1;
    for(int i = 0; i < m; i++){
        delete[] A[i];
    }
    delete[] A;
} 

void Deletion_ans(double* A, int n){
    for(int i = 0; i < n; i++){
      delete[] A;
    }
}

void filling(double** A, int n){
    cout << "Enter the system: " << endl;
    int m = n + 1;
    for(int i = 0; i < n; i++){ 
        cout << "Enter " << i + 1 << " line: ";
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    cout << endl;
}

void printing(double** A, int n){
    int m = n + 1;
    system("cls");
    cout << "System: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double* gauss(double** M, int n){
    // first stage
    double  temp; // temprorary variable
    int k, i, j;
    double* X = new double [n]; // array with answers
 
    for (i = 0; i < n; i++)
    {
        double temp = M[i][i]; // choose numbers on the main diagonal
        for (j = n; j >= i; j--)
            M[i][j] /= temp; // divide the entire line by this number
        for (j = i + 1; j < n; j++) 
        // loop through the lines
        {
            temp = M[j][i]; // choose the element under the main diagonal
            for (k = n; k >= i; k--)
                M[j][k] -= temp * M[i][k]; // subtract from row j row i multiplied by the first element under the main diagonal in row j
        }
    }
    //second stage
    X[n - 1] = M[n - 1][n]; // last x will be last number in last row
    for (i = n - 2; i >= 0; i--)
    // fint the rest
    {
        X[i] = M[i][n]; // assign the last number in the line
        for (j = i + 1; j < n; j++) X[i] -= M[i][j] * X[j]; 
        // subtract those X(multiplied by coefficient) that we already know
    }
    return X;
}

void print_ans(double* A, int n){
  for (int i = 0; i < n; i++)
        cout << "X" << i + 1 << " = " << A[i] << endl;
    cout << endl;
}

int main(){
  int n, i, j;
    while(true){
    cout << "Enter count of equations: "; 
    cin >> n;
    cout << endl;
    double** M = Creation(n);
    filling(M, n);
    printing(M, n);
    double* X = gauss(M, n);
    print_ans(X, n);
    cout << "Press enter to continue...";
    _getch(); //pause in program
    Deletion_ans(X, n);
    Deletion_mas(M, 3);
    system("cls");
    
  }

}

