class Solution 
{
public:
    int passThePillow(int n, int time)
    {
        bool odd = (time / (n - 1)) % 2 == 0;

        if (odd)
        {
            return (time % (n - 1) + 1);
        }
        else
        {
            return (n - (time % (n - 1)));
        }

        return 0;
    }
};