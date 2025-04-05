class Solution
{
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
    {
        int n = arr.size();
        int m = pieces.size();

        unordered_map<int, int> um;
        for (int i = 0; i < m; i++)
        {
            um[pieces[i][0]] = i;
        }

        int j = 0;
        while (j < n)
        {
            if (um.contains(arr[j]))
            {
                auto k = pieces[um[arr[j]]];
                for (int i = 0; i < k.size(); i++)
                {
                    if (arr[j] != k[i])
                        return false;
                    j++;
                }
            }
            else
                return false;
        }

        return true;
    }
};