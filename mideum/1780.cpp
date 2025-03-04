struct Data
{
    vector<int> powers;

    Data()
    {
        int curr = 1;
        powers.push_back(1);

        for (int i = 1; ; i++)
        {
            curr *= 3;
            powers.push_back(curr);

            if (curr > 10000001)
                break;
        }
    }
};

class Solution 
{
    Data d;

public:
    bool checkPowersOfThree(int n) 
    {
        //for (auto a : d.powers)
        //    cout << a << " ";

        int i = d.powers.size() - 1;
        
        while (i >= 0)
        {
            if (d.powers[i] <= n)
                n -= d.powers[i];

            if (n == 0) 
                return true;

            i--;
        }

        return false;
    }
};