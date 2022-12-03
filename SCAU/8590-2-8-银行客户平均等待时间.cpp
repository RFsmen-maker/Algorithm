/*
 * 8590-2.8 队列应用——银行客户平均等待时间
 * 无视给出的 C，直接用 C++
*/
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
        int n;
        cin >> n;

        if (n <= 1) { // 过滤
                double dummy;
                while (n--) cin >> dummy;
                cout << "0.00";
                return 0;
        }

        queue<pair<double, double>> q; // 队列记录时间段，即开始和完成的时间点
        double mom, tim;
        for (int i = 0; i < n; ++i) {
                cin >> mom >> tim;
                q.push(pair<double, double>(mom, tim));
        }

        double sum = 0.0, st = q.front().first, ed = st + q.front().second;
        q.pop();
        while (!q.empty()) {
                if (q.front().first >= ed) { // 不用等，直接过
                        ed = q.front().first + q.front().second;
                }
                else { // q.front().first < ed // 需要等
                        sum += (ed - q.front().first);
                        ed += q.front().second;
                }
                q.pop();
        }
        printf("%.2f", sum / static_cast<double>(n));
        return 0;
}
