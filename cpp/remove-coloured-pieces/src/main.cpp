#include <iostream>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int alice_moves = 0, bob_moves = 0;
        
        // Count the number of removable pieces for each player
        for (size_t i{1}; i < colors.length() - 1; ++i) // O(n)
        {
            if (colors.at(i - 1) == 'A' && colors.at(i) == 'A' && colors.at(i + 1) == 'A')
            {
                ++alice_moves;
            } else if (colors.at(i - 1) == 'B' && colors.at(i) == 'B' && colors.at(i + 1) == 'B')
            {
                ++bob_moves;
            }
        }
        
        // Set the winner to alice
        bool turn = true;
        
        // While on their turn there are pieces to remove for alice or pieces to remove for bob,
        while ((alice_moves && turn) || (bob_moves && !turn)) // O(n - m), so O(n)
        {
            // Alternate decrementing alice and bob's number of removable pieces.
            if (turn)
            {
                --alice_moves;
                
            } else
            {
                --bob_moves;
            }
            turn = !turn;
        }
        
        // The winner is the player after the player who does not play on their turn.
        return !turn;
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
    string game6{"BBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAA"}; // 25 to 26
    
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
