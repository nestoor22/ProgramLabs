#include <stdio.h>
#include <math.h>

int main() {
    double x, y; double a = 3; double b = 4;
    int n = 20;
    double dx = (b - a)/n;
    x = a;
    while (x <= b){
        y = exp(x) + log(x) -10*x;
        printf("(x = %f,y = %f)\n", x, y);
        x += dx;
    }
    return 0;
}