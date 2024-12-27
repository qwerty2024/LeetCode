class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        string tmp = "";

        while (n > 0)
        {
            //cout << n << endl;
            if (n % 2 == 0)
                tmp += '0';
            else
                tmp += '1';

            n >>= 1;
        }

        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i] == tmp[i - 1])
                return false;
        }

        return true;
    }
};