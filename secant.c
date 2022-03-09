#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1.0e-9

double f(double x)
{

	double f1 = pow(x,3)+4*pow(x,2)-10;
	return f1;
}

void secant(double x1, double x2)
{
	double n = 0, xm, x0, c;
	int itr=0;
	if (f(x1) * f(x2) < 0) {
		do {
			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
			c = f(x1) * f(x0);
			x1 = x2;
			x2 = x0;
			itr++;

			if (c == 0)
				break;
			xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
		} while (fabs(xm - x0) >= EPSILON);

		printf("Root of the given equation= %.9lf\n",  x0);
		printf( "Number of iterations : %d\n" , itr);
	} else
		printf("Can not find a root in the given interval");
}

int main()
{
	double x1 = 1, x2 = 2;
	secant(x1, x2);
	return 0;
}

