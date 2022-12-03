#include <iostream>

using namespace std;

int main(void)
{
        int A, B, Da, Db, Pa, Pb;
        Pa = Pb = 0;
        cin >> A >> Da >> B >> Db;

        int count;
        while(A != 0)
        {
                if(A % 10 == Da) {
                        if(count) {
                                Pa *= 10;
                                Pa += Da;
                        }
                        else {
                                Pa += Da;
                                count++;
                        }
                }
                A /= 10;
        }

        count = 0;
        while(B != 0)
        {
                if(B % 10 == Db) {
                        if(count) {
                                Pb *= 10;
                                Pb += Db;
                        }
                        else {
                                Pb += Db;
                                count++;
                        }
                }
                B /= 10;
        }

        cout << Pa + Pb;

        return 0;
}
