class Solution 
{
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int> pq;

        for (auto a : gifts)
            pq.push(a);

        for (int i = 0; i < k; i++)
        {
            int tmp = pq.top();
            pq.pop();
            tmp = sqrt(tmp);
            pq.push(tmp);
        }


        long long ans = 0;

        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};