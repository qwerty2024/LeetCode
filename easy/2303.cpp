class Solution 
{
public:
    double calculateTax(vector<vector<int>>& b, int income) 
    {
        double ans = (income > b[0][0]) ? (double)b[0][0] * b[0][1] / 100 : (double)income * b[0][1] / 100;
        income -= b[0][0];
        if (income < 1) return ans;
//cout << ans << " ";
        for (int i = 1; i < b.size(); i++)
        {
            if (income > (b[i][0] - b[i - 1][0]))
            {
                ans += (b[i][0] - b[i - 1][0]) * (double)b[i][1] / 100;
                income -= (b[i][0] - b[i - 1][0]);
                //cout << ans << " ";
            }
            else
            {
                ans += (double)income * b[i][1] / 100;
                //cout << ans << " ";
                return ans;
            }
        }
        
        return ans;
    }
};
