class Solution 
{
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> ans;

        int current = n;

        for (int i = 0; i < n; i++)
        {
            // найти на какой позиции сейчас число current
            int pos = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == current)
                {
                    pos = j;
                    break;
                }
            }

            // перевернуть все блины до найденной позиции
            ans.push_back(pos + 1);
            int l = 0;
            int r = pos;
            while (l < r)
            {
                swap(arr[l], arr[r]);
                l++;
                r--;
            }

            // перевернуть блины до позиции установки current
            ans.push_back(current);
            l = 0;
            r = current - 1;
            while (l < r)
            {
                swap(arr[l], arr[r]);
                l++;
                r--;
            }

            current--;
        }

        return ans;
    }
};