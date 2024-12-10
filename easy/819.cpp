class Solution 
{
public:
    string mostCommonWord(string par, vector<string>& ban) 
    {
        transform(par.begin(), par.end(), par.begin(), ::tolower);
        unordered_map<string, int> um;

        int i = 0;
        while (i < par.size())
        {
            if (par[i] >= 'a' && par[i] <= 'z')
            {
                string tmp = "";

                while (i < par.size() && (par[i] >= 'a' && par[i] <= 'z'))
                {
                    tmp += par[i];
                    i++;
                }

                um[tmp]++;
            }

            i++;
        }

        //for (auto a : um)
        //    cout << a.first << " " << a.second << endl;

        unordered_set<string> bann;
        for (auto a : ban)
            bann.insert(a);

        string ans = "";
        int maxi = 0;
        for (auto a : um)
        {
            if (!bann.contains(a.first) && a.second > maxi)
            {
                ans = a.first;
                maxi = a.second;
            }
        }

        return ans;
    }
};