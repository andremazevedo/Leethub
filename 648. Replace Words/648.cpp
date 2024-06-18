#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(), 
            [](const string& a, const string& b) {
                return a.length() < b.length();
            }
        );

        int pos = 0, len = 0;
        while (pos < sentence.length()) {
            if (sentence[pos] == ' ') {
                string word = sentence.substr(pos - len, len);
                for (const string& root : dictionary) {
                    if (root == word.substr(0, root.length())) {
                        sentence.replace(pos - len, len, root);
                        pos -= len - root.length();
                        len = 0;
                        break;
                    }
                }
                pos++;
                len = 0;
            }
            else {
                pos++;
                len++;
            }
        }

        string word = sentence.substr(pos - len, len);
        for (const string& root : dictionary) {
            if (root == word.substr(0, root.length())) {
                sentence.replace(pos - len, len, root);
                break;
            }
        }

        return sentence;
    }
};

int main() {

    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    printInput(getName(dictionary), dictionary, getName(sentence), sentence);
    
    printOutput(Solution().replaceWords(dictionary, sentence));

    return 0;
}
