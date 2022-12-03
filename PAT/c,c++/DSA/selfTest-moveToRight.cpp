#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(void)
{
        int N, M;
        cin >> N >> M;
        int number[N];
        M %= N;

        for(int i = 0; i < N; i++)
                cin >> number[i];
        for(int i = M; i > M - N; i--)
        {
                cout << number[(abs(i - N) % N)];
                if(i > (M - N + 1))
                        cout << ' ';
        }
        cout << '\n';

        return 0;
}
