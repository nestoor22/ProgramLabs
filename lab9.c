#include <stdio.h>
#include <math.h>

struct furrs{
    int N;
    double a0,ak,y;

}furr;

int main() {

    double T = 0.01;
    furr.N = 200;
    double x;
    double h = T / furr.N,aak,bbk;
    double sum,Sum,furier,Tp,bk;
    double w = 2 * M_PI / T;
    FILE *myfile, *myfileX, *myfileY, *akk, *bkk,*fur,*furx;
    float X[200] = {};
    float Y[200] = {};
    float AK[20];
    float BK[20];

    myfile = fopen("myfile.txt", "wt");
    myfileX = fopen("myfileX.txt", "wt");
    myfileY = fopen("myfileY.txt", "wt");
    akk = fopen("ak.txt", "wt");
    bkk = fopen("bk.txt", "wt");
    fur = fopen("fur.txt","wt");
    furx = fopen("furx.txt","wt");
    x = 0;

    while (x <= 0.01) {
        if (x <= 0.004) {
            furr.y = 5;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", furr.y);
            fprintf(myfile, "%.6f %.6f \n", x, furr.y);
        }
        if ((x > 0.004) && (x <= 0.005)) {
            furr.y = 5 - 5 *(x-0.004)/0.001;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", furr.y);
            fprintf(myfile, "%.6f %.6f \n", x, furr.y);
        }
        if ((x >= 0.005) && (x <= 0.0075)) {
            furr.y = 5 * (x-0.005) / 0.0025;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", furr.y);
            fprintf(myfile, "%.6f %.6f \n", x, furr.y);
        }
        if ((x>0.0075)&&(x<=0.01)){
            furr.y = 5 - 5*(x-0.0075)/0.0025;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", furr.y);
            fprintf(myfile, "%.6f %.6f \n", x, furr.y);

        }
        x += 0.01 /furr.N;
    }
    fclose(myfile);fclose(myfileX);fclose(myfileY);
    myfileX = fopen("myfileX.txt", "r");
    myfileY = fopen("myfileY.txt", "r");
    int i;
    for (i = 0; !feof(myfileX); i++) {
        fscanf(myfileX, "%f", &X[i]);
        fscanf(myfileY, "%f", &Y[i]);
    }

    int k1,i1,i2;
    for (k1 = 1; k1 <= 10; k1++) {
        Sum = 0;
        for (i1 = 0; i1 <200; i1++) {
            Sum += Y[i1] * cos(k1 * w * X[i1]);
        }
        aak = 2*h*Sum/T;
        AK[k1] = aak;
        fprintf(akk,"%i %f\n",k1,aak);
        Sum = 0;
        for(i2 = 1; i2<200; i2++){
            Sum += Y[i2] * sin(k1 * w * X[i2]);
        }
        bbk = 2*h*Sum/T;
        BK[k1] = bbk;
        fprintf(bkk,"%i %f\n",k1,bbk);
    }
    int i4;
    for (i4 = 0; i4 < 200; i4++) {
        sum += Y[i4];
    }
    int j,m;
    for (j = 1; j <= 20; j++) {
        for (m = 0; m < 200; m++) {
            furr.ak += Y[m] * cos(j * w * X[m]);
            bk += Y[m] * sin(j * w * X[m]);
        }
    }
    furr.ak *= 2*h/T;
    bk *= 2*h/T;
    furr.a0 = 2 * h * sum / T;
    fclose(bkk);fclose(akk);

    int k2;
    for(Tp = 0;Tp<=0.01;Tp += 0.01/200){
        furier = furr.a0/2;
        for(k2=1;k2<=10;k2++){
            furier += AK[k2]*cos(k2*w*Tp)+BK[k2]*sin(k2*w*Tp);
        }
        fprintf(fur,"%f %f\n",Tp,furier);
        fprintf(furx,"%f\n",furier);
    }
    printf("N = %i\nT = %f\na0 = %f\n",furr.N,T,furr.a0);
    printf("ak = %f\nbk = %f\n",furr.ak,bk);
    return 0;
}
