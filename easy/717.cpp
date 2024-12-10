class Solution 
{
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();

        string tmp = "";

        int i = 0;
        while (i < n)
        {
            if (bits[i] == 0)
            {
                tmp += 'a';
            }
            else
            {
                i++;
                tmp += 'b';
            }

            i++;
        }

        return (tmp[tmp.size() - 1] == 'a') ? true : false;
    }
};