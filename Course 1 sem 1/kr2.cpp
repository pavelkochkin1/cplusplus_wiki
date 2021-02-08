#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int count_dig(int num){
    int count=1;
	while ((num/=10) > 0) count++;
	return count;
}

int digit(int num, int dig){
    int count = count_dig(num);
    num /= pow(10, count - dig);
    return num % 10;
}

bool isPrime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int num_Prime(int num){
    int s = 1, dig;
    int count = count_dig(num);
    for(int i = 1; i <= count; i++){
        dig = digit(num, i);
        if(isPrime(dig)) s*=dig;
    }
    return s;
}

int min_dig(int num){
    int min = digit(num, 1), count = count_dig(num), dig;
    for(int i = 2; i <= count; i++){
        dig = digit(num, i);
        if(dig < min) min = dig;
    }
    return min;
}

int my_pow(int num, int pow){
    int res = 1;
    for(int i = 1; i < pow + 1; i++){
        res *= num;
    }
    return res;
}


int main(){
    int n, m;
    cout << "Enter N and enter M with digit's count >=3: "; cin >> n >> m;
    
    // First task
    cout << "1. Sum of the third digits is - " << digit(n, 3) + digit(m, 3) << endl;

    //Second task
    int s = num_Prime(m);
    if(s!=0){
        cout << "2. Sum of primes - " << s << endl;
    }else{
        cout << "2. No prime digits" << endl;
    }

    //Third task
    cout << "3. The number 2 to the power of the minimum digit of the number a - " << my_pow(2, min_dig(n));



}