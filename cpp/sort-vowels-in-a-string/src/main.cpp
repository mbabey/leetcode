#include <iostream>

using namespace std;

class Solution
{
private:
    bool is_vowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

public:
    string sortVowels(string s)
    {
        vector<char> vowels;
        vector<int>  vowel_locations;
        
        for (int i{0}; i < s.size(); ++i)
        {
            if (is_vowel(s[i]))
            {
                vowels.push_back(s[i]);
                vowel_locations.push_back(i);
            }
        }
        
        sort(vowels.begin(), vowels.end());
        
        for (int i{0}; i < vowels.size(); ++i)
        {
            s[vowel_locations[i]] = vowels[i];
        }
        return s;
    }
};

int main()
{
    Solution s;
    
    cout << s.sortVowels("lEetcOde") << endl;
    
    return 0;
}
