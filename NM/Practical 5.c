#include <stdio.h>
#include <math.h>
#include <conio.h>

float f(float x)
{
    return pow(x, 3) + 2 * x * x + 10 * x - 20;
}

void calculateRoot(float *a, float *b, float *c, float *result, float err)
{
    float f1 = f(*a);
    float f2 = f(*b);
    float f3 = f(*c);
    float d1 = f1 - f3;
    float d2 = f2 - f3;
    float h1 = *a - *c;
    float h2 = *b - *c;
    float a0 = f3;
    float a1 = (((d2 * pow(h1, 2)) - (d1 * pow(h2, 2))) / ((h1 * h2) * (h1 - h2)));
    float a2 = (((d1 * h2) - (d2 * h1)) / ((h1 * h2) * (h1 - h2)));
    float x = ((-2 * a0) / (a1 + fabs(sqrt(a1 * a1 - 4 * a0 * a2))));
    float y = ((-2 * a0) / (a1 - fabs(sqrt(a1 * a1 - 4 * a0 * a2))));

    if (x >= y)
        *result = x + *c;
    else
        *result = y + *c;
}

int main()
{
    float a, b, c, err;
    float result;
    int maxItr;

    clrscr();

    printf("Enter a, b, c, maximum iterations, and error tolerance: ");
    scanf("%f %f %f %d %f", &a, &b, &c, &maxItr, &err);


    for (int i = 0; i < maxItr; ++i)
    {
        calculateRoot(&a, &b, &c, &result, err);

        if (fabs(result - c) <= err)
            break;

        a = b;
        b = c;
        c = result;

        printf("Current Iteration %d X = %f\n", i, c);
    }

    if (fabs(result - c) <= err)
        printf("The root is %f\n", result);
    else
        printf("Root can't be found using Muller method\n");

    getch();
    return 0;
}
