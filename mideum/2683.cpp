class Solution 
{
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n = derived.size();
        int curr = 0;

        for (int i = 0; i < n; i++)
        {
            curr ^= derived[i];
        }

        if (curr == 0)
            return true;

        curr = 1;

        for (int i = 0; i < n; i++)
        {
            curr ^= derived[i];
        }

        if (curr == 1)
            return true;

        return false;
    }
};