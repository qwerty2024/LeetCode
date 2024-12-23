class Solution 
{
public:
    string bestHand(vector<int>& r, vector<char>& s) 
    {
        bool test = true;
        for (int i = 1; i < 5; i++)
        {
            if (s[i] != s[i - 1]) test = false;
        }

        if (test) return "Flush";


        vector<int> v(14, 0);
        for (auto a : r)
            v[a]++;

        for (int i = 0; i < 14; i++)
            if (v[i] > 2) return "Three of a Kind";

        for (int i = 0; i < 14; i++)
            if (v[i] > 1) return "Pair";


        return "High Card";
    }
};