#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

bool reverse(char* str){
    bool isTrue = true;
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0 and isTrue == true; i--)
    {
        if(str[i] != str[j]){
            return false;
        }
        j++;
    }
    return true;
}

bool isALetter(char c) {
    return ((c >= 97 && c <= 122) or (c >= 65 && c <= 90));
}

int main(){
    // char str[80] = "Hello";

    // strlen(str);

    // cin.getline(str, 80); // ввод в массив символов, можно с пробелом 

    // cout << str[0];



    // First
    // char str[100];
    // char let;
    // bool isIn = false;
    // cout << "Enter string: "; cin.getline(str, 80);

    // cout << "Enter searching char: "; cin >> let;

    // for (int i = 0; i < strlen(str) - 1 and isIn == false; i++)
    // {
    //     if(let == str[i]){
    //         isIn = true;
    //     }
    // }

    // if(isIn){
    //     cout << "Yes, char " << let << "exists in string.";
    // }else{
    //     cout << "No, char " << let << "doesn's exist in string.";
    // }
    

    // Second
    // char str[100];
    // cout << "Enter string: "; cin.getline(str, 80);

    // for (int i = 0; i < strlen(str); i++)
    // {
    //     if(str[i] == '+'){
    //         str[i] = '-';
    //     }
    // }

    // cout << endl << str;

    // Third task
    // char str[100];
    // cout << "Enter string: "; cin.getline(str, 80);

    // for (int i = 0; i < strlen(str); i++)
    // {
    //     if(str[i] == '.' and str[i+1]=='.' and str[i+2]=='.'){
    //         for(int j = i + 1; j < strlen(str); j++){
    //             str[j] = str[j + 2];
    //         }
    //     }
    // }

    // cout << endl << str;

    // Fourth task
    // char str[100];
    // char str2[100];
    // int j = 0;
    // cout << "Enter string: "; cin.getline(str, 80);

    // for (int i = strlen(str) - 1; i >= 0 ; i--)
    // {
    //     str2[j] = str[i];
    //     j++;
    // }

    // cout << endl << "invert string: " << str2;


    // Fivth task
    // char str[100];
    // int j = 0;
    // bool isTrue = true;
    // cout << "Enter string: "; cin.getline(str, 80);

    // for (int i = strlen(str) - 1; i >= 0 and isTrue == true; i--)
    // {
    //     if(str[i] != str[j]){
    //         isTrue = false;
    //     }
    //     j++;
    // }

    // if(isTrue){
    //     cout << "U r right!";
    // }else{
    //     cout << "U r wrong :(";
    // }


    //Sixth task
    // char str[100];
    // char str2[100];
    // cout << "Enter string 1: "; cin.getline(str, 80);
    // cout << endl << "Enter string 2: "; cin.getline(str2, 80);

    // if(reverse(str) and reverse(str2)){
    //     cout << endl <<"That's true";
    // }else{
    //     cout << endl <<"That's wrong";
    // }


    //Seventh task
    // char str[100];
    // cout << "Enter string: "; cin.getline(str, 80);
    // int count = 1;

    // for(int i = 0; i < strlen(str); i++){
    //     if(str[i] == ' ' or str[i] == ',' or str[i] == '.'){
    //         count++;
    //     }
    // }

    // cout << endl << "Count of words is " << count;



    //Eight task
    const int n = 100;
    char str[n];
    char toFind;
    cout << "Enter your string: "; cin.getline(str, n);
    int numOfWords = 0;

    bool isAWord = true;

    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' ' or str[i] == '.' or str[i] == ',') {
            if(isAWord) numOfWords++;
            //isAWord = true;
        }

        if (!isALetter(str[i])) isAWord = false;
        else isAWord = true;
    }


    if (str[strlen(str) - 1] != ' ' && str[strlen(str) - 1] != '.' && str[strlen(str) - 1] != ',')
    numOfWords++;

    cout << "Count of words: " << numOfWords;

    return 0;
}



