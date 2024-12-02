class Solution 
{
public:
    string largestGoodInteger(string num) 
    {
        char maxi = 0;

        int n = num.size();
        int i = 0;
        while (i < n - 2)
        {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                maxi = max(maxi, num[i]);
            }

            i++;
        }

        if (maxi == 0) return "";

        string ans = "";
        ans += maxi;
        ans += maxi;
        ans += maxi;
        return ans;
    }
};