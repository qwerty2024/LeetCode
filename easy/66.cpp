class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        int p = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] + p > 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += p;
                p = 0;
                break;
            }
        }

        if (p == 1)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};