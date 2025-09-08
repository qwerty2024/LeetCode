class Solution 
{
    void give_me(string& nn, int pos)
    {
        if (pos == 0)
        {
            if (nn[0] == '1')
                nn[0] = '-';
            else
                nn[0] = nn[0] - 1;
            return;
        }

        if (nn[pos] > '0')
        {
            nn[pos]--;
            return;
        }

        nn[pos] = '9';
        give_me(nn, pos - 1);
    }

public:
    vector<int> getNoZeroIntegers(int n) 
    {
        string a = "";
        string b = "";
        string nn = to_string(n);
        int len = nn.size();

        int pos = len - 1;

        while (pos >= 0)
        {
            if (nn[pos] == '-')
                break; 

            if (nn[pos] == '0')
            {
                give_me(nn, pos - 1);
                a += '5';
                b += '5';
                pos--;
                continue;
            }

            if (nn[pos] == '1')
            {
                if (pos == 0)
                {
                    a += '1';
                    break;
                }
                give_me(nn, pos - 1);
                a += '6';
                b += '5';
                pos--;
                continue;
            }

            a += (nn[pos] - 1);
            b += '1';
            pos--;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return {stoi(a), stoi(b)};
    }
};