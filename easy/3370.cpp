class Solution 
{
public:
    int smallestNumber(int n) 
    {
        if (n > 511)
            return 1023;

        if (n > 255)
            return 511;

        if (n > 127)
            return 255;

        if (n > 63)
            return 127;

        if (n > 31)
            return 63;
        
        if (n > 15)
            return 31;

        if (n > 7)
            return 15;

        if (n > 3)
            return 7;

        if (n > 1)
            return 3;

        return 1;
    }
};