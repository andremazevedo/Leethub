#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> hashmap;
    int size = 1013;

public:
    MyHashMap() {
        hashmap.resize(size);
    }
    
    void put(int key, int value) {
        auto& bucket = hashmap[key % size];
        for (auto& p : bucket) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        bucket.emplace_front(key,value);
    }
    
    int get(int key) {
        const auto& bucket = hashmap[key % size];
        for (const auto& p : bucket)
            if (p.first == key)
                return p.second;
        return -1;
    }
    
    void remove(int key) {
        auto &bucket = hashmap[key % size];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
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