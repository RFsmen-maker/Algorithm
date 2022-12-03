/*
Basic-1001 (3n+1) guess
*/

#include <iostream>

using namespace std;

int main(void)
{
        unsigned int n, amoCut;

        cin >> n;
        while(n != 1)
        {
                if(n % 2) {
                        n = (3 * n + 1) / 2;
                }
                else {
                        n /= 2;
                }
                ++amoCut;
        }
        cout << amoCut;

        return 0;
}
