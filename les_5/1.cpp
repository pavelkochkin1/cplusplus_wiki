#include <iostream>
#include <math.h>
using namespace std;

void creating(int** M, int n, int m);
void filling(int** M, int n, int m);
void printing(int** M, int n, int m);

int main(){
    int n, m, n1, n2, i, j, max, min, sum = 0, index, k, count; 
    cout << "Enter N "; cin >> n;
    cout << "ENter M "; cin >> m;


    // First task
    // int** A = new int* [n];
    // creation(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // cout << "Enter two num for changing:" << endl;;
    // cin >> n1 >> n2;
    
    // for(int i = 0; i < n; i++){
    //     k = A[i][n1];
    //     A[i][n1] = A[i][n2];
    //     A[i][n2] = k;
    // }

    // printing(A, n, m);



    //Second task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // sum = 0;
    // max = 0;
    // index = 0;

    // for(i = 0; i < n; i++){
    //     max += A[i][0];
    // }

    // for(i = 1; i < m; i++){ // column's loop
    //     for(j = 0; j < n; j++){ // line's loop
    //         sum += A[j][i];
    //     }
    //     if(sum > max){
    //         max = sum;
    //         index = i;
    //     }
    //     sum = 0;
    // }

    // cout << "Index of max column " << index;



    // Third task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // min = 0 ;sum = 0; index = 0;

    // for(i = 0; i < m; i++){
    //     min += A[0][i];
    // }

    // for(i = 1; i < n; i++){
    //     for(j = 0; j < m; j++){
    //         sum += A[i][j];
    //     }
    //     if(sum < min){
    //         min = sum;
    //         index = i;
    //     }
    //     sum = 0;
    // }
    // cout << "Index of min line " << index;



    // Fourth task
    // int** A = new int* [n];
    // creation(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // cout << "Positive elements of main diagonal: ";

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < m; j++){
    //         if(i == j and A[i][j] >= 0){
    //             cout << A[i][j] << " ";
    //         }
    //     }
    // }    



    // Fiveth task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // min = A[0][0];

    // for(i = 0; i < n; i++){ // founding min element
    //     for(j = 0; j < m; j++){
    //         if(A[i][j] < min){
    //             min = A[i][j];
    //         }
    //     }
    // }

    // cout << "Indexes of min elements: ";

    // for(i = 0; i < n; i++){ // printing indexes of min elements
    //     for(j = 0; j < m; j++){
    //         if(A[i][j] == min){
    //             cout << "(" << i << "; " << j << "), ";
    //         }
    //     }
    // }  



    // Sixth task
    
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // int* B = new int [n * m];
    // index = 0;
    // for(i = 0;i < n; i++){ // unwrapping A matrix into B array
    //     for(j = 0; j < m; j++){
    //         B[index] = A[i][j];
    //         index++;
    //     }
    // }

    // cout << "1D array: ";
    // for(i = 0; i < n * m; i++){ // printing 1-D array
    //     cout << B[i] << " ";
    // }



    // Seventh task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);
    
    // for(i = 0; i < m; i++){
    //     max = A[i][0];
    //     for(j = 0; j < n; j++){
    //         if(A[j][i] > max){
    //             max = A[j][i];
    //         }
    //     }
    //     cout << "Max element of " << i << " column is " << max << endl;
    // }



    // Eighth task
    // int** A = new int* [n];
    // creation(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // cout << "Enter K "; cin >> k;
    // cout << "K number is found more than three times in lines: ";

    // for(i = 0; i < n; i++){
    //     count = 0;
    //     for(j = 0; j < m; j++){
    //         if(A[i][j] == k){
    //             count++;
    //         }
    //     }
    //     if(count >= 3){
    //             cout << i << " ";
    //         }
    // }



    // Nineth task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);
    // cout << endl;
    
    // int** B = new int* [n];
    // creating(B, n, m);
    // filling(B, n, m);
    // printing(B, n, m);
    // cout << endl;

    // int** C = new int* [n];
    // for(i = 0; i < n; i++){
    //     C[i] = new int [m];
    // }

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < m; j++){
    //         if(A[i][j] > B[i][j]){
    //             C[i][j] = A[i][j];
    //         }else{
    //             C[i][j] = B[i][j];
    //         }
    //     }
    // }

    // printing(C, n, m);



    // Tenth task
    // int** B = new int* [n];
    // creation(A, n, m);
    // filling(A, n, m);

    // for(i = 0; i < n; i++){
    //     sum = 0;
    //     for(j = 0; j < m; j++){
    //         if(j != m - 1){
    //             cin >> B[i][j];
    //             sum += B[i][j];
    //         }else{
    //             B[i][j] = sum;
    //         }
            
    //     }
    // }

    // printing(B, n, m);



    // Eleventh task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // cout << endl;

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < n; j++){
    //         if(i == j){
    //             k = A[i][j];
    //             A[i][j] = A[i][n - j - 1];
    //             A[i][n - j - 1] = k;
    //         }
    //     }
    // }

    // printing(A, n, m);



    // Twelfth task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // int max_of_min = 0;

    // for(j = 0; j < m; j++){
    //     min = A[0][j];
    //     for(i = 0; i < n; i++){
    //         if(A[i][j] < min){
    //             min = A[i][j];
    //         }
    //     }
    //     if(min > max_of_min){
    //         max_of_min = min;
    //     }
    // }

    // cout << "Max of min in columns: " << max_of_min;




    // Thirteenth task
    // int** A = new int* [n];
    // creating(A, n, m);
    // filling(A, n, m);
    // printing(A, n, m);

    // count = 0;

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < m; j++){
    //         if(A[i][j] > 9 and A[i][j] < 100){
    //             count++;
    //         }
    //     }
    // }

    // cout << "Count of 2-digits numbers: " << count;

    

    // Foutreenth task
    // int** B = new int* [n];
    // creating(B, n, m + 1);
    // filling(B, n, m);
    // int* sum_column = new int [m];

    // for(i = 0; i < n; i++){
    //     sum = 0;
    //     for(j = 0; j < m + 1; j++){
    //         if(j != m){
    //             sum += B[i][j];
    //             cout << B[i][j] << " ";
    //         }else{
    //             cout << sum;
    //         }
    //     }
    //     cout << endl;
    // }

    // for(i = 0; i < m; i++){
    //     sum_column[i] = 0;
    //     for(j = 0; j < n; j++){
    //         sum_column[i] += B[j][i];
    //     }
    // }

    // for(i = 0; i < m; i++){
    //     cout << sum_column[i] << " ";
    // }

    return 0;
}




void creating(int** M, int n, int m){
    for(int i = 0; i < n; i++){
       M[i] = new int [m];
    }
}

void filling(int** M, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
        }
    }
}

void printing(int** M, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}