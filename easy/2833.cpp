class Solution 
{
public:
    int furthestDistanceFromOrigin(string moves) 
    {
        int count_L = 0;
        int count_R = 0;
        int count_ = 0;

        for (auto a : moves)
            if (a == '_')
                count_++;
            else if (a == 'L')
                count_L++;
            else if (a == 'R')
                count_R++;

        return (count_L > count_R) ? count_L + count_ - count_R : count_R + count_ - count_L;
    }
};