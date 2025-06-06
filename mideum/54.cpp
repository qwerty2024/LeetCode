class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = m - 1;

        while (left <= right && up <= down)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[up][i]);
            }

            for (int i = up + 1; i <= down; i++)
            {
                ans.push_back(matrix[i][right]);
            }

            if (up != down)
                for (int i = right - 1; i >= left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }

            if (left != right)
                for (int i = down - 1; i > up; i--)
                {
                    ans.push_back(matrix[i][left]);
                }

            left++;
            right--;
            up++;
            down--;
        }

        return ans;
    }
};