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
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int param[2][4];
    for(int i = 0; i < 4; i++){
        cout << "Enter x" << i+1 << " y" << i+1 << " ";
        cin >> param[0][i] >> param[1][i];
    }

    double s1 = square(param[0][0], param[1][0], param[0][1], param[1][1], param[0][2], param[1][2]);
    double s2 = square(param[0][0], param[1][0], param[0][3], param[1][3], param[0][2], param[1][2]);
    double s3 = square(param[0][0], param[1][0], param[0][1], param[1][1], param[0][3], param[1][3]);
    double s4 = square(param[0][1], param[1][1], param[0][3], param[1][3], param[0][2], param[1][2]);

    cout << "X max " << "Y_max" << endl;
    bool equal = true;
    if(s1 > s2 and s1 > s3 and s1 > s4){
        cout << param[0][0] << "     " << param[1][0] << endl;
        cout << param[0][1] << "     " << param[1][1] << endl; 
        cout << param[0][2] << "     " << param[1][2] << endl;
        equal = false;
    }
    if(s2 > s1 and s2 > s3 and s2 > s4){
        cout << param[0][0] << "     " << param[1][0] << endl;
        cout << param[0][3] << "     " << param[1][3] << endl; 
        cout << param[0][2] << "     " << param[1][2] << endl;
        equal = false;
    }
    if(s3 > s1 and s3 > s2 and s3 > s4){
        cout << param[0][0] << "     " << param[1][0] << endl;
        cout << param[0][1] << "     " << param[1][1] << endl; 
        cout << param[0][3] << "     " << param[1][3] << endl;
        equal = false;
    }
    if(s4 > s1 and s4 > s3 and s4 > s2){
        cout << param[0][1] << "     " << param[1][1] << endl;
        cout << param[0][3] << "     " << param[1][3] << endl; 
        cout << param[0][2] << "     " << param[1][2] << endl;
        equal = false;
    }
    if(equal){
        cout << "Squares of triangles with this parameteres are equal!";
    }
    



    return 0;
}