class Solution 
{
public:
    int maxDistance(vector<int>& colors) 
    {
        int n = colors.size();
        int maxi = 0;

        int i = n - 1;
        while (i > 0)
        {
            if (colors[0] != colors[i])
            {
                maxi = max(maxi, i);
                break;
            }

            i--;
        }

        i = 0;
        while (i < n - 1)
        {
            if (colors[n - 1] != colors[i])
            {
                maxi = max(maxi, n - i - 1);
                break;
            }

            i++;
        }

        return maxi;
    }
};