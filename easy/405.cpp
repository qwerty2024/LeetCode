class Solution 
{
public:
    string toHex(int num) 
    {
        if (num == 0) return "0";

        string ans = "";

        long long n = num;
        if (num < 0)
            n += 4294967296;

        while (n > 0)
        {
            int ost = n % 16;

            if (ost < 10)
                ans += to_string(ost);
            else
                ans += 'a' + (ost - 10);

            n /= 16;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};