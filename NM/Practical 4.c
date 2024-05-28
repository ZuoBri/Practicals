#include <conio.h>
#include <math.h>
#include <stdio.h>

float f(float x) { return ((x * x * x) - (2 * x) - 5); }

int main() {
  float a, b, c, e;
  int count = 1, n;
  
  clrscr();
  
  printf("Enter the values of a, b, allowed error, and maximum number of "
         "iterations (separated by spaces):\n");
  scanf("%f %f %f %d", &a, &b, &e, &n);

  if (f(a) == f(b)) {
    printf("Solution cannot be found as the values of a and b are the same.\n");
    return -1;
  }

  do {
    c = (a * f(b) - b * f(a)) / (f(b) - f(a));
    a = b;
    b = c;

    printf("Iteration No-%d    x=%f\n", count, c);
    count++;

    if (count == n) {
      break;
    }
  } while (fabs(f(c)) > e);

  printf("\nThe required solution is %f\n", c);
  getch();
  return 0;
}
