class Solution
{
public:
    string oddString(vector<string>& w)
    {
        int n = w.size();
        int m = w[0].size();

        vector<int> diff0;
        vector<int> diff1;
        vector<int> diff2;

        for (int j = 1; j < m; j++)
        {
            diff0.push_back(w[0][j] - w[0][j - 1]);
            diff1.push_back(w[1][j] - w[1][j - 1]);
            diff2.push_back(w[2][j] - w[2][j - 1]);
        }

        vector<int>* etalon;
        if (diff0 == diff1)
        {
            etalon = &diff0;
        }
        else if (diff1 == diff2)
        {
            etalon = &diff1;
        }
        else if (diff0 == diff2)
        {
            etalon = &diff0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if ((*etalon)[j - 1] != w[i][j] - w[i][j - 1])
                    return w[i];
            }
        }

        return w[0];
    }
};