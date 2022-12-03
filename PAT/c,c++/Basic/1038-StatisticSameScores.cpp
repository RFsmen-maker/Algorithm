/*
* Basic-1038 Statistic Same Scores
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        int N;
        cin >> N;

        int scoAmo[101] = {0};
        while(N--)
        {
                int tempSco;
                cin >> tempSco;
                scoAmo[tempSco]++;
        }

        cin >> N;
        vector<int> check;
        for(int i = 0; i < N; i++)
        {
                int tempChe;
                cin >> tempChe;
                check.push_back(tempChe);
        }

        for(int i = 0; i < N-1; i++)
                cout << scoAmo[check[i]] << ' ';
        cout << scoAmo[check[N-1]];

        return 0;
}
