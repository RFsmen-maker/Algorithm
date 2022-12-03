/*
Basic-1049 Sequence Fragment Addition
Algorithm the same as prismatic polygon.
The double is not enough, use the long double.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
        int N;
        cin >> N;
        long double tempDo, sum = 0.0;
        for(int i = 0; i < N; i++)
        {
                cin >> tempDo;
                sum += tempDo * (N - abs(i - N) + 1) * abs(i - N);
        }

        if(sum > 0) {
                cout.setf(ios_base::floatfield, ios_base::fixed);
                cout.precision(2);
                cout << sum;
        }
        else {
                cout << 0;
        }

        return 0;
}
