class Solution 
{
public:
    bool checkAlmostEquivalent(string word1, string word2) 
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (auto a : word1)
            v1[a - 'a']++;

        for (auto a : word2)
            v2[a - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            if (abs(v1[i] - v2[i]) > 3)
                return false;
        }

        return true;
    }
};