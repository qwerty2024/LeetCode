class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        int n = citations.size();
        int ans = 0;

        sort(citations.begin(), citations.end(), greater<int>());

        int i = 0;
        while (i < n)
        {
            if (citations[i] < i + 1)
                break;

            i++;
        }

        return i;
    }
};