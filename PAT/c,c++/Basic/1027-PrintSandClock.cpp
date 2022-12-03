/*
* Basic-1027 Sand Clock
* 数列求和问题：把沙漏当作两个三角形
* 每个三角形的符号个数即数列和
* 每个三角形 Sn = (1 + 2n-1)n / 2
* 整个沙漏需要符号 S = 2n^2 - 1
* 给出一个 S， n = sqrt((S+1)/2)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
        int S, n;
        char shape;
        cin >> S >> shape;

        n = sqrt((S+1) / 2);

        for(int i = 0; i < 2*n-1; i++)
        {
                for(int j = 0; j < n-1-abs(n-1-i); j++) cout << ' ';
                for(int j = 0; j < 2*abs(n - 1 - i)+1; j++) cout << shape;
                cout << endl;
        }

        cout << S - 2 * pow(n, 2.0) + 1;

        return 0;
}
