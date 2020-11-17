#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int DigitCount(int k){
    int count = 0;
    while(k > 0){
        count++;
        k /= 10;
    }
    return count;
} 

int DigitN(int k, int n){
    if(DigitCount(k) < n){
        return -1;
    }else{
        k /= pow(10, n - 1);
        k %= 10;
        return k;
    }
}

bool isPalindrome(int k){
    bool isPal = true;
    int digitcount = DigitCount(k);
    for(int i = 1; i < digitcount / 2 and isPal; i++){
        if(DigitN(k, i) == DigitN(k, digitcount)){
            digitcount--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    int num; int n;
    cout << "Enter ur number: "; cin >> num;
    // cout << "Count of digits in number is " << DigitCount(num) << endl;
    // cout << "Enter number of ur digits: "; cin >> n;
    // cout << "Ur digit is " << DigitN(num, n) << endl;
    if(isPalindrome(num)) cout << "Number is palindrome."; 
    else cout << "Number isn't palindrome";


    return 0;
}