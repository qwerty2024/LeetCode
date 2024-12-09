class Solution 
{
public:
    bool canAliceWin(int n) 
    {
        int x = 10;
        bool test = true;
        char ch = 'a'; // чей ход

        while (n >= 0)
        {
            if (ch == 'a')
            {
                if (n >= x)
                {
                    ch = 'b';
                    n -= x;
                    x--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (n >= x)
                {
                    ch = 'a';
                    n -= x;
                    x--;
                }
                else
                {
                    return true;
                }
            }
        }

        return true;
    }
};