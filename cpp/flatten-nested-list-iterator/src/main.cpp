#include <iostream>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
private:
    variant<int, vector<NestedInteger>> x;

public:
    NestedInteger(vector<NestedInteger> &val) : x(val) {}
    
    NestedInteger(int val) : x(val) {}
    
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return (holds_alternative<int>(x));
    }
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return get<int>(x);
    }
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    {
        return get<vector<NestedInteger>>(x);
    }
};


class NestedIterator {
private:
    vector<int> list;
    int list_i{0};

    static void get_ints(vector<NestedInteger> nestedList, vector<int> &newList)
    {
        for (int i{0}; i < nestedList.size(); ++i)
        {
            if (nestedList[i].isInteger())
            {
                newList.push_back(nestedList[i].getInteger());
            } else
            {
                get_ints(nestedList[i].getList(), newList);
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        get_ints(nestedList, list);
    }
    
    int next() {
        return list[list_i++];
    }
    
    bool hasNext() {
        return list_i < list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

vector<NestedInteger> create_list1();
vector<NestedInteger> create_list2();
vector<NestedInteger> create_list3();

int main()
{
    
    vector<NestedInteger> list1 = create_list1();
//    vector<NestedInteger> list2 = create_list2();
//    vector<NestedInteger> list3 = create_list3();
    
    NestedIterator i(list1);
    while (i.hasNext()) cout << i.next();
    
    return 0;
}

vector<NestedInteger> create_list1()
{
    NestedInteger n1{1};
    NestedInteger n2{2};
    vector<NestedInteger> oneone{n1, n1};
    NestedInteger n11{oneone};
    vector<NestedInteger> list1{n11, n2, n11};
    return list1;
}
