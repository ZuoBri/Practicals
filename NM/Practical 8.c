#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 10

void readMatrix(float a[SIZE][SIZE], int n)
{
    printf("Enter coefficients of Augmented Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
}

void gaussJordan(float a[SIZE][SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!\n");
            exit(0);
        }
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                float ratio = a[j][i] / a[i][i];
                for (int k = 0; k <= n; k++)
                    a[j][k] -= ratio * a[i][k];
            }
    }
}

void solve(float a[SIZE][SIZE], float x[SIZE], int n)
{
    for (int i = 0; i < n; i++)
        x[i] = a[i][n] / a[i][i];
}

void printSolution(float x[SIZE], int n)
{
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %0.3f\n", i, x[i]);
}

int main()
{
    float a[SIZE][SIZE], x[SIZE];
    int n;

    clrscr();

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    readMatrix(a, n);
    gaussJordan(a, n);
    solve(a, x, n);
    printSolution(x, n);

    getch();
    return 0;
}
