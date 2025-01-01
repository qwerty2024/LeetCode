class Solution 
{
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        string ans = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

        vector<int> let(26, 0);

        for (auto a : licensePlate)
        {
            if (a >= 'a' && a <= 'z')
                let[a - 'a']++;

            if (a >= 'A' && a <= 'Z')
                let[a - 'A']++;
        }

        for (const auto& a : words)
        {
            vector<int> tmp(26, 0);
            for (const auto& b : a)
            {
                tmp[b - 'a']++;
            }

            bool test = true;
            for (int i = 0; i < 26; i++)
            {
                if (tmp[i] < let[i])
                    test = false;
            }

            if (test && a.size() < ans.size())
                ans = a;
        }

        return ans;
    }
};