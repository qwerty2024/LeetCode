class Solution 
{
public:
    int getCommon(vector<int>& n1, vector<int>& n2) 
    {
        int n = n1.size();
        int m = n2.size();

        int i = 0;
        int j = 0;

        while (i < n && j < m)
        {
            if (n1[i] == n2[j])
                return n1[i];
            else if (n1[i] > n2[j])
                j++;
            else
                i++;
        }


        return -1;
    }
};