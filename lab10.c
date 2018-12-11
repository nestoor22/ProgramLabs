#include <stdio.h>

int main() {

    FILE *myfile = fopen("furx.txt", "r");
    int i, indmin, indmax;
    float min, max;
    float A[200];
    for (i = 0; i < 200; i++) {
        fscanf(myfile, "%f", &A[i]);
    }
    indmin = 0;
    indmax = 0;
    for (i = 1; i < 200; i++) {
        if (A[indmin] > A[i])
            indmin = i;
        else if (A[indmax] < A[i])
            indmax = i;
    }
    min = A[indmin];
    max = A[indmax];
    printf("min index = %i\nmin value = %f\n"
           "max index = %i\nmax value = %f\n",indmin, min, indmax, max);
    return 0;
}