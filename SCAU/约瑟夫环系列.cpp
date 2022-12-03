/*
 * 1139. 约瑟夫环问题
 * 指定了起始的位置，直接偏移过去即可
*/
/*
 * ex 1.6 圈中游戏
 * 指定人数，每次报数到 3 退圈
 * 输出留下人的编号
 * 递推公式：pos = ((0 + m) % n + m) % (n + 1) ...
*/
#include <iostream>

using namespace std;

// 照抄
// try2：显然，需要使用数学推导计算
// 终极递推公式：s = (s + m) % i; m 为距离
int main1(void)
{
        int n;
        cin >> n;
        int s = 0;
        for (int i = 2; i <= n; ++i)
        {
                s = (s + 3) % i;
                cout << s << endl;
        }
        cout << "Last : " << s + 1 << endl;

        return 0;
}

// try1：首先尝试使用链表暴力，显然，超时
//int main(void)
//{
//        int n;
//        cin >> n;
//        list<int> arr;
//        for (int i = 1; i <= n; ++i)
//                arr.push_back(i);
//
//        auto it = arr.begin();
//        while (arr.size() != 1)
//        {
//                int count = 0;
//                auto del = it;
//                while (count < 2)
//                {
//                        del++;
//                        if (del == arr.end()) del = arr.begin();
//                        count++;
//                }
//                it = del;
//                it++;
//                if (it == arr.end()) it = arr.begin();
//                arr.erase(del);
//        }
//        cout << *(arr.begin());
//
//        return 0;
//}

int main(void)
{
        int n, start, out;
        cin >> n >> start >> out;

        int pos = 0;
        for (int i = 2; i <= n; ++i) {
                pos = (pos + out) % i;
        }
        cout << (pos + start - 1) % n + 1 << endl;

        return 0;
}
