class Solution 
{
public:
    double largestTriangleArea(vector<vector<int>>& p) 
    {
        int n = p.size();
        double ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    double S = abs(0.5 * ((p[j][0] - p[i][0]) * (p[k][1] - p[i][1]) - (p[k][0] - p[i][0]) * (p[j][1] - p[i][1])));

                    if (ans < S)
                    {
                        ans = S;
                    }
                }
            }
        }

        return ans;
    }
};