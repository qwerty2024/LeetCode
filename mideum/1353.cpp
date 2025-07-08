class Solution 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n = events.size();
        int res = 0;
        int current = 0;
        priority_queue<int, vector<int>, greater<>> pq;

        sort(events.begin(), events.end());

        for (int day = 1; current < n || !pq.empty(); day++)
        {
            if (pq.empty())
                day = events[current][0];            

            while (current < n && events[current][0] <= day)
            {
                pq.push(events[current++][1]);
            }

            while (!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }

            if (!pq.empty())
            {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};