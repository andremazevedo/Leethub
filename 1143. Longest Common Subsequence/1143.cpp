#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length()));

        if (text1[0] == text2[0])
            dp[0][0] = 1;
        else
            dp[0][0] = 0;

        for (int row = 1; row < text1.length(); row++)
            if (text1[row] == text2[0] && dp[row - 1][0] < 1)
                dp[row][0] = dp[row - 1][0] + 1;
            else
                dp[row][0] = dp[row - 1][0];

        for (int col = 1; col < text2.length(); col++)
            if (text1[0] == text2[col] && dp[0][col - 1] < 1)
                dp[0][col] = dp[0][col - 1] + 1;
            else
                dp[0][col] = dp[0][col - 1];



        for (int i = 1; i < text1.length() && i < text2.length(); i++) {
            for (int row = i; row < text1.length(); row++) {
                int previousLongest;

                if (dp[row][i - 1] < dp[row - 1][i])
                    previousLongest = dp[row - 1][i];
                else
                    previousLongest = dp[row][i - 1];

                if (text1[row] == text2[i] && previousLongest < i + 1)
                    dp[row][i] = previousLongest + 1;
                else
                    dp[row][i] = previousLongest;
            }

            for (int col = i + 1; col < text2.length(); col++) {
                int previousLongest;

                if (dp[i - 1][col] < dp[i][col - 1])
                    previousLongest = dp[i][col - 1];
                else
                    previousLongest = dp[i - 1][col];

                if (text1[i] == text2[col] && previousLongest < i + 1)
                    dp[i][col] = previousLongest + 1;
                else
                    dp[i][col] = previousLongest;
            }
        }

        return dp[text1.length() - 1][text2.length() - 1];
    }
};

int main() {

    string text1 = "psnw";
    string text2 = "vozsh";
    
    cout << "Input: text1 = \"" << text1 << "\", text2 = \"" << text2 << "\"" << endl;
    
    cout << "Output: " << Solution().longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
