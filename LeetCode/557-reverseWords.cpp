#include <iostream>
#include <String>

using namespace std;

void reverseString(string &s, int left, int right)
{
        int sym;
        int half = ((right -  left) % 2) ? (right + left) / 2 + 1 : (right + left) / 2;
        char tempCh;
        for(int i = left; i < half; ++i)
        {
                sym = right + left - i;
                // cout << "sym : " << sym << endl;
                tempCh = s[sym];
                s[sym] = s[i];
                s[i] = tempCh;
        }
}
// 要想清楚边界条件，优先考虑极限情况
string reverseWords(string s)
{
        int len = s.size();
        int effWord = 0, blank;
        for(int i = 0; i < len; ++i)
        {
                if(s[i] == ' ' || i+1 == len) {
                        blank = (i+1 == len) ? i+1 : i;
                        // cout << "eff: " << effWord << " blank: " << blank << endl;
                        reverseString(s, effWord, blank-1);
                        effWord = blank+1;
                }
        }
        return s;
}

int main(void)
{
        string str = "Let's take LeetCode contest";
        string temp;
        temp = reverseWords(str);
        cout << temp << endl;

        return 0;
}
