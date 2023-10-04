#include <iostream>
#include <sstream>

using namespace std;

class MyHashMap
{
private:
    int map[1000000];
public:
    MyHashMap()
    {
        fill_n(map, sizeof(map) / sizeof(int), -1);
    }
    
    void put(int key, int value)
    {
        map[key] = value;
    }
    
    int get(int key)
    {
        return map[key];
    }
    
    void remove(int key)
    {
        map[key] = -1;
    }
    
    string to_string()
    {
        stringstream ss;
        
        ss << "[ ";
        for (int i = 0; i < sizeof(map) / sizeof(int); ++i)
        {
            if (map[i] != -1)
            {
                ss << "[ " << i << ", " << map[i] << " ]";
            }
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

//    cout << hm.get(222) << endl;
//    cout << hm.get(779) << endl;
    hm.put(565, 194);
    hm.put(4, 73);
    cout << hm.get(565) << endl;
    cout << hm.get(4) << endl;
}

class MySpaceEfficientHashMap
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
            return (map.size() && map[start].key == key) ? start : -1;
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
        if (map.size() > 1 && map[map.size() - 2].key > kv.key)
        {
            sort(map.begin(), map.end(), [](struct key_value a, struct key_value b)
            {
                return a.key < b.key;
            });
        }
    }

public:
    MySpaceEfficientHashMap() = default;
    
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