class Solution 
{
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue<int> pq;
        if (amount[0] > 0) pq.push(amount[0]);
        if (amount[1] > 0) pq.push(amount[1]);
        if (amount[2] > 0) pq.push(amount[2]);
        int ans = 0;

        while (!pq.empty())
        {
            int a = pq.top();
            pq.pop();
            int b = -1;
            if (!pq.empty())
            {
                b = pq.top();
                pq.pop();
            }

            a--;
            b--;

            if (a > 0) pq.push(a);
            if (b > 0) pq.push(b);
            ans++;
        }

        return ans;
    }
};