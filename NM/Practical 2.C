#include <conio.h>
#include <math.h>
#include <stdio.h>

double f(double x) { return x * log10(x) - 1.2; }

void regulaFalsi(double *x, double x0, double x1, double fx0, double fx1, int *itr) {
  *x = ((x0 * fx1) - (x1 * fx0)) / (fx1 - fx0);
  ++(*itr);
  printf("Iteration no. %3d X = %7.5f \n", *itr, *x);
}

int main() {
  int itr = 0, maxmitr;
  double x0, x1, x2, x3, allerr;
  clrscr();
  printf("Enter the values of x0, x1, allowed error and maximum iterations:\n");
  scanf("%lf %lf %lf %d", &x0, &x1, &allerr, &maxmitr);

  regulaFalsi(&x2, x0, x1, f(x0), f(x1), &itr);

  do {
    if (f(x0) * f(x2) < 0)
      x1 = x2;
    else
      x0 = x2;

    regulaFalsi(&x3, x0, x1, f(x0), f(x1), &itr);

    if (fabs(x3 - x2) < allerr) {
      printf("After %d iterations, root = %6.5f\n", itr, x3);
      return 0;
    }

    x2 = x3;
  } while (itr < maxmitr);
  getch();
}
