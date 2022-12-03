#include <iostream>

using namespace std;

int main(void)
{
        bool broke[128] = {0};
        char str[100000];
        char tempCh;
        while(cin.get(tempCh) && tempCh != '\n')
        {
                broke[tempCh] = 1;
                if(isupper(tempCh)) broke[tolower(tempCh)] = 1;
                else if(islower(tempCh)) broke[toupper(tempCh)] = 1;
        }
        unsigned int i = 0;
        while(cin.get(str[i++]) && str[i-1] != '\n');

        bool check = broke['+'];
        if(check) {
                for(int j = 0; j < i; j++)
                {
                        if(!broke[str[j]] && !isupper(str[j]))
                                cout << str[j];
                }
        }
        else {
                for(int j = 0; j < i; j++)
                {
                        if(!broke[str[j]])
                                cout << str[j];
                }
        }

        return 0;
}

