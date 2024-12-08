class Solution 
{
public:
    int maxRectangleArea(vector<vector<int>>& p) 
    {
        int n = p.size();
        vector<bool> select(n, false);

        // Выбираем первые 4 элемента
        fill(select.begin(), select.begin() + 4, true);

        int ans = -1;
        
        do {
            vector<vector<int>> tmp;
            
            for (int i = 0; i < p.size(); ++i) 
            {
                if (select[i]) 
                {
                    tmp.push_back(p[i]);
                }
            }

            sort(tmp.begin(), tmp.end());

            bool test = true;
            
            if (tmp[0][0] == tmp[1][0] && tmp[2][0] == tmp[3][0] &&
                tmp[0][1] == tmp[2][1] && tmp[1][1] == tmp[3][1])
            {
                for (int i = 0; i < p.size(); ++i) // проверка нет ли точек внутри или на границе
                {
                    if (!select[i]) 
                    {
                        if ((p[i][0] >= tmp[0][0] && p[i][0] <= tmp[2][0]) &&
                            (p[i][1] >= tmp[0][1] && p[i][1] <= tmp[1][1])) 
                            test = false;
                    }
                }

                if (test)
                {
                    int s = (tmp[1][1] - tmp[0][1]) * (tmp[2][0] - tmp[0][0]);
                    ans = max(ans, s);
                }
            }    
 
        } while (prev_permutation(select.begin(), select.end()));

        return ans;
    }
};