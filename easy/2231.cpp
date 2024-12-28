class Solution
{
public:
    int largestInteger(int num)
    {
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        vector<bool> v;

        while (num > 0)
        {
            if ((num % 10) % 2 == 0)
            {
                pq1.push(num % 10);
                num /= 10;
                v.push_back(true);
            }
            else
            {
                pq2.push(num % 10);
                num /= 10;
                v.push_back(false);
            }
        }

        string ans = "";
        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i])
            {
                ans += (char)(pq1.top() + '0');
                pq1.pop();
            }
            else
            {
                ans += (char)(pq2.top() + '0');
                pq2.pop();
            }
        }

        return stoi(ans);
    }
};