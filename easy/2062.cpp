class Solution 
{
public:
    int countVowelSubstrings(string word) 
    {
        int ans = 0;
        for (int i = 0; i < word.size(); i++)
        {
            vector<int> dict(26, 0);
            int j = i;
            while (j < word.size() && (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u'))
            {
                dict[word[j] - 'a']++;

                if (dict['a' - 'a'] > 0 && dict['e' - 'a'] > 0 && dict['i' - 'a'] > 0 && dict['o' - 'a'] > 0 && dict['u' - 'a'] > 0)
                    ans++;

                j++;
            }
        }

        return ans;
    }
};