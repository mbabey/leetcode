#include <iostream>
#include <sstream>

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

    void add(int key, int value)
    {
        struct key_value kv{};
        kv.key   = key;
        kv.value = value;
        map.push_back(kv);
        if (map.size() > 2 && map[map.size() - 2].key > kv.key)
        {
            sort(map.begin(), map.end(), [](struct key_value a, struct key_value b)
            {
                return a.key < b.key;
            });
        }
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
            add(key, value);
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
    
    string to_string()
    {
        stringstream ss;
        
        ss << "[ ";
        for (struct key_value kv : map)
        {
            ss << "[ " << kv.key << ", " << kv.value << " ]";
        }
        ss << " ]";
        
        return ss.str();
    }
};

void run_test1();

void run_test2();

void run_test3();

int main()
{
    run_test1();
    run_test2();
    run_test3();
    
    return 0;
}

void run_test1()
{
    cout << "--Test 1--" << endl;
    
    MyHashMap hm{};
    
    hm.put(1, 1);
    cout << hm.to_string() << endl;
    
    hm.put(2, 2);
    cout << hm.to_string() << endl;
    
    cout << hm.get(1) << endl;
    cout << hm.get(3) << endl;
    
    hm.put(2, 1);
    cout << hm.to_string() << endl;
    
    cout << hm.get(2) << endl;
    
    hm.remove(2);
    cout << hm.to_string() << endl;
    
    cout << hm.get(2) << endl;
}

void run_test2()
{
    cout << "--Test 2--" << endl;
    MyHashMap hm{};
    
    hm.put(69, 420);
    cout << hm.to_string() << endl;
    
    cout << hm.get(420) << endl;
    cout << hm.get(69) << endl;
    
    hm.put(420, 69);
    cout << hm.to_string() << endl;
    
    cout << hm.get(420) << endl;
    cout << hm.get(69) << endl;
    
    hm.remove(69);
    cout << hm.to_string() << endl;
    
    hm.put(420, 420);
    cout << hm.to_string() << endl;
    
    cout << hm.get(420) << endl;
    cout << hm.get(69) << endl;
}

void run_test3()
{
    cout << "--Test 3--" << endl;
    MyHashMap hm{};
    
    for (int i = 0; i < 1000000; ++i)
    {
        hm.put(i, i);
    }
    
    cout << hm.to_string() << endl;
    
    for (int i = 0; i < 1000000; ++i)
    {
        hm.get(i);
    }
    
    for (int i = 0; i < 1000000; ++i)
    {
        hm.remove(i);
    }
}
