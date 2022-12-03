/*
Basic-1021 Unit Statistic
*/
#include <iostream>

using namespace std;

int main(void)
{
        int statistic[10] = {0};
        char tempC;
        while(cin.get(tempC) && tempC != '\n')
        {
                statistic[tempC - '0']++;
        }

        for(int i = 0; i < 9; i++)
        {
                if(statistic[i]) {
                        cout << i <<':'<< statistic[i] << endl;
                }
        }
        if(statistic[9]) {
                cout << "9:" << statistic[9] << endl;
        }

        return 0;
}
