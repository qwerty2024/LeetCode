class Solution
{
    int n = 0;
    int nO = 0;

    //bool test(string s, int len)
    //{
    //    int curr_len = 1;
    //    int count = 0;
    //    for (int i = 1; i < n; i++)
    //    {
    //        if (s[i] == s[i - 1])
    //        {
    //            curr_len++;
    //            if (curr_len > len)
    //            {
    //                s[i] = (s[i] == '1') ? '0' : '1';
    //                count++;
    //                curr_len = 1;
    //            }
    //        }
    //        else
    //        {
    //            curr_len = 1;
    //        }
    //    }
    //
    //    return count <= nO;
    //}

public:
    int minLength(string s, int numOps)
    {
        nO = numOps;
        n = s.size();
        if (n == 1) return 1;
        int count1 = 0;
        int count2 = 0;

        // случай когда длина может равнятся 1 (1010101010101)
        string tmp1 = s; //(1010101010101...)
        string tmp2 = s; //(0101010101010...)
        int i = 0;
        while (i < n)
        {
            if (i % 2 == 0)
            {
                if (tmp1[i] != '1')
                    count1++;
                if (tmp2[i] != '0')
                    count2++;
            }
            else
            {
                if (tmp1[i] != '0')
                    count1++;
                if (tmp2[i] != '1')
                    count2++;
            }

            i++;
        }

        if (count1 <= numOps) return 1;
        if (count2 <= numOps) return 1;


        auto getops = [&](int maxConsecutive) -> bool 
        {
            int streak = 1, currChar = s[0], ans = 0;
            for (int i = 1; i < n; i++) 
            {
                if (s[i] == currChar) 
                {
                    streak++;
                    if (streak > maxConsecutive) 
                    {
                        // flip
                        streak = 1, currChar = !s[i], ans++;
                    }
                }
                else 
                {
                    streak = 1, currChar = s[i];
                }
            }
            return ans <= numOps;
        };


        // бинарный поиск [2,n]
        int l = 2;
        int r = n;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            //if (test(s, mid))
            if (getops(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};