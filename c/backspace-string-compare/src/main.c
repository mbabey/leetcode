#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_bool(bool b)
{
    printf("%s\n", b ? "true" : "false");
}

int get_next(char *str, int index);

bool backspaceCompare(char *s, char *t);

int main(void)
{
    const char *s1 = "ab#c", *t1 = "ad#c";
    const char *s2 = "ab##", *t2 = "a#d#";
    const char *s3 = "a#c", *t3 = "b";
    const char *s4 = "abc#", *t4 = "bac#";
    
    print_bool(backspaceCompare(s1, t1));
    print_bool(backspaceCompare(s2, t2));
    print_bool(backspaceCompare(s3, t3));
    print_bool(backspaceCompare(s4, t4));
    
    return EXIT_SUCCESS;
}

bool backspaceCompare(char *s, char *t)
{
    int s_index, t_index;
    
    s_index = get_next(s, (int) strlen(s) - 1);
    t_index = get_next(t, (int) strlen(t) - 1);
    
    // While neither string ptr is at the beginning of the string,
    while (s_index >= 0 && t_index >= 0)
    {
        // If the chars are not equal, the strings are not equal
        if (*(s + s_index) != *(t + t_index)) return false;
        // get the next char in the string
        s_index = get_next(s, s_index - 1);
        t_index = get_next(t, t_index - 1);
    }
    
    return (s_index == t_index);
}

int get_next(char *str, int index)
{
    int b_count;
    
    b_count = 0;
    
    // Rip back along the string from an index.
    for (int i = index; i >= -1; --i)
    {
        // String is empty, return -1.
        if (i < 0)
        {
            index = i;
            break;
        }
        // Char is a backspace; increment the backspace counter.
        if (*(str + i) == '#')
        {
            ++b_count;
            continue;
        }
        // Char is not a backspace, but there are backspaces stacked; decrement the backspace counter.
        if (b_count)
        {
            --b_count;
            continue;
        }
        // Char is not a backspace and there are no backspaces; return the index.
        index = i;
        break;
    }
    
    return index;
}
