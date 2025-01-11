class Solution 
{
public:
    int closetTarget(vector<string>& words, string target, int startIndex) 
    {
        int n = words.size();
        bool flag = false;

        for (auto a : words)
            if (a == target)
            {
                flag = true;
                break;
            }

        if (!flag) return -1;

        int len1 = 0;
        int len2 = 0;

        int i = startIndex;
        while (words[i] != target)
        {
            len1++;
            i++;
            if (i == n)
                i = 0;
        }

        i = startIndex;
        while (words[i] != target)
        {
            len2++;
            i--;
            if (i == -1)
                i = n - 1;
        }

        return min(len1, len2);
    }
};