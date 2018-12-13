#include <stdio.h>
#include <math.h>

int main() {

    double T = 0.04;
    int N = 200;
    double x, y;
    double h = T / N,aak,bbk;
    double sum,Sum,furier,Tp,ak,bk,a0;
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

    while (x <= 0.04) {
        if (x <= T/3) {
            y = 5*x/(T/3);
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", y);
            fprintf(myfile, "%.6f %.6f \n", x, y);
        }
        if ((x > T/3) && (x <= T/2)) {
            y = 5;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", y);
            fprintf(myfile, "%.6f %.6f \n", x, y);
        }
        if ((x > T/2) && (x <= 7*T/8)) {
            y = 5 - 11*(x-0.02)/0.015;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", y);
            fprintf(myfile, "%.6f %.6f \n", x, y);
        }
        if ((x>7*T/8)&&(x<=T)){
            y = 6*(x-0.035)/0.005 - 6;
            fprintf(myfileX, "%.5f\n", x);
            fprintf(myfileY, "%.5f\n", y);
            fprintf(myfile, "%.6f %.6f \n", x, y);

        }
        x += 0.04 / N;
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
            ak += Y[m] * cos(j * w * X[m]);
            bk += Y[m] * sin(j * w * X[m]);
        }
    }
    ak *= 2*h/T;
    bk *= 2*h/T;
    a0 = 2 * h * sum / T;
    fclose(bkk);fclose(akk);

    int k2;
    for(Tp = 0;Tp<=0.04;Tp += 0.04/200){
        furier = a0/2;
        for(k2=1;k2<=10;k2++){
            furier += AK[k2]*cos(k2*w*Tp)+BK[k2]*sin(k2*w*Tp);
        }
        fprintf(fur,"%f %f\n",Tp,furier);
        fprintf(furx,"%f\n",furier);
    }
    printf("N = %i\nT = %f\na0 = %f\n",N,T,a0);
    printf("ak = %f\nbk = %f\n",ak,bk);
    return 0;
}
