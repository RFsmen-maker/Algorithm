/*
 * 07.1077 韩信点兵
 * Description 相传汉高祖刘邦问大将军韩信统御兵士多少，韩信答说，
 * 每3人一列余1人、5人一列余2人、7人一列余4人、13人一列余6人、
 * 17人一列余2人、19人一列余10人、23人一列余1人、29人一列余11人。
 * 刘邦茫然而不知其数。你呢？ 你是一位优秀的程序员，请你帮刘邦解决这一问题。

 * 输入格式
 * 要求由键盘输入A,B,C,D,E,F,G,H,a,b,c,d,e,f,g,h十六个数，
 * 分别代表每A人一列余a、每B人一列余b、每C人一列余c、每D人一列余D、每E人一列余e、
 * 每F人一列余f、每G人一列余g、每H人一列余h，其中A,B,C,D,E,F,G,H为互不相等的质数

 * 输出格式
 * 输出总兵士数，要求输出满足条件的最小的一个，但要满足8种排法的每一种排法至少可排一列。
 * （保证给的数据，有结果且计算的结果不会超过2的63次方）

 * 输入样例
 * 2 3 5 7 11 13 17 19
 * 1 1 1 1 1 1 1 1
 * 输出样例
 * 9699691
*/
#include <iostream>
#include <algorithm>

using namespace std;

// 暂时不会，只能抄下
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) // 扩展欧几里得，辗转相除求最大公约
{
        if (b == 0) {
                x = 1;
                y = 0;
                return a;
        }
        ll t = exgcd(b, a%b, y, x); // 交换除数和余数
        y = y - a / b * x;
        return t;
}

ll china(ll a[], ll b[]) // 中国剩余定理
{
        ll m = 1, ans = 0, mx = -1;
        for (int i = 0; i < 8; ++i)
        {
                m *= a[i];
                mx = max(mx, a[i]); // 记最大除数
        }

        for (int i = 0; i < 8; ++i)
        {
                ll x, y;
                ll w = m / a[i];
                ll t = exgcd(w, a[i], x, y);
                ans = (ans + w * b[i] * (x / t)) % m;
        }
        while (ans < mx) ans += m;
        return ans;
}

int main(void)
{
        ll div[8], rem[8];
        for (int i = 0; i < 8; ++i) cin >> div[i]; // 存除数
        for (int i = 0; i < 8; ++i) cin >> rem[i]; // 存余数
        cout << china(div, rem) << endl;

        return 0;
}

// 超时，应用数论中的中国剩余定理
// 利用一个条件，输入的数字都是质数，所以最小公倍数就是它们乘起来

//int main(void)
//{
//        long amount = 1;
//        int nums[8][2];
//        for (int i = 0; i < 8; ++i)
//        {
//                cin >> nums[i][0];
//                amount *= nums[i][0];
//        }
//        for (int i = 0; i < 8; i++) cin >> nums[i][1];
//
//
//        return 0;
//}
