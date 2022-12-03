/*
Basic-1028 Population Census
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        int N, tempDate, tempIn, effCount = 0;
        const int LIMITAGE = 18140906;
        const int TODAY = 20140906;
        int oldest = 20140906, youngest = 18140906;
        string oldName, youName, tempName;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
                tempDate = 0;
                cin >> tempName;
                for(int j = 10000; j >= 1; j /= 100)
                {
                        cin >> tempIn;
                        cin.get();
                        tempDate += tempIn * j;
                }
                if(tempDate <= TODAY && tempDate >= LIMITAGE)
                {
                        ++effCount;
                        if(tempDate > youngest) {
                                youName = tempName;
                                youngest = tempDate;
                        }
                        if(tempDate < oldest) {
                                oldName = tempName;
                                oldest = tempDate;
                        }
                }
        }

        if(effCount) {
                cout << effCount <<' '<< oldName <<' '<< youName;
        }
        else {
                cout << 0;
        }

        return 0;
}
