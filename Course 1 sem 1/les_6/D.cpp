#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double side(int x1,int y1,int x2,int y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

bool existence(double a, double b, double c){
	if (a + b < c or a + c < b or b + c < a) return false;
	else return true;
}

double square(int x1, int y1, int x2, int y2, int x3, int y3){
    double a = side(x1,y1,x2,y2);
    double b = side(x1,y1,x3,y3);
    double c = side(x2,y2,x3,y3);
    if(existence(a,b,c)){
        double p = (a + b + c) / 2;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << S << endl;
        return S;
    }else{
        cout << "ERROR - one of the triangles doesn't exist" << endl;
    }
    return 0;
}

int main(){
    //Entering parameteres
    int x1, y1, x2, y2, x3, y3, px, py;
    cout << "Enter x1 y1 "; cin >> x1 >> y1;
    cout << "Enter x2 y2 "; cin >> x2 >> y2;
    cout << "Enter x3 y3 "; cin >> x3 >> y3;
    cout << "Enter px py "; cin >> px >> py;

    double s1 = square(x1, y1, x2, y2, x3, y3);
    double s2 = square(x1, y1, x2, y2, px, py);
    double s3 = square(x1, y1, x3, y3, px, py);
    double s4 = square(x2, y2, x3, y3, px, py);

    if(s1 < s2 + s3 + s4){
        cout << "P is the outer point";
    }else{
        cout << "P is the inside point";
    }
    

    return 0;
}