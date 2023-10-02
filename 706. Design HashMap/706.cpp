#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}
 
class MyHashMap {
    vector<vector<pair<int,int>>> buckets;

public:
    MyHashMap() {
        buckets = vector<vector<pair<int,int>>>(1000);
    }
    
    void put(int key, int value) {
        int i = hash(key);
        vector<pair<int,int>>::iterator it = contains(key);
        if (it != buckets[i].end())
            it->second = value;
        else
            buckets[i].push_back(pair<int,int>(key, value)); 
    }
    
    int get(int key) {
        int i = hash(key);
        vector<pair<int,int>>::iterator it = contains(key);
        if (it != buckets[i].end())
            return it->second;
        else
            return -1; 
    }
    
    void remove(int key) {
        int i = hash(key);
        vector<pair<int,int>>::iterator it = contains(key);
        if (it != buckets[i].end())
            buckets[i].erase(it);
    }

    vector<pair<int,int>>::iterator contains(int key) {
        int i = hash(key);
        vector<pair<int,int>>::iterator it;
        for(it = buckets[i].begin(); it != buckets[i].end(); ++it)
            if (it->first == key)
                break;
        return it;
    }

    int hash(int key) {
        return key % 1000;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {

    MyHashMap *myHashMap = new MyHashMap();
    myHashMap->put(1, 1); // The map is now [[1,1]]
    myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
    cout << myHashMap->get(1) << endl;   // return 1, The map is now [[1,1], [2,2]]
    cout << myHashMap->get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    cout << myHashMap->get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
    myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
    cout << myHashMap->get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]

    return 0;
}