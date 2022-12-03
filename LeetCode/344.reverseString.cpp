#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s)
{
        int len = s.size()-1;
        char tempCh;
        for(int i = 0; i < len/2+1; ++i)
        {
                tempCh = s[i];
                s[i] = s[len - i];
                s[len-i] = tempCh;
        }
}

int main(void)
{
        vector<char> str = {'h', 'e', 'l', 'l', 'o'};
        reverseString(str);
        for(auto it = str.begin(); it != str.end(); ++it)
                cout << *it;

        return 0;
}
