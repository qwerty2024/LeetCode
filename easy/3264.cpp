class Solution 
{
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        //while (!pq.empty())
        //{
        //    cout << pq.top().first << " " << pq.top().second << "\n";
        //    pq.pop();
        //}

        for (int i = 0; i < k; i++)
        {
            pair<int, int> tmp = pq.top();
            tmp.first *= m;
            pq.pop();
            pq.push(tmp);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }

        return nums;
    }
};