class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        string ans = "";

        if (num1.size() < num2.size()) 
            swap(num1, num2);
    
        int i = num2.size() - 1;
        int j = num1.size() - 1;
        int one = 0;
        while (i >= 0)
        {
            int tmp = num1[j] - '0' + num2[i] - '0' + one;

            //cout << tmp << endl;

            if (tmp > 9)
            {
                one = 1;
                //ans = (char)(tmp - 10 + '0') + ans;
                ans += (char)(tmp - 10 + '0');
            }
            else
            {
                one = 0;
                //ans = (char)(tmp + '0') + ans;
                ans += (char)(tmp + '0');
            }

            i--;
            j--;
        }

        i = num1.size() - num2.size() - 1;

        while (i >= 0)
        {
            int tmp = num1[i] - '0' + one;

            if (tmp > 9)
            {
                one = 1;
                //ans = (char)(tmp - 10 + '0') + ans;
                ans += (char)(tmp - 10 + '0');
            }
            else
            {
                one = 0;
                //ans = (char)(tmp + '0') + ans;
                ans += (char)(tmp + '0');
            }

            i--;
        }

        if (one == 1 && i < 0)
        {
            //ans = '1' + ans;
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};