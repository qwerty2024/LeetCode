class Solution 
{
public:
    int maxContainers(int n, int w, int maxWeight) 
    {
        int nn = n * n;
        int ww = maxWeight / w;

        return min(ww, nn);
    }
};