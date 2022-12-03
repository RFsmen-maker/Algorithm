/*
 * 18938-2.7 汉诺塔问题
 * 递归解决，迭代需要使用栈容器完成
*/
#include <iostream>

using namespace std;

void hano(int amount, char a, char b, char c) // 借助 b 杆使得 a 杆上的盘移动到 c 杆
{
        if (amount == 1) cout << a << "->" << amount << "->" << c << endl;
        else {
                hano(amount-1, a, c, b);
                cout << a << "->" << amount << "->" << c << endl;
                hano(amount-1, b, a, c);
        }
}

// 注意是 a 杆到 b 杆
int main(void)
{
        int n;
        char a, b, c;
        cin >> n >> a >> b >> c;
        hano(n, a, c, b); // 原杆，辅助杆，目标杆

        return 0;
}

