#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (solvePath(board, word, row, col))
                    return true;
            }   
        }

        return false;
    }

private:
    bool solvePath(vector<vector<char>>& board, string word, int row, int col) {
        char letter = board[row][col];

        if (letter != word[0])
            return false;

        if (word.size() == 1)
            return true;

        board[row][col] = '_';

        if (col > 0 && solvePath(board, word.substr(1, word.length() - 1), row, col - 1))
            return true;

        if (col < board[row].size() - 1 && solvePath(board, word.substr(1, word.length() - 1), row, col + 1))
            return true;
        
        if (row > 0 && solvePath(board, word.substr(1, word.length() - 1), row - 1, col))
            return true;

        if (row < board.size() - 1 && solvePath(board, word.substr(1, word.length() - 1), row + 1, col))
            return true;

        board[row][col] = letter;
        
        return false;
    }
};

int main() {

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    
    printInput(getName(board), board, getName(word), word);
    
    printOutput(Solution().exist(board, word));

    return 0;
}
