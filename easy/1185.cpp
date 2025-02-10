class Solution 
{
public:
    string dayOfTheWeek(int day, int month, int year) 
    {
        // 1 января 1969 год не високосный - среда

        int count = 0;
        int y = 1969;
        int v = 1;
        bool curr = false;
        while (y != year)
        {
            if (v % 4 == 0)
            {
                count += 366;
                v = 1;
            }
            else
            {
                count += 365;
                v++;
            }

            y++;
        }

        if (v == 4 && year != 2100) curr = true;

//cout << count << endl;
//cout << curr;

        vector<int> months {};

        if (curr)
        {
            months = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
        }
        else
        {
            months = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        }

        count += months[month - 1];

        count += day;
        
        vector<string> tmp{"Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday"};

        return tmp[count % 7];
    }
};