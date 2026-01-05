class Solution 
{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        bool zeros = false;
        int otr = 0;
        int mini = abs(matrix[0][0]);
        
        for (const auto& str : matrix)
            for (const auto& a : str)
            {
                mini = min(mini, abs(a));
                if (a == 0)
                    bool zeros = true;
                if (a < 0)
                    otr++;
            }

        long long ans = 0;
        if (zeros || otr % 2 == 0)
        {
            for (const auto& str : matrix)
                for (const auto& a : str)
                    ans += abs(a);

            return ans;
        }

        for (const auto& str : matrix)
            for (const auto& a : str)
                ans += abs(a);

        ans -= 2 * mini;

        return ans;
    }
};