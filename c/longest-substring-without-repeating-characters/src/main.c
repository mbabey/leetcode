#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s);

int hasRepeatingCharacters(char *front, char *back);

int main(void)
{
    char *input1;
    char *input2;
    char *input3;
    
    input1 = strdup("pwwkew");
    input2 = strdup("bbbbbb");
    input3 = strdup("abcabcbb");
    
    printf("input1: %d\ninput2: %d\ninput3: %d\n",
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
    int  longest;
    int  current;
    char *front;
    char *back;
    
    longest = 0;
    front = back = s;
    
    // While not at the end of the string.
    while (*back)
    {
        // If a string has repeating characters, move the front pointer.
        if (hasRepeatingCharacters(front, back))
        {
            ++front;
            // The front should never equal the back.
            if (front == back)
            {
                ++back;
            }
        } else // If there are no repeating characters, increase the size of the substring.
        {
            ++back;
        }
        
        current = back - front;
        longest = (longest > current) ? longest : current;
    }
    
    return longest;
}

int hasRepeatingCharacters(char *front, char *back)
{
    int repeat;
    char *c;
    
    // Compare the characters in the string to find if any repeat.
    // Return whether there are repeating characters.
    repeat = 0;
    while (!repeat && front <= back)
    {
        c = front + 1;
        while (c <= back)
        {
            if (*c == *front)
            {
                repeat = 1;
            }
            ++c;
        }
        ++front;
    }
    
    return repeat;
}
