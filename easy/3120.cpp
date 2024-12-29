class Solution 
{
public:
    int numberOfSpecialChars(string word) 
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (auto a : word)
        {
            if (a >= 'a' && a <= 'z') v1[a - 'a']++;
            if (a >= 'A' && a <= 'Z') v2[a - 'A']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (v1[i] > 0 && v2[i] > 0) ans++;
        }

        return ans;
    }
};