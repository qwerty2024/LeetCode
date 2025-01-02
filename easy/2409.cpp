class Solution 
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
    {
        vector<int> d{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aAm = stoi(arriveAlice.substr(0, 2)) - 1;
        int aAd = stoi(arriveAlice.substr(3, 2)) - 1;

        int lAm = stoi(leaveAlice.substr(0, 2)) - 1;
        int lAd = stoi(leaveAlice.substr(3, 2)) - 1;

        int aBm = stoi(arriveBob.substr(0, 2)) - 1;
        int aBd = stoi(arriveBob.substr(3, 2)) - 1;
 
        int lBm = stoi(leaveBob.substr(0, 2)) - 1;
        int lBd = stoi(leaveBob.substr(3, 2)) - 1;

        pair<int, int> aa{0 , 0};
        for (int i = 0; i < 12 && i < aAm; i++)
            aa.first += d[i];
        aa.first += aAd;

        for (int i = 0; i < 12 && i < lAm; i++)
            aa.second += d[i];
        aa.second += lAd;


        pair<int, int> bb{0 , 0};
        for (int i = 0; i < 12 && i < aBm; i++)
            bb.first += d[i];
        bb.first += aBd;

        for (int i = 0; i < 12 && i < lBm; i++)
            bb.second += d[i];
        bb.second += lBd;

        int ans = 0;

        for (int i = 0; i < 365; i++)
        {
            if (i >= aa.first && i <= aa.second && i >= bb.first && i <= bb.second)
                ans++;
        }

        return ans;
    }
};