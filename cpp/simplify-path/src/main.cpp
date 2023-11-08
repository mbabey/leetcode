#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> path_tokens;
        stringstream   path_ss{path};
        string         token;
        
        while (getline(path_ss, token, '/'))
        {
            if (!token.empty())
            {
                path_tokens.push_back(token);
            }
        }
        
        vector<string> path_stack;
        for (string   &tok : path_tokens)
        {
            if (tok == ".." && !path_stack.empty())
            {
                path_stack.pop_back();
            } else if (tok != ".." && tok != ".")
            {
                path_stack.push_back(tok);
            }
        }
        
        stringstream ss;
        for (string &dir : path_stack)
        {
            ss << "/" << dir;
        }
        if (path_stack.empty())
        {
            ss << "/";
        }
        
        return {ss.str()};
    }
};

int main()
{
    Solution s;
    
    cout << s.simplifyPath("/../") << endl;
    cout << s.simplifyPath("/home/user/Documents/../Pictures") << endl;
    cout << s.simplifyPath("/home/user/../../usr/local/bin") << endl;
    cout << s.simplifyPath("/home/user/./Downloads/../Pictures/././") << endl;
    
    return 0;
}
