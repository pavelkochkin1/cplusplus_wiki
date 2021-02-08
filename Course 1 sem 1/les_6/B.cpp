#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double side(int x1,int y1,int x2,int y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

struct triangle{
    double a;
    double b;
    double c;
};

bool existence(triangle sample){
	if (sample.a + sample.b < sample.c || sample.a + sample.c < sample.b || sample.b + sample.c < sample.a)
		return false;
	else
		return true;
}

double poluperemetr(triangle sample){
	return (sample.a + sample.b + sample.c) / 2;
}

double square(triangle sample){
    if(existence(sample)){
	double p = poluperemetr(sample);
	double S = sqrt(p * (p - sample.a) * (p - sample.b) * (p - sample.c));
    cout << S << endl;
    return S;
    }else{
        cout << "ERROR - one of the triangles doesn't exist";
    }
    return false;
}

int main(){
    //Entering parameteres
    int x1_1, y1_1, x1_2, y1_2, x1_3, y1_3, x2_1, y2_1, x2_2, y2_2, x2_3, y2_3;
    cout << "Enter x1_1 y1_1 "; cin >> x1_1 >> y1_1;
    cout << "Enter x1_2 y1_2 "; cin >> x1_2 >> y1_2;
    cout << "Enter x1_3 y1_3 "; cin >> x1_3 >> y1_3;
    cout << "Enter x2_1 y2_1 "; cin >> x2_1 >> y2_1;
    cout << "Enter x2_2 y2_2 "; cin >> x2_2 >> y2_2;
    cout << "Enter x2_3 y2_3 "; cin >> x2_3 >> y2_3;

    triangle first;
    first.a = side(x1_1, y1_1, x1_2, y1_2);
    first.b = side(x1_2, y1_2, x1_3, y1_3);
    first.c = side(x1_1, y1_1, x1_3, y1_3);

    triangle second;
    second.a = side(x2_1, y2_1, x2_2, y2_2);
    second.b = side(x2_2, y2_2, x2_3, y2_3);
    second.c = side(x2_1, y2_1, x2_3, y2_3);

    double s1 = square(first); 
    double s2 = square(second);
    if(s1 > s2){
        cout << "Square of first triangle is larger";
    }else{
        if(s1 < s2){
            cout << "Square of second triangle is larger";
        }else{
            cout << "Squares are equal";
        }
    }
    return 0;
}