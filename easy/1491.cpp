class Solution 
{
public:
    double average(vector<int>& s) 
    {
        int count = 0;
        int sum = 0;
        int mini = *min_element(s.begin(), s.end());
        int maxi = *max_element(s.begin(), s.end());

        for (auto a : s)
        {
            if (a != mini && a != maxi)
            {
                count++;
                sum += a;
            }
        }

        return (count == 0) ? 0 : (double)sum / count;
    }
};