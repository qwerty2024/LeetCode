class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        unordered_map<int, int> um;

        for (auto a : arr)
            um[a]++;
        
        int target = (arr.size() + 3) / 4;

        for (auto a : um)
        {
            if (a.second >= target) return a.first;
        }
        return 0; 
    }
};