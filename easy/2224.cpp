class Solution 
{
public:
    int convertTime(string curr, string corr) 
    {
        int ans = 0;
        string h1 = curr.substr(0, 2);
        string h2 = corr.substr(0, 2);
        string m1 = curr.substr(3, 2);
        string m2 = corr.substr(3, 2);

        int hh1 = stoi(h1);
        int hh2 = stoi(h2);
        int mm1 = stoi(m1);
        int mm2 = stoi(m2);

        int ost = (hh2 - hh1) * 60 + (mm2 - mm1);

        for (; ost > 0;)
        {
            if (ost >= 60)
            {
                ost -= 60;
            }   
            else if (ost >= 15)
            {
                ost -= 15;
            }
            else if (ost >= 5)
            {
                ost -= 5;
            }
            else ost -= 1;

            ans++; 
        }

        return ans;
    }
};