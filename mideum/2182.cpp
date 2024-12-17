class Solution 
{
public:
    string repeatLimitedString(string s, int L) 
    {
        vector<int> v(26);
        for (auto a : s)
            v[a - 'a']++;
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] != 0) pq.push({i, v[i]});
        }

        string ans = "";
        while (!pq.empty())
        {
            auto a = pq.top();
            pq.pop();

            while (true)
            {
                int counter = 0;
                while (a.second > 0 && counter < L)
                {
                    ans += (char)(a.first + 'a');
                    a.second--;
                    counter++;
                }

                if (a.second != 0)
                {
                    if (!pq.empty())
                    {
                        auto b = pq.top();
                        pq.pop();
                        ans += (char)(b.first + 'a');
                        b.second--;

                        if (b.second != 0) pq.push(b);
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }

        return ans;
    }
};