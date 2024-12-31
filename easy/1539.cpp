class Solution
{
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        if (arr[arr.size() - 1] == arr.size())
            return arr[arr.size() - 1] + k;

        int l = 0;
        int r = arr.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] - 1 - mid < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        if (l == arr.size())
            return arr[arr.size() - 1] + k - (arr[arr.size() - 1] - arr.size());

        int i = arr[l] - 1 - l;
        int num = arr[l];

        if (i < k)
            return num + (k - i) - 1;

        while (i != k)
        {
            num--;
            i--;
        }

        return --num;
    }
};