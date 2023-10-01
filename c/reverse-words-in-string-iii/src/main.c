#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseWords(char *s);

int main(void)
{
    char *s1 = strdup("Let's take LeetCode contest");
    char *s2 = strdup("God Ding");
    char *s3 = strdup("Onomatopoeia");
    char *s4 = strdup("The quick brown fox jumps over the lazy dog");
    char *s5 = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    
    printf("%s\n", reverseWords(s1));
    printf("%s\n", reverseWords(s2));
    printf("%s\n", reverseWords(s3));
    printf("%s\n", reverseWords(s4));
    printf("%s\n", reverseWords(s5));
    
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(s5);
    
    return EXIT_SUCCESS;
}

char *reverseWords(char *s)
{
    char *s_i;
    char *front;
    char *back;
    char temp;
    
    s_i = s;
    while (*s_i)
    {
        front = s_i;
        while (*s_i && *s_i != ' ') ++s_i; // Move s_i to the end of the word.
        back = s_i - 1;
        while (front < back)
        {
            temp = *front;
            *(front++) = *back;
            *(back--)  = temp;
        }
        while (*s_i && *s_i == ' ') ++s_i; // Move s_i to the start of the next word.
    }
    
    return s;
}
