class Solution
{
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& p1, vector<double>& r1, vector<vector<string>>& p2, vector<double>& r2)
    {
        unordered_map<string, double> um;
        um[initialCurrency] = 1.0;

        while (true)
        {
            bool test = true;
            for (int i = 0; i < p1.size(); i++)
            {
                if (um[p1[i][0]] * r1[i] > um[p1[i][1]])
                {
                    um[p1[i][1]] = um[p1[i][0]] * r1[i];
                    test = false;
                }

                if (um[p1[i][1]] / r1[i] > um[p1[i][0]])
                {
                    um[p1[i][0]] = um[p1[i][1]] / r1[i];
                    test = false;
                }
            }

            if (test)
                break;
        }

        while (true)
        {
            bool test = true;
            for (int i = 0; i < p2.size(); i++)
            {
                if (um[p2[i][0]] * r2[i] > um[p2[i][1]])
                {
                    um[p2[i][1]] = um[p2[i][0]] * r2[i];
                    test = false;
                }

                if (um[p2[i][1]] / r2[i] > um[p2[i][0]])
                {
                    um[p2[i][0]] = um[p2[i][1]] / r2[i];
                    test = false;
                }
            }

            if (test)
                break;
        }


        return um[initialCurrency];
    }
}; 