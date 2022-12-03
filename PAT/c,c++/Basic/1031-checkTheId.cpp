#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
        int N;
        cin >> N;
        char (*sequence)[18];
        sequence = (char (*)[18])malloc(N * 18 * sizeof(char));

        char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < 18; j++)
                {
                        cin >> sequence[i][j];
                }
        }

        int separate[17] = {
                7, 9, 10, 5, 8,
                4, 2, 1, 6, 3,
                7, 9, 10, 5, 8,
                4, 2};
        int sum;
        bool flag = 1;
        for(int i = 0; i < N; i++)
        {
                sum = 0;
                for(int j = 0; j < 17; j++)
                {
                        sum += ((sequence[i][j] - '0') * separate[j]);
                }
                sum %= 11;
                if(M[sum] != sequence[i][17]) {
                        for(int j = 0; j < 18; j++)
                        {
                                cout << sequence[i][j];
                        }
                        cout << endl;
                        flag = 0;
                }
        }

        if(flag)
                cout << "All Passed" << endl;

        return 0;
}
