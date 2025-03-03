class Solution 
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int eq = 0;
        vector<int> v1;
        vector<int> v2;

        for (auto a : nums)
        {
            if (a < pivot)
                v1.push_back(a);
            else if (a > pivot)
                v2.push_back(a);
            else
                eq++;
        }

        vector<int> v_eq(eq, pivot);

        v1.insert(v1.end(), v_eq.begin(), v_eq.end());
        v1.insert(v1.end(), v2.begin(), v2.end());   

        return v1;
    }
};