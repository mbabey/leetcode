#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LEN 26
#define ALPHA_ASCII_MOD 'a' // 97

#define IS_COLLISION(start1, end1, start2, end2) \
    ((start1 <= start2 && start2 <= end1) || (start1 <= end2 && end2 <= end1) \
    || (start2 <= start1 && start1 <= end2) || (start2 <= end1 && end1 <= end2))

#define MIN(a, b) (a < b) ? (a) : (b)

struct LookupChar
{
    char c;
    int  shift;
};

struct StartEndPair
{
    int start;
    int end;
};

int minExtraChar(char *s, char **dictionary, int dictionarySize);

struct LookupChar *getAlphabet(const char *text, int *alphabet_size);

bool *generateIdentifierArray(const char *text, int *alphabet_size);

void setLookupTable(const char *word, struct LookupChar *lookup_table, int lookup_table_size);

int setShift(char c, const char *word);

void findMatches(char *text, const char *word, struct LookupChar *lookup_table, int lookup_table_size,
                 struct StartEndPair **start_end_pairs, int *start_end_pairs_size);

int getShift(char c, struct LookupChar *lookup_table, int lookup_table_size);

int determineOptimalSolution(struct StartEndPair *start_end_pairs, int start_end_pairs_size, int text_len);

int compareStartEndPair(const void *sep1, const void *sep2);

int findMinChars(int index, struct StartEndPair *start_end_pairs, int start_end_pairs_size, int remaining_chars);

int main(void)
{
    int remaining_chars;
    
    char *s = strdup("dwmodizxvvbosxxw");
    
    const char *dictionary[16];
    int        dictionarySize = 16;
    
    dictionary[0]  = "ox";
    dictionary[1]  = "lb";
    dictionary[2]  = "diz";
    dictionary[3]  = "gu";
    dictionary[4]  = "v";
    dictionary[5]  = "ksv";
    dictionary[6]  = "o";
    dictionary[7]  = "nuq";
    dictionary[8]  = "r";
    dictionary[9]  = "txhe";
    dictionary[10] = "e";
    dictionary[11] = "wmo";
    dictionary[12] = "cehy";
    dictionary[13] = "tskz";
    dictionary[14] = "ds";
    dictionary[15] = "kzbu";
    
    remaining_chars = minExtraChar(s, dictionary, dictionarySize);
    
    printf("%d\n", remaining_chars);
    
    return 0;
}

int minExtraChar(char *s, char **dictionary, int dictionarySize)
{
    int remaining_chars;
    
    struct LookupChar *alphabet;
    int               alphabet_size;
    
    // Get the alphabet.
    alphabet = getAlphabet(s, &alphabet_size);
    if (!alphabet)
    {
        return -1;
    }
    
    struct StartEndPair *start_end_pairs;
    int                 start_end_pairs_size;
    
    start_end_pairs_size = 0;
    start_end_pairs      = NULL;
    
    // For each word in the dictionary, find matches in s.
    for (int dict_i = 0; dict_i < dictionarySize; ++dict_i)
    {
        setLookupTable(*(dictionary + dict_i), alphabet, alphabet_size);
        findMatches(s, *(dictionary + dict_i), alphabet, alphabet_size,
                    &start_end_pairs, &start_end_pairs_size);
    }
    
    remaining_chars = determineOptimalSolution(start_end_pairs, start_end_pairs_size, 0);
    
    free(alphabet);
    free(start_end_pairs);
    
    return remaining_chars;
}

struct LookupChar *getAlphabet(const char *text, int *alphabet_size)
{
    struct LookupChar *alphabet;
    bool              *identifier;
    
    // Generate the boolean identifier array.
    identifier = generateIdentifierArray(text, alphabet_size);
    if (!identifier)
    {
        return NULL;
    }
    
    // Allocate memory for the alphabet and fill in the letters.
    alphabet = (struct LookupChar *) malloc(sizeof(struct LookupChar) * *alphabet_size);
    if (!alphabet)
    {
        free(identifier);
        return NULL;
    }
    
    // Use the identifier array to generate the alphabet.
    for (int i = 0, a = 0; i < ALPHABET_LEN; ++i)
    {
        if (identifier[i])
        {
            (alphabet + a)->c     = i + ALPHA_ASCII_MOD;
            (alphabet + a)->shift = 0;
            ++a;
        }
    }
    
    free(identifier);
    
    return alphabet;
}

