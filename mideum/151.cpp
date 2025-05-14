class Solution 
{
    void rev(int i, int j, string& s)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

public:
    string reverseWords(string s) 
    {
        // удалить пробелы в начале
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        s = s.substr(i, s.size() - i);

        // удалить пробелы с конца
        int j = s.size() - 1;
        while (s[j] == ' ')
        {
            j--;
        }        
        s = s.substr(0, j + 1);

        // свапаем всю строку
        rev(0, s.size() - 1, s);

        i = 0;
        while (i < s.size())
        {
            j = i;
            while (j < s.size() && s[j] != ' ')
            {
                j++;
            }
            j--;

            rev(i, j, s);

            i = j + 1;
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
        }

        i = 0; j = 0;
        while (j < s.size())
        {
            while (j < s.size() && s[j] != ' ')
            {
                s[i] = s[j];
                i++;
                j++;
            }

            if (j < s.size())
            {
                s[i] = s[j];
                i++;
                j++;
            }

            while (j < s.size() && s[j] == ' ')
            {
                j++;
            }
        }

        return s.substr(0, i);
    }
};