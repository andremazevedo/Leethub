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
 
class MyHashSet {
    vector<vector<int>> buckets;

public:
    MyHashSet() {
        buckets = vector<vector<int>>(1000);
    }
    
    void add(int key) {
        int i = hash(key);
        if (!contains(key))
            buckets[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash(key);
        vector<int>::iterator it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it != buckets[i].end())
            buckets[i].erase(it);
    }
    
    bool contains(int key) {
        int i = hash(key);
        vector<int>::iterator it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it != buckets[i].end())
            return true;
        else 
            return false;
    }
    
    int hash(int key) {
        return key % 1000;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {

    MyHashSet *myHashSet = new MyHashSet();
    myHashSet->add(1);      // set = [1]
    myHashSet->add(2);      // set = [1, 2]
    cout << myHashSet->contains(1) << endl; // return True
    cout << myHashSet->contains(3) << endl; // return False, (not found)
    myHashSet->add(2);      // set = [1, 2]
    cout << myHashSet->contains(2) << endl; // return True
    myHashSet->remove(2);   // set = [1]
    cout << myHashSet->contains(2) << endl; // return False, (already removed)

    return 0;
}