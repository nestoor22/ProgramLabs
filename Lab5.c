#include <stdio.h>
#include <math.h>

double func(double x){
     return exp(x) + log(x) -10*x;
}
double derivative(double x){
    return exp(x) - 10 + 1/x;
}
int main() {

    double x = 3.5, dx, eps;
    eps = 0.000000001;
    do {
        dx = func(x)/derivative(x);
        x = x-dx;
    }while(fabs(dx)>eps);

    printf("x = %.4f f(x) = %.4f \n", x , func(x));
    return 0;
}