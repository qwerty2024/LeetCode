class Solution 
{
public:
    vector<int> circularGameLosers(int n, int k) 
    {
        vector<bool> v(n + 1, false);
        int i = 1;
        v[i] = true;
        int curr = 1;
        while (true)
        {
            int offs = (i * k) % n;
            if (offs + curr > n)
                curr = (offs + curr) % n;
            else
                curr += offs; 

            if (v[curr] == true)
                break;
            else
                v[curr] = true;

            i++;
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (v[i] == false) ans.push_back(i);

        return ans;
    }
};