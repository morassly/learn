class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int t = 0;
        int b = matrix.size() - 1;

        int l = 0;
        int r = matrix[0].size() - 1;
        int i = 0;
        int j = 0;
        int num = 0;
        int tar = matrix.size() * matrix[0].size();

        while (num < tar)
        {
            for (int i = l; i <= r; i++)
            {
                res.push_back(matrix[t][i]);
                num++;
            }
            t++;
            for (int i = t; i <= b; i++)
            {
                res.push_back(matrix[i][r]);
                num++;
            }
            r--;
            for (int i = r; i >= l && num < tar; i--)
            {
                res.push_back(matrix[b][i]);
                num++;
            }
            b--;
            for (int i = b; i >= t && num < tar; i--)
            {
                res.push_back(matrix[i][l]);
                num++;
            }
            l++;
        }
        return res;
    }
  
};