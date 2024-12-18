class Solution 
{
public:
    string winningPlayer(int x, int y) 
    {
        int tmp = min(x, y / 4);

        return (tmp % 2 == 1) ? "Alice" : "Bob";
    }
};