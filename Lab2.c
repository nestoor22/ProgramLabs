#include <stdio.h>

int main() {

    float x, y, z, f, max, min;

    x = 2;
    f = x*x;
    y = 5 ;
    z = 5;

    if ((f >= y) && ((f) >= z))
        max = f;
    else if ((y > f) && (y > z))
        max = y;
    else
        max = z;

    if ((f <= y) && (f <= z))
        min = f;
    else if ((y < f) && (y < z))
        min = y;
    else
        min = z;

    float result = max / min + 5;
    printf("%.2f", result);
    return 0;
}
