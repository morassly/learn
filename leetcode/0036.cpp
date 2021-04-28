class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> wow(9, 0);
        int mux1;
        int mux2;
        int mux3;
        int box_index;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                mux1 = 1 << (board[i][j] - '1');
                mux2 = 1 << 9 + (board[i][j] - '1');
                mux3 = 1 << 18 + (board[i][j] - '1');
                box_index = (i / 3) * 3 + j / 3;
                if ((wow[i] & mux1) != mux1 && (wow[j] & mux2) != mux2 &&
                    (wow[box_index] & mux3) != mux3) {
                    wow[i] = wow[i] | mux1;
                    wow[j] = wow[j] | mux2;
                    wow[box_index] = wow[box_index] | mux3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};