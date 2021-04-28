class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0;
        int b = n - 1;

        int l = 0;
        int r = n - 1;
        int i = 0;
        int j = 0;
        int num = 0;
        int tar = n * n;
        vector<vector<int>> matrix(n, vector<int>(n));
        while (num < tar) {
            for (int i = l; i <= r; i++) {
                matrix[t][i] = num + 1;
                num++;
            }
            t++;
            for (int i = t; i <= b; i++) {
                matrix[i][r] = num + 1;
                num++;
            }
            r--;
            for (int i = r; i >= l && num < tar; i--) {
                matrix[b][i] = num + 1;
                num++;
            }
            b--;
            for (int i = b; i >= t && num < tar; i--) {
                matrix[i][l] = num + 1;
                num++;
            }
            l++;
        }
        return matrix;
    }
};