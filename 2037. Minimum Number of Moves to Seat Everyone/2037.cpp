#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int moves = 0;

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (int i = 0; i < seats.size(); i++)
            moves += abs(seats[i] - students[i]);

        return moves;
    }
};

int main() {

    vector<int> seats = {3, 1, 5};
    vector<int> students = {2, 7, 4};

    printInput(getName(seats), seats, getName(students), students);

    printOutput(Solution().minMovesToSeat(seats, students));

    return 0;
}
