#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    int max = 0;

    bool isUnique(vector<string>& subsequence, string str) {
        for (int i = 0; i < str.length() - 1; i++) {
            for (int j = i + 1; j < str.length(); j++) {
                if (str[i] == str[j]) {
                    return false;
                }
            }
        }

        for (auto c : str) {
            for (auto i : subsequence) {
                if (i.find(c) != string::npos) {
                    return false;
                }
            }
        }
        
        return true;
    }

    void backtracking(vector<string>& arr, vector<string>& subsequence, int index) {
        int len = 0;

        for (auto i : subsequence) {
            len += i.length();
        }
        
        if (len > max) {
            max = len;
        }
    
        for (int i = index; i < arr.size(); i++) {
            if (isUnique(subsequence, arr[i])) {
                subsequence.push_back(arr[i]);
    
                backtracking(arr, subsequence, i + 1);
        
                subsequence.pop_back();
            }
            else {
                backtracking(arr, subsequence, i + 1);
            }
        }
    }

public:
    int maxLength(vector<string>& arr) {
        vector<string> subsequence;

        backtracking(arr, subsequence, 0);

        return max;
    }
};

int main() {

    vector<string> arr = {"abcdefghijklm","bcdefghijklmn","cdefghijklmno","defghijklmnop","efghijklmnopq","fghijklmnopqr","ghijklmnopqrs","hijklmnopqrst","ijklmnopqrstu","jklmnopqrstuv","klmnopqrstuvw","lmnopqrstuvwx","mnopqrstuvwxy","nopqrstuvwxyz","opqrstuvwxyza","pqrstuvwxyzab"};
    
    cout << "Input: arr = " << arr << endl;
    
    cout << "Output: " << Solution().maxLength(arr) << endl;

    return 0;
}
