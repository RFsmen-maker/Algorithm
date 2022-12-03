/*
* 242. 有效的字母异位词
* 直接自建一个 int record[26]，或者使用 unordered_map
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// 使用哈希表
bool isAnagram1(string s, string t)
{
        if (s.size() != t.size()) return false;
        unordered_map<char, int> record;
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
                ++map[s[i]];
                --map[t[i]];
        }
        for (unordered_map<char, int>::iterator it = record.begin(); it != record.end(); ++it)
        {
                if (it->second != 0) return false;
        }
        return true;
}

bool isAnagram(string s, string t)
{
        int record[26] = {0};
        for (char c : s)
        {
                record[static_cast<int>(c- 'a')]++;
        }
        for (char c : t)
        {
                record[static_cast<int>(c- 'a')]--;
        }
        for (int i = 0; i < 26; i++)
        {
                if (record[i] != 0) return false;
        }
        return true;
}

int main(void)
{
        cout << isAnagram("rat", "car") << endl;

        return 0;
}
