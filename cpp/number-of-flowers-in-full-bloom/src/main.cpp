#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> starts, stops, solution;
        
        // Create a start and stops array from the flowers start and stop times
        for (vector<int> &flower : flowers)
        {
            starts.push_back(flower[0]);
            stops.push_back(flower[1]);
        }
        
        // Sort the arrays
        sort(starts.begin(), starts.end());
        sort(stops.begin(), stops.end());
        
        // For each person, determine the number of flowers that are in bloom
        // binary_sim_insert search the arrays and get the number of values to the left of the closest position
        int      start_pos, stop_pos;
        for (int &day : people)
        {
            start_pos = upper_bound(starts.begin(), starts.end(), day) - starts.begin();
            stop_pos  = lower_bound(stops.begin(), stops.end(), day) - stops.begin();
            
            solution.push_back(start_pos - stop_pos);
        }
        
        return solution;
    }
};

string arr_to_string(vector<int> arr);

int main()
{
    Solution s;
    
    vector<vector<int>> flowers1{{1, 6},
                                 {3, 7},
                                 {9, 12},
                                 {4, 13}};
    vector<int>         people1{2, 3, 7, 11};
    
    vector<vector<int>> flowers2{{1, 10},
                                 {3, 3}};
    vector<int>         people2{3, 3, 2};
    
    vector<vector<int>> flowers3{{1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1},
                                 {1, 1}};
    vector<int>         people3{1};
    
    
    cout << arr_to_string(s.fullBloomFlowers(flowers1, people1)) << endl;
    cout << arr_to_string(s.fullBloomFlowers(flowers2, people2)) << endl;
    cout << arr_to_string(s.fullBloomFlowers(flowers3, people3)) << endl;
    
    return 0;
}

string arr_to_string(vector<int> arr)
{
    stringstream ss;
    ss << "[";
    for (int &i : arr)
    {
        ss << " " << i << " ";
    }
    ss << "]";
    return {ss.str()};
}

/* The functions below were a part of the solution, but the resulting runtime was too long. Calls to
 * binary_sim_insert() were replaced by calls to upper_bound() and lower_bound()
 */

/**
 * This function will simulate inserting val into the array. It returns the hypothetical position of val.
 * If entries of val exist in the array, it is specified whether val is inserted before or after
 * its existing entries.
 */
//int binary_sim_insert(vector<int> &arr, int start, int end, int val, bool after)
//{
//    if (arr.empty()) return -1;
//
//    if (start >= end) // Not found.
//    {
//        if (val > arr[start]) // Insert val after arr[start]
//        {
//            return start + 1;
//        }
//        if (val < arr[start]) // Insert val before arr[start] or at beginning.
//        {
//            return (start == 0) ? start : start - 1;
//        }
//
//        // Insert val according to bool after.
//        start = adjust_position(arr, start, after);
//        return start;
//    }
//
//    int size{end - start + 1};
//    int pos{(size / 2) + start};
//
//    if (val > arr[pos])
//    {
//        return binary_sim_insert(arr, start + size / 2, end, val, after);
//    }
//    if (val < arr[pos])
//    {
//        return binary_sim_insert(arr, start, end - size / 2, val, after);
//    }
//
//    // If there are other occurrences of val, shift pos either before or after all of them.
//    pos = adjust_position(arr, pos, after);
//    return pos;
//}

/**
 * Adjust the position to beginning or end of a list of like numbers.
 */
//int adjust_position(vector<int> &arr, int pos, bool after)
//{
//    if (after)
//    {
//        while (pos < arr.size() - 1 && arr[pos] == arr[pos + 1])
//        {
//            pos++;
//        }
//        pos += 1;
//    } else
//    {
//        while (pos > 0 && arr[pos] == arr[pos - 1])
//        {
//            pos--;
//        }
//    }
//    return pos;
//}
