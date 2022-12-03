/*
* Basic-1026 Program's Running Time
*/
#include <iostream>

using namespace std;

int main(void)
{
        int c1, c2;
        cin >> c1 >> c2;
        const double CLK = 100;
        int result = (int)((c2-c1) / CLK + 0.5);

        int hours = result / 3600;
        result %= 3600;
        int mins = result / 60;
        int seconds = result % 60;

        printf("%02d:%02d:%02d", hours, mins, seconds);

        return 0;
}
