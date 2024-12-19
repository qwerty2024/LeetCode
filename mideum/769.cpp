class Solution
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            vector<bool> v(n, false);
            int left = i;
            int right = i;
            v[arr[i]] = true;
            while (right < n)
            {
                bool test = true;
                for (int j = left; j <= right; j++)
                {
                    if (v[j] == false) test = false;
                }

                if (test) break;

                right++;
                i++;
                v[arr[right]] = true;
            }

            ans++;
        }

        return ans;
    }
};