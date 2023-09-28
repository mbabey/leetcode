#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n);

int main(void)
{
    double x1, x2, x3, x4, x5;
    int n1, n2, n3, n4, n5;
    
    x1 = 2;
    n1 = 10;
    
    x2 = 2.1;
    n2 = 3;
    
    x3 = 2;
    n3 = -2;
    
    x4 = -99.999;
    n4 = INT32_MAX;
    
    x5 = 99.999;
    n5 = INT32_MIN;
    
    printf("%f\n", myPow(x1, n1));
    printf("%f\n", myPow(x2, n2));
    printf("%f\n", myPow(x3, n3));
    printf("%f\n", myPow(x4, n4));
    printf("%f\n", myPow(x5, n5));
    
    return EXIT_SUCCESS;
}

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    if (n == -1)
    {
        return 1 / x;
    }
    
    if (n & 1)
    {
        return myPow(x, n / 2) * myPow(x, n / 2) * ((n < 0) ? 1 / x : x);
    }
    
    return myPow(x, n / 2) * myPow(x, n / 2);
}
