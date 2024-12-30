class Solution 
{
public:
    int maxNumberOfBalloons(string text) 
    {
        vector<int> v(26, 0);
        for (auto a : text)
            v[a - 'a']++;

        int ans = INT_MAX;

        ans = min(v['b' - 'a'], ans);
        ans = min(v['a' - 'a'], ans);
        ans = min(v['l' - 'a'] / 2, ans);
        ans = min(v['o' - 'a'] / 2, ans);
        ans = min(v['n' - 'a'], ans);

        return ans;
    }
};