class Solution 
{
public:
    vector<int> constructRectangle(int area) 
    {
        vector<int> divisors;
        int n = area;
        for (int i = 1; i * i <= n; i++) 
        {
            if(n % i == 0)
            {
                if(i * i != n)
                    divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }

        //sort(divisors.begin() , divisors.end());
        int mini = INT_MAX;
        int d = 1;
        for (int i = 0; i < divisors.size(); i++)
        {
            if (abs(divisors[i] - area / divisors[i]) < mini)
            {
                mini = abs(divisors[i] - area / divisors[i]);
                d = divisors[i];
            }
        }

        vector<int> ans{d, area / d};
        sort(ans.begin(), ans.end(), greater<>());
        return ans;
    }
};