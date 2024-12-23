class Solution 
{
public:
    bool strongPasswordCheckerII(string p) 
    {
        unordered_set<char> us{'!','@','#','$','%','^','&','*','(',')','-','+'};
        int n = p.size();
        bool test1 = true;
        bool test2 = true;
        bool test3 = true;
        bool test4 = true;

        if (n < 8) return false;

        for (int i = 0; i < n; i++)
        {
            if (p[i] >= 'a' && p[i] <= 'z') test1 = false;
            if (p[i] >= 'A' && p[i] <= 'Z') test2 = false;
            if (p[i] >= '0' && p[i] <= '9') test3 = false;
            if (us.contains(p[i]))          test4 = false;
        }

        if (test1) return false;
        if (test2) return false;
        if (test3) return false;
        if (test4) return false;    

        for (int i = 1; i < n; i++)
        {
            if (p[i] == p[i - 1]) return false;
        }

        return true; 
    }
};