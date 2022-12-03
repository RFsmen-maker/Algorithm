/*
* 长数对比
*/
#include <iostream>
#include <string>

using namespace std;

int longIntCmp(string s1, string s2);

int main(void)
{
        string s1, s2;
        cin >> s1 >> s2;
        int result = longIntCmp(s1, s2);
        if(result == 1) cout << "Bigger" << endl;
        else if(result == -1) cout << "Smaller" << endl;
        else cout << "Equal" << endl;

        return 0;
}

int longIntCmp(string s1, string s2)
{
        if(s1.size() > s2.size()) return 1;
        else if(s1.size() < s2.size()) return -1;
        else {
                int len = s1.size();
                for(int i = 0; i < len; i++)
                {
                        if(s1[i] > s2[i]) return 1;
                        else if(s1[i] < s2[i]) return -1;
                }
                return 0;
        }
}
