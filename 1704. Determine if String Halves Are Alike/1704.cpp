#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.length() / 2);
        string b = s.substr(s.length() / 2, s.length() / 2);

        return countVowels(a) == countVowels(b);
    }

private:
    int countVowels(string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = toupper(s[i]);
            if (c == 'A'|| c == 'E' || c == 'I' || c == 'O' || c == 'U')
                count++;       
        }
        
        return count;
    }
};

int main() {

    string s = "book";
    
    cout << "Input: s = \"" << s << "\"" << endl;
    
    cout << "Output: " << boolalpha << Solution().halvesAreAlike(s) << endl;

    return 0;
}
