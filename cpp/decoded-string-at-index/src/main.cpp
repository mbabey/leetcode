#include <iostream>

using namespace std;

class Solution
{
public:
    
    /**
     * Reverse traversal algorithm. Relies on the fact that the encoded string s has cycles; the kth character can be
     * mapped to any cycle. This algorithm maps it to the first cycle.
     * @param s the encoded string
     * @param k the position of the character to return
     * @return the kth character as a string
     */
    string decodeAtIndex(string s, int k)
    {
        size_t len{0};
        string::iterator it{s.begin()};
        
        // Get the length of encoded s
        while (it != s.end())
        {
            // If char is a digit, multiply the len by the digit.
            if (*it - '0' >= 0 && *it - '0' <= 9)
            {
                len *= *it - '0';
            } else // If char is not a digit, add one to len.
            {
                ++len;
            }
            ++it;
        }
        
        // Reverse traverse
        while (--it != s.begin() && len > k) {
            
            // If char is a digit, divide the length by the digit then adjust k to fit into the new cycle size.
            if (*it - '0' > 0 && *it - '0' <= 9)
            {
                len /= *it - '0';
                k %= len;
            } else // If the char is not a digit, subtract one from the len (we are not changing cycles).
            {
                --len;
            }
        }
        
        return {*it};
    }
    
    string decodeAtIndexNaive(string s, int k)
    {
        string final;
        
        for (string::iterator it = s.begin(); it != s.end() && k > final.length(); ++it)
        {
            // If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
            if (*it - '0' >= 0 && *it - '0' <= 9)
            {
                string   current{final};
                for (int i = 1; i < *it - '0'; ++i)
                {
                    final.append(current);
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
    
    string s1, s2, s3, s4, s5, s6;
    int    k1, k2, k3, k4, k5, k6;
    
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
    s6 = "y959q969u3hb22odq595";
    k6 = 222280369;
    
    cout << sol.decodeAtIndex(s1, k1) << endl; // Output: "leetleetcodeleetleetcodeleetleetcode", "o"
    cout << sol.decodeAtIndex(s2, k2) << endl; // Output: "hahahaha", "h"
    cout << sol.decodeAtIndex(s3, k3) << endl;
    cout << sol.decodeAtIndex(s4, k4) << endl;
    cout << sol.decodeAtIndex(s5, k5) << endl;
    cout << sol.decodeAtIndex(s6, k6) << endl;
    
    return 0;
}

