class Solution 
{
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
       
        for (int i = 1; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int indx = dp[m][n];
        int  len = indx;

        string tmp(len, ' ');
        int i = m, j = n;
        while (i > 0 && j > 0) 
        {
            if (str1[i - 1] == str2[j - 1]) 
            {
                tmp[indx - 1] = str1[i - 1]; 
                i--;
                j--;
                indx--; 
            }

            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
 
        string ans = "";

        i = 0; j = 0;
        for (int k = 0; k < len; k++)
        {
            while (i < m && str1[i] != tmp[k])
            {
                ans.push_back(str1[i]);
                i++;
            }

            while (j < n && str2[j] != tmp[k])
            {
                ans.push_back(str2[j]);
                j++;
            }

            ans.push_back(tmp[k]);
            i++; j++;
        }

        while (i < m)
        {
            ans.push_back(str1[i]);
            i++;
        }

        while (j < n)
        {
            ans.push_back(str2[j]);
            j++;
        }

        return ans;
    }
};