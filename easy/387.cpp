class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        unordered_map<int, int> um;
        for (auto a : s)
        {
            um[a]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (um[s[i]] == 1)
                return i;
        }

        return -1;
    }
};