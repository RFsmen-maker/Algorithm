/*
 * 19084. 万万没想到之聪明的编辑
 * times : 2
 * AAA... -> AA, AABB -> AAB
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;

void flagMethod(vector<string> &str)
{
        for (int i = 0; i < n; ++i) {
                if (str.empty()) { //
                        cout << endl;
                        continue;
                }

                bool cur = false, last = false;
                int len = str[i].size();
                string rep;
                rep.push_back(str[i][0]); // 初始化
                for (int j = 1; j < len; ++j) {
                        if (str[i][j] == str[i][j-1]) {
                                if (cur || last) continue;
                                cur = true;
                        }
                        else last = cur, cur = false;
                        rep.push_back(str[i][j]);
                }
                cout << rep << endl;
        }
}

int main(void)
{
        cin >> n;
        vector<string> str(n);
        for (string &i : str) cin >> i;

        flagMethod(str);

        return 0;
}


