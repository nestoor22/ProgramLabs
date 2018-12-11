#include <stdio.h>
#include <math.h>

double integr(double a,double b){
    return pow(b,3)/3 - pow(a,3)/3;
}

int main()
{
    double pohybka, a = 0, b = 5,S = 0, x = a;
    double dx = (b-a)/200;
    while (x<=b)
    {
        x += dx;
        S += x*x;
    }
    S = S*dx;
    pohybka = S - integr(a,b);

    printf("%.4f\n%.4f", S,pohybka);
    return 0;

}