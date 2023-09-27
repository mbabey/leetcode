#include <stdio.h>

#define BASE 10

int addDigits(int num);

int main(void)
{
    int num;
    int ans;
    
    num = 38;
    
    ans = addDigits(num);
    printf("%d\n", ans);
    
    return 0;
}

int addDigits(int num)
{
    // If num is less than 10, return num.
    if (num < BASE)
    {
        return num;
    }
    
    int sum;
    
    // Separate digits of num and sum them.
    sum = 0;
    while (num != 0)
    {
        sum += num % BASE;
        num = num / BASE;
    }
    
    num = addDigits(sum);
    
    return num;
}
