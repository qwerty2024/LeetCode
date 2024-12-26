class Solution 
{
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        vector<int> ans;
        
        vector<int> v(10);
        for (auto a : digits)
            v[a]++;

        for (int i = 100; i < 1000; i += 2)
        {
            unordered_map<int, int> um;
            int tmp = i;
            um[tmp % 10]++;
            tmp /= 10;
            um[tmp % 10]++;
            tmp /= 10;
            um[tmp % 10]++;
            
            bool flag = true;
            
            for (auto a : um)
            {
                if (a.second > v[a.first])
                    flag = false;
            }

            if (flag)
                ans.push_back(i);
        }

        return ans;
    }
};