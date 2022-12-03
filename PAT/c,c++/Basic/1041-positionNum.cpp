#include <iostream>

using namespace std;

typedef struct data
{
        char sequence[17];
        int tryP;
        int exmP;
}Data;

int main(void)
{
        int N, M;

        cin >> N;
        Data student[N];

        for(int i = 0; i < N; i++)
        {
                cin >> student[i].sequence;
                cin >> student[i].tryP;
                cin >> student[i].exmP;
        }

        cin >> M;
        int emptyP[M];
        for(int i = 0; i < M; i++)
        {
                cin >> emptyP[i];
        }

        for(int i = 0; i < M; i++)
        {
                for(int j = 0; j < N; j++)
                {
                        if(emptyP[i] == student[j].tryP) {
                                cout << student[j].sequence
                                <<' '<< student[j].exmP;
                                if(i != M-1)
                                        cout << endl;
                        }
                }
        }

        return 0;
}
