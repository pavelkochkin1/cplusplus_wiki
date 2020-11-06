#include<iostream>
#include<algorithm>
using namespace std;

void display_array(int M[], int n);

void quicksort(int array[], int start, int end);
int Partition(int targetArray[], int start, int end);

int main()
{
    int a[10]{2, 5, 7, 60, 5, 4, 10, 8, 8, 4};

    display_array(a, sizeof(a)/sizeof(a[0]));

    quicksort(a, 0, sizeof(a)/sizeof(a[0]) - 1);

    display_array(a, sizeof(a)/sizeof(a[0]));

}

void quicksort(int array[], int start, int end){

    if(start >= end){
        return;
    }

    int pivot = Partition(array, start, end); // getting pivot
    quicksort(array, start, pivot - 1); // left side
    quicksort(array, pivot + 1, end);

}

int Partition(int targetArray[], int start, int end){

    int value = targetArray[end];
    int position = start;

    for(int i = start; i < end; i++){
        if(targetArray[i] <= value){
            swap(targetArray[i], targetArray[position]);
            position++;
        }
    }

    targetArray[end] = targetArray[position];
    targetArray[position] = value;
    
    return position;

}


void display_array(int* M, int n){
    for(int i = 0; i < n; i++){
        cout << M[i] << " ";
    }
    cout << endl;
}

