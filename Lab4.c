#include <stdio.h>
#include <math.h>

double y(double x){
    double f = exp(x) + log(x) - 10*x;
    return f;
}

int main() {

    double c = 3.5;
    double d = 3.55;
    double e = 1e-6;
    double test;
    double s;
    while ((d - c) > e){
        s = (c + d)/2;
        if (y(c) * y(s) < 0)
            d = s;
        else
            c = s;

    }
    test = exp(s) + log(s) - 10*s;
    printf(" x = %.4f\n f(x) = %.4f\n", s, test);
    return 0;
}