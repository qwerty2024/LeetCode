class Solution 
{
public:
    string getHappyString(int n, int k) 
    {
        string ans = "";

        int right = 3 * pow(2, n - 1);
        int left = 1;
        char prev = 'a';

        if (k <= right / 3)
        {
            right = right / 3;
            ans += 'a';
        } 
        else if (k <= (right / 3) * 2)
        {
            left = right / 3 + 1;
            right = (right / 3) * 2;
            ans += 'b';
            prev = 'b';
        }
        else if (k <= right)
        {
            left = (right / 3) * 2 + 1;
            ans += 'c';
            prev = 'c';
        }
        else
            return "";

        for(int i = 1; i < n; i++)
        {
            int mid = left + (right - left + 1) / 2;
            if (k < mid)
            {
                char sym = prev == 'a' ? 'b' : 'a';
                right = mid - 1;
                ans += sym;
                prev = sym;
            }
            else 
            {
                char sym = prev == 'c' ? 'b' : 'c';
                left = mid;
                ans += sym;
                prev = sym;
            }
        }

        return ans;
    }
};