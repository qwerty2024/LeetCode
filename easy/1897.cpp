class Solution 
{
public:
    bool makeEqual(vector<string>& words) 
    {
        vector<int> v(26, 0);

        for (auto a : words)
            for (auto b : a)
                v[b - 'a']++;
        
        int k = words.size();

        for (auto a : v)
            if (a % k != 0) return false;

        return true;
    }
};
