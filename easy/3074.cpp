class Solution 
{
public:
    int minimumBoxes(vector<int>& apple, vector<int>& c) 
    {
        int sum = 0;
        for (auto a : apple)
            sum += a;

        sort(c.begin(), c.end(), greater());

        int ans = 0;
        for (auto a : c)
        {
            sum -= a;
            ans++;
            if (sum <= 0) break;
        }

        return ans;
    }
};