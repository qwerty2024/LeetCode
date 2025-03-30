class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.size();
        vector<pair<int,int>> t(26, {-1, -1});

        for (int i = 0; i < n; i++)
        {
            if (t[s[i] - 'a'].first == -1)
                t[s[i] - 'a'].first = i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (t[s[i] - 'a'].second == -1)
                t[s[i] - 'a'].second = i;
        }

        //for (int i = 0; i < 26; i++)
        //    cout << t[i].first << " " << t[i].second << endl;

        vector<pair<int,int>> tt;
        for (int i = 0; i < 26; i++)
            if (t[i].first != -1)
                tt.push_back(t[i]);

        sort(tt.begin(), tt.end());

        //for (int i = 0; i < tt.size(); i++)
        //    cout << tt[i].first << " " << tt[i].second << endl;

        vector<int> ans;
        pair<int,int> curr = tt[0];

        for (int i = 1; i < tt.size(); i++)
        {
            if (tt[i].first < curr.second)
            {
                curr.second = max(curr.second, tt[i].second);
            }
            else
            {
                ans.push_back(curr.second - curr.first + 1);
                curr = tt[i];
            }
        }

        ans.push_back(curr.second - curr.first + 1);

        return ans; 
    }
};