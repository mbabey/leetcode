#include <iostream>

using namespace std;

class MyHashMap
{
private:
    struct key_value
    {
        int key;
        int value;
    };
    
    vector<struct key_value> map;
    
    int binary(int start, int end, int key)
    {
        if (start >= end)
        {
            return -1; // Does not exist.
        }
        
        int size{end - start + 1};
        int pos{(size / 2) + start};
        
        if (key > map[pos].key)
        {
           return binary(start + size / 2, end, key);
        }
        if (key < map[pos].key)
        {
            return binary(start, end - size / 2, key);
        }
        return pos;
    }

public:
    MyHashMap() = default;
    
    void put(int key, int value)
    {
        int pos = binary(0, map.size() - 1, key);
        if (pos != -1)
        {
            map[pos].value = value;
        } else
        {
            struct key_value kv{};
            kv.key   = key;
            kv.value = value;
            map.push_back(kv);
            sort(map.begin(), map.end(), [](struct key_value a, struct key_value b)
            {
                return a.key < b.key;
            });
        }
        
    }
    
    int get(int key)
    {
        int pos = binary(0, map.size() - 1, key);
        if (pos != -1)
        {
            return map[pos].value;
        }
        
        return -1;
    }
    
    void remove(int key)
    {
        int pos = binary(0, map.size() - 1, key);
        if (pos != -1)
        {
            auto location = map.begin() + pos;
            map.erase(location);
        }
    }
};

int main()
{
    
    return 0;
}
