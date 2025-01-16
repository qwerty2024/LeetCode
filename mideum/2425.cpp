class Solution 
{
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> tmp1;
        unordered_map<int, int> tmp2;
        int ans = 0;

        for (auto& a : nums1)
            tmp1[a]++;
        
        for (auto& a : nums2)
            tmp2[a]++;

        if (m % 2 == 1)
        {
            for (auto& a : tmp1)
            {
                if (a.second % 2 == 1)
                    ans ^= a.first;
            }
        }

        if (n % 2 == 1)
        {
            for (auto& a : tmp2)
            {
                if (a.second % 2 == 1)
                    ans ^= a.first;
            }
        }

        return ans;
    }
};