/*
Basic-1022 D Scale A+B
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
        const unsigned int MAX = 1000;
        unsigned int A, B, D;
        cin >> A >> B >> D;

        unsigned int tempSum = A + B;
        if(!tempSum) {
                cout << 0;
                return 0;
        }

        unsigned int result[MAX] = {0};
        unsigned int tempCo = 0;

        while(tempSum)
        {
                if(tempSum % D) {
                        result[tempCo] = tempSum % D;
                }
                else {
                        result[tempCo] = 0;
                }
                tempCo++;
                tempSum /= D;
        }

        for(int i = tempCo-1; i >= 0; --i)
        {
                cout << result[i];
        }

        return 0;
}
