#include <iostream>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        const bool alice = true;
        const bool bob = false;
        bool winner;
        
        int alice_moves = 0, bob_moves = 0;
        
        // Count the number of removable pieces for each player
        for (int i{0}; i < colors.length(); ++i) {
            if (colors.at(i) == 'A')
            {
                ++alice_moves;
            } else {
                ++bob_moves;
            }
        }
        // Set the winner to alice
        turn = alice;
        // While there are pieces to remove for bob and pieces to remove for alice,
        while (alice_moves && bob_moves)
        {
            // starting with alice, alternate decrementing alice and bob's number of removable pieces.
            if (turn == alice)
            {
                --alice_moves;
            } else {
                --bob_moves;
            }
        }
        return winner;
    }
};

int main()
{
    Solution sol;
    
    return EXIT_SUCCESS;
}
