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

bool isDot(char a){
    return ((a == '.') or (a==','));
}

void countSpaces_backward(char *str){
    // удаляет пробелы в конце строки
    int spaces = 0;
    for(int i = strlen(str) - 1; i >=0 and !isLetter(str[i]); i++){
        if(str[i] == ' ') spaces++;
    }
    for(int i = 0; i < strlen(str) - spaces; i++){
        str[i] = str[i];
    }
}

int Evaluate(char* str){
    // для третьей задачи
    int res = (int)str[0] - 48;
    int a1;
    for(int i = 1; i < strlen(str); i = i + 2){
        a1 = (int)str[i+1] - 48;
        if(str[i] == '+') res = res + a1;
        if(str[i] == '-') res = res - a1;
    }
    return res;
}

char* inv(char* str, int len){
    // добавляем в конец строки эту же строку
    // при это заменяя R на L и обратно
    for(int i = len - 1; i >= 0; i--){
        if(str[i] == 'L'){
            str[len + (len - i)] = 'R';
        }else{
            str[len + (len - i)] = 'L';
        }
    }
    return str;
}

char* stringRL(int n){
    char* str = new char [100];
    if(n == 0){
        // возвращаем R строку если n = 0
        str[0] = 'R'; str[1] = '\0'; return str;
    }

    char* str1 = stringRL(n - 1); // спускаемся через рекурсию ниже
    int newlen = strlen(str1); // запоминаем длину строки
    for(int i = 0; i < newlen; i++){
    // добавляем новую строку в строку ответа
        str[i] = str1[i];
    }

    // после этого по условию задачи добавляем в конец R
    str[newlen] = 'R';
   
    str = inv(str, newlen); // добавляем в конец эту же строку, но инвертированную и с заменой букв
    
    str[2 * newlen + 1] = '\0'; // в конце добавляем ноль - конец строки

    return str;
}



int main(){
    //First task
    // char str[100];
    // bool isTrue = true;
    // cout << "Enter string: "; cin.getline(str, 80);
    // for(int i = 0; i < strlen(str) and isTrue; i += 2){
    //     if(str[i] != str[i+1]) isTrue = false;
    // }
    // if(isTrue) cout << "True";
    // else cout << "False";


    //Second task
    // char str[100];
    // char sFilt[100];
    // int len = 0;
    // cout << "Enter string: "; cin.getline(str, 100);
    // for(int i = 0; i < strlen(str); i++){
    //     if(isLetter(str[i])){
    //         sFilt[len] = str[i];
    //         len++;
    //     }
    //     if(isDot(str[i])){
    //         sFilt[len] = str[i];
    //         sFilt[len + 1] = ' ';
    //         len += 2;
    //     }
    // }
    // countSpaces_backward(sFilt);
    // sFilt[len] = '\0';
    // cout << "Formated string: " << sFilt;


    //Third task
    // char str[100];
    // int i = 0;
    // bool isCorrect = false;
    // int spaces = 0;
    // cout << "Enter string:"; cin.getline(str, 80);
    // cout << "Answer: " << Evaluate(str);


    //Fourth task
    char str[100];
    int n;
    cout << "Enter n: "; cin >> n;
    cout << "Final: " << stringRL(n);

    return 0;
}