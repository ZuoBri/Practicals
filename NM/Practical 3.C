#include <conio.h>
#include <math.h>
#include <stdio.h>

float f(float x) { return (3 * x) - cos(x) - 1; }
float df(float x) { return 3 + sin(x); }

int main() {
  int itr, maxmitr;
  float h, x0, x1, allerr;
  // clrscr();
  printf("\nEnter x0, allowed error and maximum iterations\n");
  scanf("%f %f %d", &x0, &allerr, &maxmitr);
  for (itr = 1; itr <= maxmitr; itr++) {
    h = f(x0) / df(x0);
    x1 = x0 - h;
    printf(" At Iteration no. %3d, x = %9.6f\n", itr, x1);
    if (fabs(h) < allerr) {
      printf("After %3d iterations, root = %8.6f\n", itr, x1);
      return 0;
      getch();
    }
    x0 = x1;
  }
  getch();
}
