class Solution
{
public:
    long long findScore(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> uses(n, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(make_pair( nums[i], i ));
        }

        long long ans = 0;
        while (!pq.empty())
        {
            if (uses[pq.top().second])
            {
                ans += pq.top().first;
                uses[pq.top().second] = false;

                if (pq.top().second > 0) 
                    uses[pq.top().second - 1] = false;

                if (pq.top().second < n - 1)
                    uses[pq.top().second + 1] = false;

                pq.pop();
            }
            else
            {
                pq.pop();
            }
        }

        return ans;
    }
};