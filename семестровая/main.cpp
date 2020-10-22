#include<iostream>
#include<math.h>
using namespace std;

int main(){

    double x, s, t, e, y, k, y_main;
    int n, i;
    cout << "Enter N: "; cin >> n; n = n - 1;
    e = 0.030;
    
    while (n >= 0){

        cout << "Enter X: ";cin >> x; cout << "x = " << x;
        i = 1;
        s = 1; //значение суммы при i равном 0
        y_main = (3 + 0.2 * x) / (sqrt(1 + x + 0.02 * x * x));
        y = 3 + 0.2 * x; // числитель конечного числа
        x = x + 0.02 * x * x; // преобразование аргумента для вычисления суммы  
        k = 1; //нулевое слагаемое

        while(fabs(k) > e){
            t = (- 1) * (2 * i - 1) * x / (2 * i);
            k = k * t;
            s += k;
            i++;
        }

        cout << ", y = " << y * s << ", y_of_original_function = " << y_main << endl;
        
        
        n--;

    }
        

    return 0;
}