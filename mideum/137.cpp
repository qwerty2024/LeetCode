class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {   
        vector<int> bits(32, 0);
       
        for (auto a : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                if (a & 1)
                    bits[i]++;
                a >>= 1;
            }
        }   

        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (bits[i] % 3)
            {
                ans |= 1;
            }
            if (i != 0)
                ans <<= 1;
        }

        return ans;    
    }
};