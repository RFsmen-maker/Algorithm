/*
 * 18049. 迭代法求平方根
 */
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
        // Xk+1 = (Xk + n / Xk) / 2
        double n;
        cin >> n;
        double x = n;
        while (fabs(x * x - n) > 1e-5) {
                x = (x + n / x) / 2.0;
        }
        printf("%.4f", x);

        return 0;
}
