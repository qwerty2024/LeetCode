class Solution 
{
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.size();
        int i = 0;
        int j = 0;
        unordered_map<char, int> um;
        int ans = 0;


        while(j < n)
        {
            while (j < n && um.size() != 3)
            {
                um[s[j]]++;
                j++;
            }

            if (um.size() == 3)
                ans += 1 + (n - j);

            while (i < j && um.size() == 3)
            {         
                um[s[i]]--;
                if (um[s[i]] == 0)
                    um.erase(s[i]);

                if (um.size() == 3)
                    ans += 1 + (n - j);
                    
                i++;
            }
        }

        return ans;
    }
};