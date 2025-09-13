class Solution 
{
public:
    int maxFreqSum(string s) 
    {
        vector<int> alph(26, 0);

        for (auto& a : s)
        {
            alph[a - 'a']++;
        } 

        int max1 = 0;
        int max2 = 0;

        for (int i = 0; i < 26; i++)
        {
            if (i + 'a' == 'a' || i + 'a' == 'e' || i + 'a' == 'i' || i + 'a' == 'o' || i + 'a' == 'u')
            {
                max1 = max(max1, alph[i]);
            }
            else
            {
                max2 = max(max2, alph[i]);
            }
        }

        return max1 + max2;
    }
};