/*
 * 18939. 最长单词
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        // 底层逻辑，一个字符一个字符读入，注意要的是单词
        char ch;
        int count = 0;
        int max = 0;
        string res, cur;
        while ((ch = getchar()) != '.')
        {
                if (ch == ' ' || ch == '.') {
//                        cout << "cur : " << cur << endl;
//                        cout << "res : " << res << endl;
                        if (count > max) {
                                res.clear();
                                res = cur;
                                max = count;
                        }
                        cur.clear();
                        count = 0;
                }
                else {
                        cur.push_back(ch);
                        count++;
                }
                if (ch == '.') break;
        }
        cout << res << endl;

        return 0;
}

