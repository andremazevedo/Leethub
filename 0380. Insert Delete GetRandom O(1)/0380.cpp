#include "../streamUtils.hpp"

using namespace std;

class RandomizedSet {
private:
    vector<int> set;
    unordered_map<int,int> hashmap;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hashmap.count(val) > 0)
            return false;
        
        set.push_back(val);
        hashmap[val] = set.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (hashmap.count(val) == 0)
            return false;

        set[hashmap[val]] = set.back();
        hashmap[set.back()] = hashmap[val];
        set.pop_back();
        hashmap.erase(val);
        return true;
    }
    
    int getRandom() {
        return set[rand() % set.size()];
    }
};

int main() {
    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */

    return 0;
}