bool *generateIdentifierArray(const char *text, int *alphabet_size)
{
    bool *identifier;
    
    // Initialize a boolean array size 26 to false.
    identifier = (bool *) calloc(ALPHABET_LEN, sizeof(bool));
    if (!identifier)
    {
        return NULL;
    }
    
    // Set the identifier[char] to true where the character is present in the text.
    *alphabet_size = 0;
    for (int i = 0; *(text + i); ++i)
    {
        // If the character is false, flip it and increment the alphabet size.
        if (!identifier[*(text + i) - ALPHA_ASCII_MOD])
        {
            identifier[*(text + i) - ALPHA_ASCII_MOD] = true;
            ++(*alphabet_size);
        }
    }
    
    return identifier;
}

void setLookupTable(const char *word, struct LookupChar *lookup_table, int lookup_table_size)
{
    for (int i = 0; i < lookup_table_size; ++i)
    {
        (lookup_table + i)->shift = setShift((lookup_table + i)->c, word);
    }
}

int setShift(char c, const char *word)
{
    int shift;
    int word_len;
    
    word_len = (int) strlen(word);
    
    // distance from c's rightmost occurrence in the pattern among its first m-1 characters to its right end
    shift = 0;
    for (int i = word_len, match = 0; i > 1 && !match; --i)
    {
        // If the character matches the character at the index in the word.
        if (*(word + i - 1) == c)
        {
            shift = word_len - i;
            match = 1;
        }
    }
    
    // otherwise pattern's length, m
    if (shift == 0)
    {
        shift = word_len;
    }
    
    return shift;
}

void findMatches(char *text, const char *word, struct LookupChar *lookup_table, int lookup_table_size,
                 struct StartEndPair **start_end_pairs, int *start_end_pairs_size)
{
    int text_len;
    int word_len;
    int text_index;
    int shift;
    
    word_len = (int) strlen(word);
    text_len = (int) strlen(text);
    
    text_index = 0;
    
    // Match the last char of word to the char at an index in text.
    // Check the lookup table to see how far to move word across text.
    // Stop when a match is found or when the last character of word falls off the end of text.
    
    while (text_index + word_len - 1 < text_len)
    {
        char comparison_char = *(text + text_index + word_len - 1);
        int  cmp_res;
        
        // Compare the characters in the word to the characters in the text.
        cmp_res = strncmp((text + text_index), word, word_len);
        
        if (cmp_res == 0)
        {
            ++(*start_end_pairs_size);
            *start_end_pairs = (struct StartEndPair *) realloc(*start_end_pairs,
                                                               sizeof(struct StartEndPair) * *start_end_pairs_size);
            (*start_end_pairs + *start_end_pairs_size - 1)->start = text_index;
            (*start_end_pairs + *start_end_pairs_size - 1)->end   = text_index + word_len - 1;
        }
        
        shift = getShift(comparison_char, lookup_table, lookup_table_size);
        text_index += shift;
    }
}

int getShift(char c, struct LookupChar *lookup_table, int lookup_table_size)
{
    int shift;
    
    shift = 1;
    for (int i = 0, match = 0; !match && i < lookup_table_size; ++i)
    {
        if (c == (lookup_table + i)->c)
        {
            shift = (lookup_table + i)->shift;
            match = 1;
        }
    }
    
    return shift;
}

int determineOptimalSolution(struct StartEndPair *start_end_pairs, int start_end_pairs_size, int text_len)
{
    // Find the combination of start and end pairs that minimizes the number of unused characters.
    int min_chars;
    
    qsort(start_end_pairs, start_end_pairs_size, sizeof(struct StartEndPair), compareStartEndPair);
    
    min_chars = findMinChars(0, start_end_pairs, start_end_pairs_size, text_len);
    
    return min_chars;
}

int compareStartEndPair(const void *sep1, const void *sep2)
{
    return ((const struct StartEndPair *) sep1)->start - ((const struct StartEndPair *) sep2)->start;
}

int findMinChars(int index, struct StartEndPair *start_end_pairs, int start_end_pairs_size, int remaining_chars)
{
    if (index >= start_end_pairs_size)
    {
        return remaining_chars;
    }
    
    if (index > 0 && IS_COLLISION((start_end_pairs + index - 1)->start, (start_end_pairs + index - 1)->end,
                                  (start_end_pairs + index)->start, (start_end_pairs + index)->end))
    {
    
    } else
    {
        // Reduce the remaining chars count by the size of the non-colliding substring
        remaining_chars -= (start_end_pairs + index)->end - (start_end_pairs + index)->start + 1;
    }
    
    int res = findMinChars(index + 1, start_end_pairs, start_end_pairs_size, remaining_chars);
    remaining_chars = MIN(remaining_chars, res);
    
    return remaining_chars;
}
