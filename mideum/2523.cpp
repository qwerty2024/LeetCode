class Solution 
{
    vector<bool> data;
    vector<int> prime;
public:
    void save_primes(int left, int n)
    {
        //if (datas != 0) return;
        data.resize(n + 1, true);

        for (int i = 2; i * i <= n; i++) 
        {
            if (data[i]) 
            {
                for (int j = i * i; j <= n; j += i) 
                {
                    data[j] = false;
                }
            }
        }

        if (left == 1)
            left++;
            
        for (int i = left; i <= n; i++)
        {
            if (data[i])
                prime.push_back(i);
        }
    }

    vector<int> closestPrimes(int left, int right) 
    {
        save_primes(left, right);

        vector<int> ans{-1, -1};
        int mini = INT_MAX;
        
        if (prime.size() < 2) return {-1, -1};

        for (int i = 1; i < prime.size(); i++)
        {
            if (prime[i] - prime[i - 1] < mini)
            {
                ans[0] = prime[i - 1];
                ans[1] = prime[i];
                mini = prime[i] - prime[i - 1];
                if (mini == 1)
                    return ans;
            }
        }

        return ans;
    }
};