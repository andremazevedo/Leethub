#include <iostream>
#include <vector>
#include <queue>
using namespace std;

ostream& operator<<(ostream& os, const queue<int>& q)
{
    os << "[";
    if (q.size() > 1)
        os << q.front() << " ... " << q.back();
    else if (!q.empty())
        os << q.front();
    os << "]";
    return os;
}

class MyStack {

    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q1.size();
        for (int i = 0; i < size; i++) {
            int v = q1.front();
            q1.pop();
            q2.push(v);
        }

        q1.push(x);
        for (int i = 0; i < size; i++) {
            int v = q2.front();
            q2.pop();
            q1.push(v);
        }
    }
    
    int pop() {
        int v = q1.front();
        q1.pop();
        return v;
    }
    
    int top() {
        return q1.front();        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {

    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_3 = obj->top();

    // cout << "Input: n = " << n << ", m = " << m << ", group = " << group << ", beforeItems = " << beforeItems << endl;

    // vector<int> output = Solution().sortItems(n, m, group, beforeItems);
    
    // cout << "output:" << output << endl;

    cout << param_3 << endl;

    return 0;

}
