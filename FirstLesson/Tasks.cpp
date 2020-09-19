#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    //Третья задача
    /*
    int n = 1;
    cin >> n;
    int factorial = 1;
    for(int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    cout << factorial;
    */ 

    //Четвертая задача
    /*int x = 2;
    int s1 = 0;
    int mn = 0;
    while(x >=2)
    {   
        mn = 0;
        cin >> x;
        if(x < 2)
        {
            break
        }
        for(int i = 1; i<=x;i++)
        {
            if(x % i == 0)
            {
                mn++;
            }
        }
        if(mn == 2)
        {
            s1++;
        }
    }
    cout << s1;
    */

    //Пятая задача
    /*
    int n;
    int x;
    cin >> n;
    int sum = 0;
    int pr = 1;
    while (n > 0)
    {
        x = n % 10;
        sum += x;
        pr *=  x;
        n = n / 10;
    }
    cout << sum << '\n';
    cout << pr;
    */

    //Шестая задача
    /*int n;
    cin >> n;
    int x1 = 0;
    int x2 = 0;
    int x3 = 1;
    for(int i = 1; i <= n; i++)
    {
        cout << x3 << ' ';
        x1 = x2;
        x2 = x3;
        x3 = x1 + x2;  
    }
    */

    //Седьмая задача
    /*int n;
    int x;
    cin >> x;
    cin >> n;
    int pr = 1;
    for(int i = 1; i<=n; i++)
    {
        pr *= x;
    }
    cout << pr;
    */

    //Восьмая задача
    /*
    int m = 0;
    int n = 0;
    cin >> m;
    cin >> n;
    for(m; m <= n; m++)
    {
        cout << m << ' ';
        for(int i = 2; i < m; i++)
        {
            if(m % i == 0)
            {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    */ 

   //Девятая задача
   /*int x;
   cin >> x;
   int x1 = x / 100;
   int x2 = x % 100;
   cout << x1 + x2;
   */

   //Десятое задание
   /*
   int x1;
   int x2;
   cin >> x1;
   cin >> x2;
   for(int i = min(x1,x2); i != 0; i--)
   {
       if(x1 % i == 0 && x2 % i ==0)
       {
           cout << i;
           break;
       }
   }
   */

}  