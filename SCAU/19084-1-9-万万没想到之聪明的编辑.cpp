/*
 * 19084. 万万没想到之聪明的编辑
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
                string str, rep;
                cin >> str;

                if (str.empty()) {
                        cout << endl;
                        continue;
                }

                // 初始化
                int len = str.size();
                bool lastF, curF;
                lastF = curF = false;
                rep.push_back(str[0]);
                char last = str[0];

                // 遍历整个 str 进行修复
                for (int j = 1; j < len; ++j) {
                        if (str[j] == last) { // 当遇见一样的字符时，有两种情况
                                if (curF || lastF) { // 前面有 AA，又遇见了 A，或者是 AAB B，直接跳过
                                        continue;
                                }
                                else { // 前面无 AA，进行记录
                                        curF = true;
                                }
                        }
                        else { // 遇见不一样的字符，让 lastF 记录前面是否有 AA，curF 恢复状态
                                lastF = curF;
                                curF = false;
                        }
                        last = str[j];
                        rep.push_back(str[j]);
                }
                cout << rep << endl;
        }

        return 0;
}

