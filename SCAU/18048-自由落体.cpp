/*
 * 18048. 自由落体
 */
#include <iostream>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        if (n == 0) {
                cout << 0.000;
                return 0;
        }

        double height = 100.0, sum = height;
        height /= 2;
        while (--n) {
                sum += 2.0 * height;
                height /= 2.0;
        }
        printf("%.03f %.03f", sum, height);

        return 0;
}
