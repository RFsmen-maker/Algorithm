#include <iostream>
#include <cmath>

using namespace std;

typedef struct {
        int n;
        int po;
        bool flag;
}N;

int main(void)
{
        int M, temp_1, temp_2;
        cin >> M;
        N array[M];
        for(int i = 0; i < M; i++)
        {
                array[i].po = array[i].flag = 0;
                cin >> array[i].n;
                temp_1 = array[i].n;
                while(temp_1 != 0)
                {
                        temp_1 /= 10;
                        array[i].po++;
                }
        }

        for(int i = 0; i < M; i++)
        {
                temp_1 = (int)pow(10, (float)array[i].po);
                for(int j = 1; j < 10; j++)
                {
                        temp_2 = j * array[i].n * array[i].n;
                        if(temp_2 % temp_1 == array[i].n) {
                                cout << j << ' ' << temp_2 << endl;
                                array[i].flag = 1;
                                break;
                        }
                }
                if(!array[i].flag) {
                        cout << "No" << endl;
                }
        }

        return 0;
}
