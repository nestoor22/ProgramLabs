#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double a = 3, b = 4; double x, y, dx;
    int n = 50;
    FILE *lab6tab = fopen("lab6tab.txt","wt");

    x = a;
    dx = (b - a)/n;

    while (x <= b){
        y = exp(x) + log(x) - 10*x;
        fprintf(lab6tab, "%f  %f)\n", x, y);
        x += dx;
    }
    fclose(lab6tab);

    return 0;
/*    plot "lab6tab.txt" w lines
    D:\university\labs\programmingl\lab6\cmake-build-debug>gnuplot*/

}
