#include <stdio.h>
#include <math.h>
#include <conio.h>

double determinant(double a, double b, double c, double d)
{
    return a * d - b * c;
}

int main()
{
    double a[2][2] = {{2, 3}, {1, -1}};
    double b[2] = {5, 1};
    double det = determinant(a[0][0], a[0][1], a[1][0], a[1][1]);
    double x = determinant(b[0], a[0][1], b[1], a[1][1]) / det;
    double y = determinant(a[0][0], b[0], a[1][0], b[1]) / det;
    clrscr();

    if (fabs(det) < 1e-9)
    {
        printf("The system has a singular matrix.\n");
        return 1;
    }

    printf("x=%.2lf, y=%2.lf\n", x, y);
    
    getch();
    return 0;
}