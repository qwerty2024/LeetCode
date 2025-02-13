class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int ans = 0;

        for (const auto& a : nums)
        {
            pq.push(a);
        }

        while (pq.size() > 1 && pq.top() < k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            long long tmp = min(x, y) * 2 + max(x, y);
            pq.push(tmp);
            ans++;
        }

        return ans;
    }
};