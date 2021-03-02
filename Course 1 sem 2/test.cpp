#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


char* inv(char* str){
    char* str2 = new char [100];
    int j = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'R') str2[strlen(str) - i - 1] = 'L';
        if(str[i] == 'L') str2[strlen(str) - i - 1] = 'R';
    }
    return str2;
}

int main(){
    char* str = new char [100];
    cout << "Enter string: "; cin.getline(str, 80);
    char* str2 = new char[100];
    str2 = inv(str);
    cout << str2;

    return 0;
}