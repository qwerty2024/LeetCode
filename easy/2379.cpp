class Solution 
{
public:
    int minimumRecolors(string b, int k) 
    {   
        int n = b.size();
        int ans = INT_MAX;

        int i = 0;
        int j = 0;
        int curr = 0;
        while (j < k)
        {
            if (b[j] == 'W') curr++;
            j++;
        }

        ans = min(ans, curr);

        while (j < n)
        {
            if (b[j] == 'W') curr++;
            if (b[i] == 'W') curr--;
            
            ans = min(ans, curr);

            i++;
            j++;
        }

        return ans;
    }
};