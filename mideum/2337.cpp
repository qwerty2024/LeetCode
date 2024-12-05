class Solution 
{
public:
    bool canChange(string s, string t) 
    {
        int n = s.size();
        int slow = 0;
        int fast = 0;

        while (fast < n && slow < n)
        {
            if (fast < slow) fast = slow;
            if (t[slow] == 'L' && s[slow] != 'L')
            {
                while (fast < n && s[fast] == '_')
                {
                    fast++;
                }

                if (s[fast] == 'L' && s[slow] == '_')
                {
                    swap(s[slow], s[fast]);
                }
                //else break;
            }

            //fast++;
            slow++;
        }

        //cout << "\"" << s  << "\"" << endl;

        slow = n - 1;
        fast = slow;
        while (fast > 0 && slow > 0)
        {
            if (fast > slow) fast = slow;
            if (t[slow] == 'R' && s[slow] != 'R')
            {
                while (fast > 0 && s[fast] == '_')
                {
                    fast--;
                }

                if (s[fast] == 'R' && s[slow] == '_')
                {
                    swap(s[slow], s[fast]);
                }
                //else break;
            }

            //fast--;
            slow--;
        }


        return s == t;
    }
};