class Solution 
{
public:
    vector<int> mostVisited(int n, vector<int>& rounds) 
    {
        int curr = rounds[0];
        vector<int> freq(n + 1, 0);
        freq[curr]++;

        for (int i = 1; i < rounds.size(); i++)
        {
            while (curr != rounds[i])
            {
                curr++;
                if (curr == n + 1) curr = 1;
                freq[curr]++;
            }
        }

        int maxi = *max_element(freq.begin(), freq.end());

        vector<int> ans;
        for (int i = 1; i < freq.size(); i++)
        {
            if (freq[i] == maxi)
                ans.push_back(i);
        }

        return ans;
    }
};