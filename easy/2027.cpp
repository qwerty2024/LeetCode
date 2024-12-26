class Solution 
{
public:
    int minimumMoves(string s) 
    {
        int n = s.size();
        int ans = 0;

        int i = 0;
        while (i < n)
        {   
            while (i < n && s[i] == 'O')
            {
                i++;
            }

            if (i < n)
            {    
                ans++;
                i += 3;
            }
        }

        return ans;
    }
};