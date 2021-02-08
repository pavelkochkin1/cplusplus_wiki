#include<iostream>
#include<math.h>
using namespace std;

int main(){
    // Первая задача 
    // int n;
    // cin >> n;
    // int s = 0;
    // while(n > 0){
    //     s += (n % 2 == 0) ? (n % 10): 0;
    //     n /= 10;
    // }
    // cout << s;

    //Третья задача
    // int n;
    // cin >> n;
    // int fact = 1;
    // for(int i = 1; i <= n; i++){
    //     fact *= i;
    // }
    // cout << fact;

    //Четвертая задача
    int n,i;
    int count = 0;
    cin >> n;
    while(n > 1){
        bool isPrime = true;
        for(i = 2; i <= sqrt(n) && isPrime == true; i++)
        {
            if(n % i == 0)
            {
                isPrime = false;
            }
        }
        if(isPrime){
            count++;
        }
        cin >> n;
    }

    // cout << count;

    //Седьмая задача
    // int s; cout << "Enter integer\n"; cin >> s;
    // int n; cout << "Enter degree of integer\n"; cin >> n;
    // int st = 1;
    // for(int i = 1; i <= n; i++){
    //     st = st * s;
    // }
    // cout << "Your answer: " << st;
    return 0;
}