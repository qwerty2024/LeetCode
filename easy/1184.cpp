class Solution 
{
public:
    int distanceBetweenBusStops(vector<int>& d, int start, int dest) 
    {
        int n = d.size();
        int a = 0;
        int b = 0;

        int i = start;
        int j = dest;
        while (i != j)
        {
            a += d[i];
            i++;
            i %= n;
        }

        j = start;
        i = dest;
        while (i != j)
        {
            b += d[i];
            i++;
            i %= n;
        }

        return min(a, b);
    }
};