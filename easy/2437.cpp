class Solution 
{
public:
    int countTime(string t) 
    {
        int left_var = 1;
        int right_var = 1;

        if (t[0] == '?' && t[1] == '?')
        {
            left_var = 24;
        }
        else if (t[0] == '?')
        {
            if (t[1] < '4')
                left_var = 3;
            else
                left_var = 2;
        }
        else if (t[1] == '?')
        {
            if (t[0] == '2')
                left_var = 4;
            else
                left_var = 10;
        }


        if (t[3] == '?' && t[4] == '?')
        {
            right_var = 60;
        }
        else if (t[3] == '?')
        {
            right_var = 6;
        }
        else if (t[4] == '?')
        {
            right_var = 10;
        }

        return left_var * right_var;
    }
};