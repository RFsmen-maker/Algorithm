/*
 * P1046 陶陶摘苹果
*/
#include <iostream>

using namespace std;

int main(void)
{
        int hig[10];
        for (int i = 0; i < 10; ++i) cin >> hig[i];
        int caH;
        cin >> caH;
        caH += 30;
        int count = 0;
        for (int i = 0; i < 10; ++i)
                if (caH >= hig[i]) count++;
        cout << count;

        return 0;
}
