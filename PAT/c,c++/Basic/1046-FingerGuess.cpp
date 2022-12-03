/*
* Basic-1046 Finger Guessing
*/
#include <iostream>

using namespace std;

int main(void)
{
        int N;
        cin >> N;

        int a, b;
        a = b = 0;
        while(N--)
        {
                int aS, aG, bS, bG;
                cin >> aS >> aG >> bS >> bG;
                if(aG == bG) continue;
                else if(aG == aS + bS) b++;
                else if(bG == aS + bS) a++;
        }
        cout << a << ' ' << b;

        return 0;
}
