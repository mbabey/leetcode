#include <iostream>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        size_t len{colors.length()};
        
        if (len < 3)
        {
            return false; // Bob wins.
        }
        
        int alice_moves{0}, bob_moves{0}, count;
        
        // Count the number of removable pieces for each player
        for (size_t i{1}; i < len; ++i) // O(n)
        {
            count = 0;
            while (colors[i] == 'A' && colors[i] == colors[i - 1])
            {
                ++count;
                ++i;
            }
            alice_moves += max(0, count - 1);
            count = 0;
            while (colors[i] == 'B' && colors[i] == colors[i - 1])
            {
                ++count;
                ++i;
            }
            bob_moves += max(0, count - 1);
        }
        
        // Alice wins if she has more moves than Bob; otherwise, Bob wins.
        return (alice_moves > bob_moves);
    }
};

string bool_to_string(bool b);

int main()
{
    Solution sol;
    
    string game1{"AAABABB"};
    string game2{"AA"};
    string game3{"ABBBBBBBAAA"};
    string game4{"AAA"};
    string game5{"ABABABABABABA"};
    string game6{"BBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAA"}; // 25 to 26
    
    cout << "Winner: " << bool_to_string(sol.winnerOfGame(game1)) << endl;
    cout << "Winner: " << bool_to_string(sol.winnerOfGame(game2)) << endl;
    cout << "Winner: " << bool_to_string(sol.winnerOfGame(game3)) << endl;
    cout << "Winner: " << bool_to_string(sol.winnerOfGame(game4)) << endl;
    cout << "Winner: " << bool_to_string(sol.winnerOfGame(game5)) << endl;
    cout << "Winner: " << bool_to_string(sol.winnerOfGame(game6)) << endl;
    
    return EXIT_SUCCESS;
}

string bool_to_string(bool b)
{
    return (b) ? "Alice" : "Bob";
}
