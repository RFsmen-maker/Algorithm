/*
 * 18041. 分期还款（加强版）
 * 一定要注意特殊情况过滤
 */
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
        double d, p, r; // 贷款额、每月还款、月利率
        cin >> d >> p >> r;

        if (d == 0.0) {
                cout << "0.0";
                return 0;
        }

        if (d * (r + 1.0) - p > d) {
                cout << "God";
                return 0;
        }

        printf("%.1f", log(p / (p - d * r)) / log(1.0 + r));

        return 0;
}
