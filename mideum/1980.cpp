class Solution
{
    int string_to_int(const string& s)
    {
        int n = s.size();
        int ans = 0;

        int count = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                ans += count;
            }

            count *= 2;
        }

        return ans;
    }

    string int_to_string(int n, int len)
    {
        string ans(len, '0');

        if (n == 0)
            return ans;

        int ind = len - 1;

        while (n > 0)
        {
            ans[ind] = '0' + (n % 2);
            n /= 2;
            ind--;
        }

        return ans;
    }

public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();

        unordered_set<int> ss;

        for (int i = 0; i < n; i++)
        {
            ss.insert(string_to_int(nums[i]));
        }

        string tmp(n, '1');
        int start = string_to_int(tmp);

        while (1)
        {     
            if (!ss.contains(start))
            {
                return int_to_string(start, n);
            }
            start--;
        }

        return "";
    }
};