class Solution 
{
public:
    int maxDifference(string s) 
    {
        int n = s.size();
        vector<int> f(26, 0);

        for (auto& a : s)
        {
            f[a - 'a']++;
        }

        int min_od = 1123124;
        int max_not_od = -1123124;

        for (int i = 0; i < 26; i++)
        {
            if (f[i] != 0 && f[i] % 2 == 0)
            {
                min_od = min(min_od, f[i]);
            }
            else if (f[i] != 0 && f[i] % 2 == 1)
            {
                max_not_od = max(max_not_od, f[i]);
            }
        }

        return max_not_od - min_od;
    }
};