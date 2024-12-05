class Solution 
{
public:
    int binaryGap(int n) 
    {
        vector<int> v;

        int count = 0;
        while (n > 0)
        {
            if (n % 2 == 1) v.push_back(count);
            n >>= 1;
            count++;
        }

        if (v.size() < 2) return 0;

        int maxi = 0;
        for (int i = 1; i < v.size(); i++)
        {
            maxi = max(v[i] - v[i - 1], maxi);
        }

        return maxi;
    }
};