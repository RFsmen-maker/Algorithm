/*
 * P1035 普及，级数求和
 * S_n = 1 + 1/2 + 1/3 + ... + 1/n
 * 给出一个 k，计算出最小的 n，使得 S_n > k
 * 高等数学，泰勒公式：ln(n + 1) = 1 + 1/2 + 1/3 + ... + 1/n, n->∞
 * 调和级数：k = Sn = ln(n + 1) + gamma
 * n > e^(k - gamma) - 1
 * n = e^(k - gamma) + 0.5
 * 一般只用遍历...
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
        const double gamma = 0.5772156649;
        double k;
        cin >> k;
        // k = ln(n+1), n = e ^ k - 1;
        cout << static_cast<int>(exp(k - gamma) + 0.5);

        return 0;
}
