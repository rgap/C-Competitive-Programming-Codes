#include <iostream>
#include <stdio.h>
using namespace std;

//recta a partir de 2 puntos x1,y1   x2,y2
line L1(y1-y2, x2-x1, (y1-y2)*x1 + (x2-x1)*y1);

//punto medio
point m1((x1+x2)/2, (y1+y2)/2);

//bisector, perpendicular
line b1(-L1.b, L1.a, m1.x*(-L1.b) + m1.y*(L1.a));

//Circulo
//bisectores
line b1(-L1.b, L1.a, m1.x*(-L1.b) + m1.y*(L1.a));
line b2(-L2.b, L2.a, m2.x*(-L2.b) + m2.y*(L2.a));

//centro
point c = intersection(b1, b2);

double r = dist(c, p1);
///////////////////////////

struct point{
    double x,y;
    point(){}
    point(double X, double Y): x(X), y(Y){}
};

struct line{//ax+by=c
    double a,b,c;
    line(){}
    line(double A, double B, double C):a(A),b(B),c(C){}
};

point intersection(const line &L1, const line &L2){//regla de cramer
    double det = (L1.a*L2.b) - (L1.b*L2.a);
    double x = ((L1.c*L2.b)-(L1.b*L2.c))/det;
    double y = ((L1.a*L2.c)-(L1.c*L2.a))/det;
    return point(x,y);
}

int posrectas(line L1, line L2){
    int det=(L1.a*L2.b) - (L1.b*L2.a);
    if(det==0){//son paralelos
        if((L1.c - L1.a)/L1.b == (L2.c - L2.a)/L2.b)
            return 1;//misma linea
        else
            return 2;//no misma linea
    }
    else return 3;//se cortan
}


double distSqr(const point &a, const point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double dist(const point &a, const point &b){//distancia euclidiana
    return sqrt(distSqr(a,b));
}

