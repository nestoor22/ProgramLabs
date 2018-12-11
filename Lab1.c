#include <stdio.h>
#include <math.h>

void main() {

	float x = 6.251;
	float y = 0.827;
	float z = 25.001;

	float a = pow(y, cbrt(fabs(x)));
	float b = pow(cos(y), 3);
	float c = fabs(x - y);
	float d = (1 + ((pow(sin(z), 2)) / sqrt(x + y)));
	float f = (exp(fabs(x - y))) + x / 2;
	float all = a + b * c * d / f;

	printf("%.4f", all);

}