class Solution 
{
public:
    int kItemsWithMaximumSum(int nO, int nZ, int nN, int k) 
    {
        if (k <= nO)
        {
            return k;
        }
        else if (k <= nO + nZ)
        {
            return nO;
        }
        else
        {
            return nO - (k - nO - nZ);
        }

        return 0;
    }
};