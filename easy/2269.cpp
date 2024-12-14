class Solution 
{
public:
    int divisorSubstrings(int num, int k) 
    {
        string s = to_string(num);
        int n = s.size();
        int ans = 0;
        int i = 0;

        while (i + k <= n)
        {
            int tmp = stoi(s.substr(i, k));
            if (tmp != 0 && num % tmp == 0)
                ans++;

                i++;
        }

        return ans;
    }
};