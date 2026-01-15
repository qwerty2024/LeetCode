class Solution 
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        //hBars.push_back(1);
        //vBars.push_back(1);
        //hBars.push_back(n + 2);
        //vBars.push_back(m + 2);
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxiH = 1;
        int maxiV = 1;

        int current = 1;
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] - hBars[i - 1] == 1)
            {
                current++;
                maxiH = max(maxiH, current);                
            }
            else
            {
                current = 1;
            }
        }

        current = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] - vBars[i - 1] == 1)
            {
                current++;
                maxiV = max(maxiV, current);
            }
            else
            {
                current = 1;
            }
        }

        return min(maxiV + 1, maxiH + 1) * min(maxiV + 1, maxiH + 1);
    }
};