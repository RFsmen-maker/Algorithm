/*
* Basic-1047 Programming Teamwork
*/
#include <iostream>

using namespace std;

int main(void)
{
        int N;
        cin >> N;
        int team[1001] = {0};

        int BestTeam = 0;
        while(N--)
        {
                int tempSeq, tempMat, tempSco;
                scanf("%d-%d %d", &tempSeq, &tempMat, &tempSco);
                team[tempSeq] += tempSco;
                if(team[tempSeq] > team[BestTeam]) BestTeam = tempSeq;
        }

        cout << BestTeam << ' ' << team[BestTeam];

        return 0;
}
