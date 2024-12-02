class Solution 
{
public:
    int alternateDigitSum(int n) 
    {
        string tmp = to_string(n);
        int ans = 0;
        bool test = true;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (test)
            {
                ans += tmp[i] - '0';
                test = false;
            }
            else
            {
                ans -= tmp[i] - '0';
                test = true;
            }
        }

        return ans;
    }
};