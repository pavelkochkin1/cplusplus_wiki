#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isLetter(char a) {
    return ((a >= 97 && a <= 122) or (a >= 65 && a <= 90));
}

char toUpper(char c){
    if(isLetter(c) and (c >= 97 and c <= 122)) return char((int)c - 32);
    return c;
}


int main(){

    //9
    // char a;
    // cout << "Enter your symbol: "; cin >> a;
    // cout << "Code of your symbol: " << (int)a;

    //10
    // int c;
    // cout << "Enter your number: "; cin >> c;
    // cout << "Symbol of this code: " << (char)c;

    //11
    // cout << "Symbol  Code" << endl;
    // for(int i = 33; i <= 126; i++){
    //     cout << (char)i << " " << i << endl;
    // }

    //12 
    // int n1, n2;
    // cout << "Enter first num: "; cin >> n1;
    // cout << "Enter second num: "; cin >> n2;
    // for(int i = n1; i <= n2; i++){
    //     cout << (char)i;
    // }

    //13
    // char str[100];
    // cout << "Enter string: "; cin.getline(str, 100);
    // for(int i = 0; i < strlen(str); i++){
    //     cout << str[i] << char(35);
    // }

    //14
    // char str[10];
    // cout << "Enter string: "; cin.getline(str, 10);
    // int count = 0;

    // for(int i = 0; i < strlen(str); i++){
    //     if(isLetter(str[i])) count++;
    // }

    // cout << "Count of letters in string: " << count;

    //15
    // char str[100];
    // cout << "Enter string: "; cin.getline(str, 100);

    // for(int i = 0; i < strlen(str); i++){
    //     cout << toUpper(str[i]);
    // }

    //16
    char str1[100], str2[100];
    cout << "Enter first string: "; cin.getline(str1, 100);
    cout << "Enter second string: "; cin.getline(str2, 100);
    bool isIn = true;
    int i2;

    for(int i = 0; i < strlen(str2); i++){
        if(str2[i] == str1[0]){
            isIn = true;
            i2 = i + 1;
            cout << "in1" << endl;
            for(int j = 1; j < strlen(str1) and isIn; j++){
                if(str2[i2] != str1[j]) isIn = false;
                i2++;
            }
            i++;
        }
    }

    if(isIn) cout << "YES";
    else cout << "NO";



    return 0;
}