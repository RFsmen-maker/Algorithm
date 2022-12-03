/*
* Basic-1032 Best Digger
* 一定要注意所有输出数值的可取范围
*/
#include <iostream>

using namespace std;

int main(void)
{
        typedef struct SCHOOL{
                int sequence;
                int score;
        }School;

        int N, maxInd = 1;
        cin >> N;
        School school[N+1];
        for(int i = 0; i < N+1; i++)
        {
                school[i].sequence = i;
                school[i].score = 0;
        }
        for(int i = 0; i < N; i++)
        {
                int tempSeq, tempSco;
                cin >> tempSeq >> tempSco;
                school[tempSeq].score += tempSco;
                if(school[tempSeq].score > school[maxInd].score) maxInd = tempSeq;
        }

        cout << school[maxInd].sequence << ' ' << school[maxInd].score;

        return 0;
}
