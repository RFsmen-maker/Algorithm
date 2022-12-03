/*
* 字符串排序
* 两个字符串 s1, s2，检查 s1 的排列之一是否 s2 的子串
*/
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

void showRecord(const int *src)
{
        for (int i = 0; i < 26; ++i) {
                if (src[i] >= 1) {
                        cout << static_cast<char>('a' + i) << " : " << src[i] << endl;
                }
        }
}
bool compare(int *src, int *dest)
{
        for (int i = 0; i < 26; ++i)
                if (src[i] != dest[i]) return false;
        return true;
}
bool checkInclusion(string s1, string s2)
{
        if(s1.size() > s2.size()) return false;

        int len = s2.size();
        int left, right;
        left = 0;
        right = s1.size();
        int src[26] = {0};
        int dest[26] = {0};

        for (int i = 0; i < right; ++i) {
                src[static_cast<int>(s1[i] - 'a')]++;
                dest[static_cast<int>(s2[i] - 'a')]++;
        }

        while (right <= len)
        {
//                cout << "dest : " << endl;
//                showRecord(dest);
                if(compare(src, dest)) return true;
                else if(right >= len) return false;
                if(dest[static_cast<int>(s2[left] - 'a')])
                        dest[static_cast<int>(s2[left] - 'a')]--;
                dest[static_cast<int>(s2[right] - 'a')]++;
//                cout << "left : " << left << endl;
//                cout << "right : " << right << endl;
                left++;
                right++;
        }

        return false;
}

int main(void)
{
        if(checkInclusion("ab", "eidboaoo")) cout << "True" << endl;
        else cout << "False" << endl;

        return 0;
}
