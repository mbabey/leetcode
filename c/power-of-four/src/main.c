#include <stdio.h>
#include <stdbool.h>

void print_bool(bool b)
{
    printf("%s\n", b ? "true" : "false");
}

bool isPowerOfFour(int n)
{
    while (n >= 4)
    {
        if (n % 4 != 0)
        {
            return false;
        }
        n /= 4;
    }
    if (n == 1)
    {
        return true;
    }
    return false;
}

int main(void)
{
    int num;
    
    num = 4;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 8;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 6;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 3;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 64;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 128;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 65536;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 1;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 2;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    num = 3;
    printf("%d: ", num);
    print_bool(isPowerOfFour(num));
    
    
    return 0;
}
