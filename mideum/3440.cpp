class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime)
    {
        int n = startTime.size();
        int ans = 0;

        vector<pair<int, bool>> tmp;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            int len = startTime[i] - end;

            tmp.push_back({ len, true });

            tmp.push_back({ endTime[i] - startTime[i], false });

            end = endTime[i];
        }
        int len = eventTime - end;
        tmp.push_back({ len, true });

        multiset<int, greater<>> s;

        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i].second == true)
            {
                s.insert(tmp[i].first);
            }
        }

        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i].second == false)
            {
                int mid = tmp[i].first;

                int left = tmp[i - 1].first;
                bool l = false;

                int right = tmp[i + 1].first;
                bool r = false;

                ans = max(ans, left + right);

                for (auto a : s)
                {
                    if (a != left && a != right && a >= mid)
                    {
                        ans = max(ans, left + right + mid);
                        break;
                    }

                    if (a == left && !l)
                    {
                        l = true;
                        continue;
                    }

                    if (a == right && !r)
                    {
                        r = true;
                        continue;
                    }

                    if (a >= mid)
                    {
                        ans = max(ans, left + right + mid);
                        break;
                    }
                    else
                        break;
                }
            }
        }

        return ans;
    }


}; 