#include <stdio.h>
#include <stdbool.h>

#define BASE 10

bool isPalindrome(int x);

void print_bool(bool b);

int main(void)
{
    int num1 = -696;
    int num2 = 1234567899;
    int num3 = 0;
    int num4 = 12345;
    int num5 = 1234554321;
    
    print_bool(isPalindrome(num1));
    print_bool(isPalindrome(num2));
    print_bool(isPalindrome(num3));
    print_bool(isPalindrome(num4));
    print_bool(isPalindrome(num5));
    
    return 0;
}

bool isPalindrome(int x)
{
    if (x < 0) // Negative numbers will never be palindromic.
    {
        return false;
    }
    
    // Initialize return variable.
    bool ans = true;
    
    // Initialize "pointers".
    long lptr;
    long rptr;
    
    rptr = lptr = 1;
    while (x / (lptr * BASE))
    {
        lptr *= BASE;
    }
    
    // Determine if the number is a palindrome using base 10 masking.
    while (lptr > rptr && ans)
    {
        if ((x / lptr) % BASE != (x / rptr) % BASE)
        {
            ans = false;
        }
        
        rptr *= BASE;
        lptr /= BASE;
    }
    
    return ans;
}

void print_bool(bool b)
{
    printf("%s\n", (b) ? "true" : "false");
}
