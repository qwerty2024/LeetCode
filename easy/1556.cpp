class Solution 
{
public:
    string thousandSeparator(int n) 
    {
        if (n == 0) return "0";
        string ans = "";
        int count = 0;
        while (n > 0)
        {
            if (count == 3)
            {
                ans += '.';
                count = 0;
            }
            ans += to_string(n % 10);
            count++; 
            n /= 10;
        }    

        reverse(ans.begin(), ans.end());

        return ans;   
    }
};