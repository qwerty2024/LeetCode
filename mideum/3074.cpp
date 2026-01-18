class Solution 
{
    long long fnk(int i, const int& x1_1, const int& y1_1,const int& x1_2, const int& y1_2, const int& x2_1, const int& y2_1, const int& x2_2, const int& y2_2)
    {
        if (x1_1 > x2_2)
            return fnk(i, x2_1, y2_1, x2_2, y2_2, x1_1, y1_1, x1_2, y1_2);

        if (y1_2 <= y2_1 || y1_1 >= y2_2 || x1_2 <= x2_1)
            return 0;

        int x1 = max(x1_1, x2_1);
        int y1 = max(y1_1, y2_1);
        int x2 = min(x1_2, x2_2);
        int y2 = min(y1_2, y2_2);

        int mini = min(x2 - x1, y2 - y1);

        return 1LL * mini * mini;
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) 
    {
        long long maxi = 0;

        for (int i = 0; i < bottomLeft.size() - 1; i++)
        {
            for (int j = i + 1; j < bottomLeft.size(); j++)
            {
                maxi = max(maxi, fnk(i, bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1], bottomLeft[j][0], bottomLeft[j][1], topRight[j][0], topRight[j][1]));
            }
        }

        return maxi;
    }
};