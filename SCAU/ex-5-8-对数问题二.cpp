/*
 * 18728. 数对问题二
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// A - B = C
// A - C = B(aim)

//// 参考博客修改
//int N, C;
//map<int, int> m;
//int arr[20005];
//int main(void)
//{
//        cin >> N >> C;
//        for (int i = 1; i <= N; ++i) {
//                cin >> arr[i];
//                m[arr[i]]++; // 个数统计
//                arr[i] -= C; // 提前减去
//        }
//        long long count = 0;
//        for (int i = 1; i <= N; ++i) {
//                count += m[arr[i]];
//        }
//        cout << count << endl;
//        return 0;
//}

int main(void)
{
        int N, C;
        cin >> N >> C;

        vector<int> arr(N);
        map<int, int> T;
        for (int i = 0; i < N; ++i) {
                cin >> arr[i];
                auto it = T.find(arr[i]);
                if (it == T.end()) T.insert(pair<int, int>(arr[i], 1));
                else (*it).second++;
        }

        // for (auto it : T) cout << it.first << ' ' << it.second << endl;

        long long count = 0;
        for (int i : arr) {
                auto p = T.find(i + C);
                if (p != T.end()) count += (*p).second;
        }
        cout << count << endl;

        return 0;
}

