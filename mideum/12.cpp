class Solution 
{
public:
    string intToRoman(int num) 
    {
        string ans = "";

        while (num > 0)
        {
            if (num > 999)
            {
                for (int i = 0; i < num / 1000; i++)
                {
                    num -= 1000;
                    ans += 'M';
                }
            }
            else if (num > 499)
            {
                if (num >= 900)
                {
                    ans += "CM";
                    num -= 900;
                }
                else
                {
                    ans += 'D';
                    num -= 500;
                }
            }
            else if (num > 99)
            {
                if (num >= 400)
                {
                    ans += "CD";
                    num -= 400;
                }
                else
                {
                    for (int i = 0; i < num / 100; i++)
                    {
                        num -= 100;
                        ans += 'C';
                    }
                }
            }
            else if (num > 49)
            {
                if (num >= 90)
                {
                    ans += "XC";
                    num -= 90;
                }
                else
                {
                    ans += 'L';
                    num -= 50;
                }
            }
            else if (num > 9)
            {
                if (num >= 40)
                {
                    ans += "XL";
                    num -= 40;
                }
                else
                {
                    for (int i = 0; i < num / 10; i++)
                    {
                        num -= 10;
                        ans += 'X';
                    }
                }
            }
            else if (num > 4)
            {
                if (num == 9)
                {
                    ans += "IX";
                    num -= 9;
                }
                else
                {
                    ans += 'V';
                    num -= 5;
                }
            }
            else
            {
                if (num == 4)
                {
                    ans += "IV";
                    num -= 4;
                }
                else
                {
                    for (int i = 0; i < num; i++)
                    {
                        num -= 1;
                        ans += 'I';
                    }
                }
            }
        }

        return ans;
    }
};