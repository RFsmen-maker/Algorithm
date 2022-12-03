#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
        int n, base, tempBlock, tempC;
        unsigned char c;
        cin >> n >> c;

        base = sqrt((n + 1) / 2);

        for(int i = 0; i < 2 * base - 1; i++)
        {
                tempBlock =(base - 1) - abs((float)(i - (base - 1)));
                tempC = 2 * abs((float)(base - i - 1)) + 1;
                while(tempBlock--)
                        cout << ' ';
                while(tempC--)
                        cout << c;
                if(i != 2 * base - 1)
                        cout << '\n';
        }

        cout << n - 2 * base * base + 1;

        return 0;
}
