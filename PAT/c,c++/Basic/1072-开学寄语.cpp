#include <iostream>

using namespace std;

int main(void)
{
        class Student{
        public:
                char name[5];
                int amount;
                int *object;
        };

        int N, M;
        cin >> N >> M;
        int *ban = new int[M];
        for(int i = 0; i < M; i++)
        {
                cin >> ban[i];
        }

        int caught = 0;
        int totalCount = 0;
        while(N--)
        {
                Student student;
                cin >> student.name >> student.amount;
                student.object = new int[student.amount];
                for(int i = 0; i < student.amount; i++)
                {
                        cin >> student.object[i];
                }

                int count = 0;
                for(int i = 0; i < student.amount; i++)
                {
                        for(int j = 0; j < M; j++)
                        {
                                if((student.object[i]-ban[j]) == 0) {
                                        if(!count) {
                                                cout << student.name << ":";
                                        }
                                        cout << " ";
                                        int zeroCheck = ban[j] <= 10 ? 3 : ban[j] <= 100 ? 2 : ban[j] <= 1000 ? 1 : 0;
                                        while(zeroCheck--)
                                                cout << '0';
                                        cout << ban[j];
                                        count++;
                                }
                        }
                }
                if(count) {
                        caught++;
                        cout << endl;
                }
                totalCount += count;
        }

        cout << caught << ' ' << totalCount;

        return 0;
}
