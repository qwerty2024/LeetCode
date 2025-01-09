class Solution 
{
public:
    string reformat(string s) 
    {
        string tmp_num = "";
        string tmp_let = "";
        for (auto a : s)
        {
            if (a >= 'a' && a <= 'z')
            {
                tmp_let += a;
            }
            else
            {
                tmp_num += a;
            }
        }    

        if (abs((int)tmp_num.size() - (int)tmp_let.size()) > 1)
            return "";

        string ans = "";
        int i = 0;
        int j = 0;
        int k = 0;
        bool flag = tmp_let.size() > tmp_num.size() ? false : true;
        while (k < s.size())
        {
            if (flag)
            {
                ans += tmp_num[i];
                i++;
                flag = false;
            }
            else
            {
                ans += tmp_let[j];
                j++;
                flag = true;
            }
            k++;
        }

        return ans;
    }
};