class Solution 
{
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) 
    {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        
        unordered_set<int> us1(aliceSizes.begin(), aliceSizes.end());
        unordered_set<int> us2(bobSizes.begin(), bobSizes.end());
        
        int diff = abs(sum1 - sum2);

        int i = 0;
        int j = 0;
        if (sum1 > sum2)
        {
            for (auto a : bobSizes)
            {
                if (us1.contains(a + (sum1 - sum2) / 2))
                    return {a + (sum1 - sum2) / 2, a};
            }
        }
        else
        {
            for (auto a : aliceSizes)
            {
                if (us2.contains(a + (sum2 - sum1) / 2))
                    return {a, a + (sum2 - sum1) / 2};
            }
        }

        return {0,0};
    }
};