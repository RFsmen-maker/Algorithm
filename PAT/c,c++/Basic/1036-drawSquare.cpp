#include <iostream>

using namespace std;

int main(void)
{
        int N, i, j;
        unsigned char c;

        cin >> N;
        cin >> c;
        i = N;
        j = N * 10 / 2;
        if(j % 10 >= 5)
                j += 10;
        j /= 10;

        for(int row = 0; row < j; row++)
        {
                if(row == 0 || row == j - 1) {
                        for(int column = 0; column < i; column++)
                        {
                                cout << c;
                        }
                }
                else { //row != 0 && row != j-1
                        for(int column = 0; column < i; column++)
                        {
                                if(column != 0 && column != i-1)
                                        cout << ' ';
                                else
                                        cout << c;
                        }
                }
                if(row != j)
                        putchar('\n');
        }

        return 0;
}
