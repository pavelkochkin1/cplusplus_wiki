#include <iostream>

using namespace std;




int main(){
    int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int B[3][3] = {{1,3,9}, {2, 5, 1}, {6,3,2}};
    int C[3][3] = {0};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    } 

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    } 

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    } 

}