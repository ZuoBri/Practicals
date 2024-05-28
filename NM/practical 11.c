// Last square method

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int i, j, k, n;
    double x[10], y[10], a, b;
    double xsum = 0, ysum = 0, x2sum = 2, xysum = 0;

    std::cout << "Enter the no. of data pairs to be enterd: ";
    std::cin >> n;
    std::cout << "Enter the x-axis values: ";

    for (i = 0; i < n; i++)
        std::cin >> x[i];
    std::cout << "Enter the y-axis values: ";
    for (i = 0; i < n; i++)
        std::cin >> y[i];

    for (i = 0; i < n; i++)
    {
        xsum = xsum + x[i];
        ysum = ysum + y[i];
        x2sum = x2sum + pow(x[i], 2);
        xysum = xysum + x[i] * y[i];
    }
    a = (n * xysum - xysum * ysum) / (n * x2sum - xsum * xsum);
    b = (x2sum * ysum - xsum * xysum) / (x2sum * n - xsum * xsum);
    double y_fit[10];
    for (i = 0; i < n; i++)
    {
        y_fit[i] = a * x[i] + b;
    }
    std::cout << "Srno." << std::setw(5) << "x" << std::setw(19) << "y(observation)" << std::setw(19) << "y(fitted)" << std::endl;
    std::cout << "--------------------------------------------------------------\n";
    for(i=0; i< n; i++) {
        std::cout<< i+1<< "." << std::setw(8) << x[i] << std::setw(15) << y[i] << std::setw(18) << y_fit[i] << std::endl;
    }
    std::cout << "\n The linear fit line is of form:\n\n" << a << "x+" << b<< std::endl;
    return 0;
}
