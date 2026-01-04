class Solution
{
    vector<int> eratosfen(int n)
    {
        n = n / 2;
        vector<int> divisor;

        for (int i = 2; i < n; i++)
        {
            bool flag = true;
            for (const auto& a : divisor)
            {
                if (i == a)
                    break;

                if (i % a == 0)
                    flag = false;
            }

            if (flag)
                divisor.push_back(i);
        }

        return divisor;
    }

public:
    int sumFourDivisors(vector<int>& nums)
    {
        int ans = 0;
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> er = eratosfen(maxi + 2);

        //for (const auto& a : er)
        //{
        //    cout << a << " ";
        //}

        unordered_map<int, int> um;
        for (const auto& a : nums)
        {
            um[a]++;
        }

        int n = er.size();

        //if (n > 111)
            //n = 111;

        for (int i = 0; i < n - 1; i++)
        {
            if (er[i] < 100 && um.contains(er[i] * er[i] * er[i]))
            {
                ans += um[er[i] * er[i] * er[i]] * (er[i] + er[i] * er[i] + 1 + er[i] * er[i] * er[i]);
            }

            for (int j = i + 1; j < n; j++)
            {
                if ((long long)er[i] * er[j] <= maxi)
                {
                    if (um.contains(er[i] * er[j]))
                    {
                        //cout << er[i] << " " << er[j] << "\n";
                        ans += um[er[i] * er[j]] * (er[i] + er[j] + 1 + er[i] * er[j]);
                    }
                }
                else
                    break;
            }
        }

        return ans;
    }
};