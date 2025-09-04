class Solution 
{
public:
    int findClosest(int x, int y, int z) 
    {
        int len1 = abs(z - x);
        int len2 = abs(z - y);

        return len1 == len2 ? 0 : len1 > len2 ? 2 : 1;
    }
};