class Solution 
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> offset{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = 0;
                int count = 0;
                for (int k = 0; k < 9; k++)
                {
                    int i_new = i + offset[k][0];
                    int j_new = j + offset[k][1];
                    
                    if (i_new >= 0 && j_new >= 0 && i_new < m && j_new < n)
                    {
                        sum += img[i_new][j_new];
                        count++;
                    }
                }

                ans[i][j] = sum / count;
            }
        }


        return ans;
    }
};
