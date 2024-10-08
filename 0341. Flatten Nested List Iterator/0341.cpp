#include "../streamUtils.hpp"
#include "unordered_map"
#include "stack"

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> s;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            s.push(nestedList[i]);
        }
    }
    
    int next() {
        int next = s.top().getInteger();
        s.pop();
        return next;
    }
    
    bool hasNext() {

        while (!s.empty()) {

            if (s.top().isInteger()) {
                return true;
            }

            vector<NestedInteger> list = s.top().getList();
            s.pop();
            for (int i = list.size() - 1; i >= 0; i--) {
                s.push(list[i]);
            }
        }

        return false;
    }
};


int main() {

    /**
     * Your NestedIterator object will be instantiated and called as such:
     * NestedIterator i(nestedList);
     * while (i.hasNext()) cout << i.next();
     */

    return 0;
}
