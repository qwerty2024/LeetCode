class Solution 
{
public:
    string removeDigit(string number, char digit) 
    {
        int n = number.size();
        string ans = "";
        bool removed = false;

        for (int i = 1; i < n; i++)
        {
            if (!removed && number[i - 1] == digit && digit < number[i])
            {
                removed = true;
                continue;
            }
            ans += number[i - 1];
        }
        
        if (!removed && number[n - 1] == digit)
        {
            return ans;
        }
        else
            ans += number[n - 1];

        if (removed) return ans;

        ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (!removed && number[i] == digit)
            {
                removed = true;
                continue;
            }
            ans += number[i];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};