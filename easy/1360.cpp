class Solution 
{
    vector<int> vis{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    vector<int> novis{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
public:
    int daysBetweenDates(string date1, string date2) 
    {
        int days1 = 0;
        int days2 = 0;
        int year1 = stoi(date1.substr(0, 4));
        int moth1 = stoi(date1.substr(5, 2)) - 1;
        int day1 = stoi(date1.substr(8, 2));

        int year2 = stoi(date2.substr(0, 4));
        int moth2 = stoi(date2.substr(5, 2)) - 1;
        int day2 = stoi(date2.substr(8, 2));

        for (int i = 1970; i < year1; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                days1 += 366;
            else
                days1 += 365;
        }

        for (int i = 1970; i < year2; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                days2 += 366;
            else
                days2 += 365;
        }

        if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0))
            days1 += vis[moth1];
        else
            days1 += novis[moth1];

        if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
            days2 += vis[moth2];
        else
            days2 += novis[moth2];

        days1 += day1;
        days2 += day2;

        return abs(days1 - days2);
    }
};