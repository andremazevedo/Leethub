#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int>>& matrix)
{
    os << "[";
    for (const auto& row : matrix) {
        os << "[";
        for (const int& element : row) {
            os << element << ",";
        }
        os << "],";
    }
    os << "]";
    return os;
}

ostream& operator<<(ostream& os, const vector<int>& vec)
{
    os << "[";
    for (const auto& element : vec) {
        os << element << ",";
    }
    os << "]";
    return os;
}

bool comp(const vector<int>& vec1, const vector<int>& vec2)
{
  return vec1.back() < vec2.back();
}


// // Greedy
// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         int length = 0;
//         int left = -1001;

//         while (1) {
//             int right = 1001;

//             for (vector<int> pair : pairs) {
//                 if (pair[0] > left && pair[1] < right) {
//                     right = pair[1];
//                 }
//             }

//             if (right != 1001) {
//                 left = right;
//                 length++;
//             } else {
//                 break;
//             }
//         }

//         return length;
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);

        int length = 1;
        int lastChainedPairIndex = 0;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > pairs[lastChainedPairIndex][1]) {
                length++;
                lastChainedPairIndex = i;
            }
        }
        
        return length;
    }
};


int main() {

    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};

    // vector<vector<int>> pairs = {{1,2},{7,8},{4,5}};

    // vector<vector<int>> pairs = {{1,1},{1,2},{2,1}, {1,54}};
    
    cout << "Input: pairs = " << pairs << endl;
    
    cout << "output: \"" << Solution().findLongestChain(pairs) << "\""<< endl;

    return 0;

}
