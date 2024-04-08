#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentsQueue;
        stack<int> sandwicheStack;
        int studentQueueCount = 0;

        for (auto student : students)
            studentsQueue.push(student);

        for (int i = sandwiches.size() - 1; i >= 0; i--)
            sandwicheStack.push(sandwiches[i]);
        
        while (!sandwicheStack.empty()) {
            if (studentsQueue.front() == sandwicheStack.top()) {
                studentsQueue.pop();
                sandwicheStack.pop();
                studentQueueCount = 0;
            }
            else {
                studentsQueue.push(studentsQueue.front());
                studentsQueue.pop();
                studentQueueCount++;
            }

            if (studentQueueCount == studentsQueue.size())
                break;
        }
        
        return studentsQueue.size();
    }
};

int main() {

    vector<int> students = {1,1,1,0,0,1}; 
    vector<int> sandwiches = {1,0,0,0,1,1};

    printInput(getName(students), students, getName(sandwiches), sandwiches);
    
    printOutput(Solution().countStudents(students, sandwiches));

    return 0;
}
