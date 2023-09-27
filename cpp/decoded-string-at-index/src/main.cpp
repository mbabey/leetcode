#include <iostream>

using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        string final;
        
        for (string::iterator it = s.begin(); it != s.end() && k > final.length(); ++it)
        {
            // If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
            if (*it - '0' >= 0 && *it - '0' <= 9)
            {
                string current{final};
                for (int i = 1; i < *it - '0'; ++i)
                {
                    final.append(current); // TODO: Still has memory problems; need sliding window
                }
            } else // If the character read is a letter, that letter is written onto the tape.
            {
                final.append(1, *it);
            }
        }
        
        // Second, get the char at the index. Use empty string if the index is greater than the string length.
//        string kth{((k > final.length()) ?  "" : string(1, final.at(k - 1)))};
        string kth{final.at(k - 1)};
        
        return kth;
    }
};

int main()
{
    
    Solution sol;
    
    string s1, s2, s3, s4, s5;
    int    k1, k2, k3, k4, k5;
    
    s1 = "leet2code3";
    k1 = 10;
    s2 = "ha22";
    k2 = 5;
    s3 = "abc";
    k3 = 3;
    s4 = "lb34";
    k4 = 4;
    s5 = "a2345678999999999999999";
    k5 = 1;
    
    sol.decodeAtIndex(s1, k1); // Output: "leetleetcodeleetleetcodeleetleetcode", "o"
    sol.decodeAtIndex(s2, k2); // Output: "hahahaha", "h"
    sol.decodeAtIndex(s3, k3);
    sol.decodeAtIndex(s4, k4);
    sol.decodeAtIndex(s5, k5);
    
    return 0;
}

