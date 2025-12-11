class Solution
{
public:
    int countPermutations(vector<int>& complexity) 
    {
        int first = complexity[0];
        int n = complexity.size();
        for (int i = 1; i < n; i++)
        {
            if (first >= complexity[i])
                return 0;
        }

        long long ans = 1;

        for (int i = 1; i < n; i++)
            ans = (ans * i) % 1000000007;

        return ans;
    }
};