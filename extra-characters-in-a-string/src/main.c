#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LEN 26
#define ALPHA_ASCII_MOD 'a' // 97

struct LookupChar
{
    char c;
    int  shift;
};

int minExtraChar(char *s, char **dictionary, int dictionarySize);

struct LookupChar *getAlphabet(const char *text, int *alphabet_size);

bool *generateIdentifierArray(const char *text, int *alphabet_size);

void setLookupTable(const char *word, struct LookupChar *lookup_table, int lookup_table_size);

int setShift(char c, const char *word);

bool findMatch(char *text, const char *word, struct LookupChar *lookup_table, int lookup_table_size, int *start_index,
               int *end_index);

int getShift(char c, struct LookupChar *lookup_table, int lookup_table_size);

void clearChars(char *text, int start_index, int end_index);

int countRemainingChars(const char *text);

int main(void)
{
    int remaining_chars;
    
    char *s = strdup("dwmodizxvvbosxxw");
    
    const char *dictionary[16];
    int        dictionarySize = 16;
    
    dictionary[0] = "ox";
    dictionary[1] = "lb";
    dictionary[2] = "diz";
    dictionary[3] = "gu";
    dictionary[4] = "v";
    dictionary[5] = "ksv";
    dictionary[6] = "o";
    dictionary[7] = "nuq";
    dictionary[8] = "r";
    dictionary[9] = "txhe";
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
    int  remaining_chars;
    
    struct LookupChar *alphabet;
    int               alphabet_size;
    
    // Get the alphabet.
    alphabet = getAlphabet(s, &alphabet_size);
    if (!alphabet)
    {
        return -1;
    }
    
    int start_index;
    int end_index;
    bool match_found;
    
    // For each word in the dictionary, find matches in s.
    for (int dict_i = 0; dict_i < dictionarySize; ++dict_i)
    {
        setLookupTable(*(dictionary + dict_i), alphabet, alphabet_size);
        match_found = findMatch(s, *(dictionary + dict_i), alphabet, alphabet_size, &start_index, &end_index);
        if (match_found)
        {
            // set *(dict + i) in s to ' '
            clearChars(s, start_index, end_index);
            // Must remove the string AFTER all strings have been checked.
        }
    }
    
    free(alphabet);
    remaining_chars = countRemainingChars(s);
    
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
    alphabet = (struct LookupChar *) malloc(sizeof(struct LookupChar) * (*alphabet_size + 1));
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
            (*(alphabet + a)).c     = i + ALPHA_ASCII_MOD;
            (*(alphabet + a)).shift = 0;
            ++a;
        }
    }
    
    // TODO: may not be necessary if method of counting chars is changed.
    // Add the ' ' character to the alphabet and increase the alphabet size by one.
    (*(alphabet + *alphabet_size)).c = ' ';
    (*(alphabet + *alphabet_size)).shift = 0;
    ++(*alphabet_size);
    
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
        (*(lookup_table + i)).shift = setShift((*(lookup_table + i)).c, word);
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

bool findMatch(char *text, const char *word, struct LookupChar *lookup_table, int lookup_table_size, int *start_index,
               int *end_index)
{
    bool match = false;
    
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
    
    while (!match && text_index + word_len - 1 < text_len)
    {
        char comparison_char = *(text + text_index + word_len - 1);
        int  cmp_res;
        
        // Compare the characters in the word to the characters in the text.
        cmp_res = strncmp((text + text_index), word, word_len);
        
        if (cmp_res == 0)
        {
            match = true;
            *start_index = text_index;
            *end_index   = text_index + word_len - 1;
        } else
        {
            shift = getShift(comparison_char, lookup_table, lookup_table_size);
            text_index += shift;
        }
    }
    
    return match;
}

int getShift(char c, struct LookupChar *lookup_table, int lookup_table_size)
{
    int shift;
    
    shift = 1;
    for (int i = 0, match = 0; !match && i < lookup_table_size; ++i)
    {
        if (c == (*(lookup_table + i)).c)
        {
            shift = (*(lookup_table + i)).shift;
            match = 1;
        }
    }
    
    return shift;
}

void clearChars(char *text, int start_index, int end_index)
{
    for (int i = start_index; i <= end_index; ++i)
    {
        *(text + i) = ' ';
    }
}

int countRemainingChars(const char *text)
{
    int remaining_chars;
    int text_len;
    
    text_len = (int) strlen(text);
    
    remaining_chars = 0;
    for (int i = 0; i < text_len; ++i)
    {
        if (*(text + i) != ' ')
        {
            ++remaining_chars;
        }
    }
    
    return remaining_chars;
}
