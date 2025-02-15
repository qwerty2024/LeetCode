class Solution
{
    int test(vector<vector<int>>& squares, double y)
    {
        int n = squares.size();
        double s1 = 0;
        double s2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (squares[i][1] > y)
            {
                s2 += (double)squares[i][2] * (double)squares[i][2];
                continue;
            }

            if (squares[i][1] + squares[i][2] < y)
            {
                s1 += (double)squares[i][2] * (double)squares[i][2];
                continue;
            }

            s1 += (double)squares[i][2] * (y - (double)squares[i][1]);
            s2 += (double)squares[i][2] * ((double)squares[i][1] + (double)squares[i][2] - y);
        }

        if (abs(s1 - s2) < 0.00001)
            return -1;

        return s1 > s2 ? 0 : 1;
    }

public:
    double separateSquares(vector<vector<int>>& squares)
    {
        double l = 0.0;
        double r = 10000000001.0;
        double mid = r;

        while (l <= r)  // (true)
        {
            mid = l + (r - l) / 2;
            int d = test(squares, mid);

            if (d == -1)
                break;

            if (d)
            {
                l = mid + 0.000001;
            }
            else
            {
                r = mid - 0.000001;
            }
        }

        int n = squares.size();
        int ind = 0;
        double mini = 9999999999;

        for (int i = 0; i < n; i++)
        {
            if (squares[i][1] < mid && squares[i][1] + squares[i][2] > mid)
            {
                return mid;
            }

            if (squares[i][1] + squares[i][2] < mid)
            {
                mini = min(mini, mid - (squares[i][1] + squares[i][2]));
            }
        }

        return mid - mini;
    }
}; 