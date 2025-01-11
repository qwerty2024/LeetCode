class Solution 
{
public:
    bool canConstruct(string s, int k) 
    {
        vector<int> v(26, 0);

        for (auto a : s)
            v[a - 'a']++;

        int n_1 = 0;
        int n_2 = 0;

        for (int i = 0; i < 26; i++)
        {
            n_2 += v[i] / 2;
            n_1 += (v[i] % 2 == 0) ? 0 : 1; 
        }

        if (n_1 == k)
            return true;
        
        if (n_1 < k)
        {
            if (k - n_1 <= 2 * n_2)
                return true;
        }

        return false;
    }
};