#include<iostream>
#include<math.h>
using namespace std;

int main(){
    //Задача а
    // int x, y, z;
    // float u;
    // cin >> x >> y >> z;
    
    // u = 2.3 - x;
    // u /= y;
    // u *= z;
    // u += 3.15;
    // u /= x;
    // u -= y;
    // u *= z;
    // u += x;

    // cout << u;

    
    //Задача б
    // float x, y, z, u;
    // cin >> x >> y >> z;
    
    // u = x + y;
    // u += 2.1;
    // x -= z;
    // x -= 5.6;
    // u /= x;
    // u *= z;
    // u += y;
    // y = z + 1.0;
    // x = z - 2.0;
    // y /= x;
    // u += y;

    // cout << u;


    //Задача в
    // int x, y;
    // y = 1;
    // cin >> x;
    // y = x; 
    // x *= x; // x^2
    // y *= x; // y = x^3
    // x *= x; // x^4
    // x = x * y; // x^7
    // x *= x;  // x^14
    // x *= x; // x ^ 28
    // x *= x; // x^ 56
    // y *= x; // x^59
    // cout << y;

    //задача на ряды 1
    // double x, s, t;
    // int n, i;
    // cin >> x;
    // s = x;
    // cin >> n;
    // for(i = 1; i <= n; i++){
    //     t = (-1)*(x * x * (2 * i - 1) / i / (2 * i + 1));
    //     s += x * t;
    //     cout << s << " ";   
    // }
    // cout << "\n" << s;

    //Задача на ряды 2
    double x, s, t;
    int m, i;
    cin >> m;
    s = 1;
    for(i = 1; i <= m; i++){
        t = (-1) * (2 * m - 1) / 3 / (2 * m + 1);

        s +=  t * 1;

    }

    cout << s;
    



    







    return 0;
}