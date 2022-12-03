#include <iostream>

#define MAX 10
using namespace std;

int main(void)
{
        char array[MAX];
        int a, b, sum, temp, m, count;

        temp = m = count = 0;
        cin >> a >> b;

        sum = a + b;
        if(sum == 0) {
                cout << 0;
                return 0;
        }
        if(sum < 0)
                m = 1;

        for(int i = 0; sum != 0; i++, count++)
        {
                temp++;
                array[i] = abs(sum % 10) + '0';
                sum /= 10;
                if(temp == 3 && sum != 0) {
                        array[++i] = ',';
                        temp = 0;
                        count++;
                }
        }
        array[count] = '\0';

        if(m)
                cout << '-';
        for(int i = count-1; i >= 0; i--)
        {
                cout << array[i];
        }

        return 0;
}
