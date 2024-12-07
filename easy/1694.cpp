class Solution 
{
public:
    string reformatNumber(string number) 
    {
        string tmp = "";

        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] != ' ' && number[i] != '-')
                tmp += number[i];
        }

        number = "";
        int i = 0;
        while (i < tmp.size())
        {
            if (tmp.size() - i > 4)
            {
                number += tmp[i++];
                number += tmp[i++];
                number += tmp[i++];
                number += '-';
            }
            else if (tmp.size() - i == 4)
            {
                number += tmp[i++];
                number += tmp[i++];
                number += '-';
                number += tmp[i++];
                number += tmp[i++];
            }
            else if (tmp.size() - i == 3)
            {
                number += tmp[i++];
                number += tmp[i++];
                number += tmp[i++];
            }
            else if (tmp.size() - i == 2)
            {
                number += tmp[i++];
                number += tmp[i++];
            }
        }

        return number;
    }
};