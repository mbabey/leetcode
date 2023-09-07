#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s);

int main(void)
{
    char *input1;
    char *input2;
    char *input3;
    
    input1 = strdup("abcabcbb");
    input2 = strdup("bbbbb");
    input3 = strdup("pwwkew");
    
    printf("input1: %d\ninput2: %d\n input3: %d\n",
           lengthOfLongestSubstring(input1),
           lengthOfLongestSubstring(input2),
           lengthOfLongestSubstring(input3));
    
    free(input1);
    free(input2);
    free(input3);
    
    return 0;
}

int lengthOfLongestSubstring(char *s)
{

    return 0;
}
