#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
        int N, temp, count = 0;
        bool flag;
        cin >> N;

        temp = 3;
        for(int i = 3; i <= N; i++)
        {
                flag = 1;
                for(int j = 2; j <= sqrt(i); j++)
                {
                        if(!(i % j)) {
                                flag = 0;
                                break;
                        }
                }
                if(flag) {
                        if(i - temp == 2)
                                count++;
                        temp = i;
                }
        }

        cout << count;

        return 0;
}
