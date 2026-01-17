class Solution 
{
    unordered_set<int> ser(int n, vector<int>& vec)
    {
        unordered_set<int> us;

        vec.push_back(1);
        vec.push_back(n);
        sort(vec.begin(), vec.end());

        for (int i = 1; i < vec.size(); i++)
        {
            int sum = 0;
            for (int j = i; j >= 1; j--)
            {
                sum += vec[j] - vec[j - 1];
                us.insert(sum);
            }
        }

        return us;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) 
    {
        unordered_set<int> us1 = ser(m, hFences);
        unordered_set<int> us2 = ser(n, vFences);

        unordered_set<int> us3;
        if (us1.size() > us2.size())
            swap(us1, us2);
        for (const auto& a : us1)
        {
            if (us2.contains(a))
                us3.insert(a);
        }

        if (us3.size() == 0)
            return -1;
        
        return ((long long)*max_element(us3.begin(), us3.end()) * *max_element(us3.begin(), us3.end())) % 1000000007;
    }
};