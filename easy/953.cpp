class Solution 
{
    unordered_map<char, int> um;

    bool cmp(string& a, string& b)
    {
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size())
        {
            if (um[a[i]] < um[b[i]]) 
                return false;
            else if (um[a[i]] > um[b[i]])
                return true;
            i++;
            j++;
        }

        if (a.size() <= b.size())
            return false;
        else
            return true;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) 
    {   
        for (int i = 0; i < 26; i++)
        {
            um[order[i]] = i;
        }

        for (int i = 1; i < words.size(); i++)
        {
            if (cmp(words[i - 1], words[i]))
                return false;
        }

        return true;
    }
};