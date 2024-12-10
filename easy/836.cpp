class Solution 
{
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) 
    {
        bool test = true;

        if (r1[0] >= r2[2] ||
            r1[2] <= r2[0] ||
            r1[3] <= r2[1] ||
            r1[1] >= r2[3])
        {
            test = false;
        }

        return test;
    }
};