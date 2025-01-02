class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int n = num.size();
        vector<int> kk;
        while (k > 0)
        {
            kk.insert(kk.begin(), k % 10);
            k /= 10;
        }

        int one = 0;
        if (kk.size() >= n)
        {
            int i = kk.size() - 1;
            int j = n - 1;
            for (; i >= 0 && j >= 0; i--, j--)
            {
                int tmp = kk[i] + num[j] + one;
                if (tmp > 9)
                {
                    num[j] = tmp % 10;
                    one = 1;
                }
                else
                {
                    num[j] = tmp;
                    one = 0;
                }
            }

            while (i != -1)
            {
                int tmp = kk[i] + one;
                if (tmp > 9)
                {
                    num.insert(num.begin(), tmp % 10);
                    one = 1;
                }
                else
                {
                    num.insert(num.begin(), tmp);
                    one = 0;
                }
                
                i--;
            }

            if (one)
                num.insert(num.begin(), 1);
        }
        else
        {
            int i = kk.size() - 1;
            int j = n - 1;
            for (; i >= 0 && j >= 0; i--, j--)
            {
                int tmp = kk[i] + num[j] + one;
                if (tmp > 9)
                {
                    num[j] = tmp % 10;
                    one = 1;
                }
                else
                {
                    num[j] = tmp;
                    one = 0;
                }
            }

            while (j != -1)
            {
                int tmp = num[j] + one;
                if (tmp > 9)
                {
                    num[j] = tmp % 10;
                    one = 1;
                }
                else
                {
                    num[j] = tmp;
                    one = 0;
                }
                
                j--;
            }

            if (one)
                num.insert(num.begin(), 1);
        }

        return num;
    }
};