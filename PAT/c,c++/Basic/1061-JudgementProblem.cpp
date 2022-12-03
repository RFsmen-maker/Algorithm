/*
* Basic-1061 Judgement Problem
*/
#include <iostream>

using namespace std;

int main(void)
{
        int stuAmo, proAmo;
        cin >> stuAmo >> proAmo;

        int full[proAmo]; for(int i = 0; i < proAmo; i++) cin >> full[i];
        bool judge[proAmo]; for(int i = 0; i < proAmo; i++) cin >> judge[i];

        int re[stuAmo];
        for(int i = 0; i < stuAmo; i++)
        {
                re[i] = 0;
                for(int j = 0; j < proAmo; j++)
                {
                        bool tempJud;
                        cin >> tempJud;
                        if(tempJud == judge[j]) re[i] += full[j];
                }
        }

        for(int i = 0; i < stuAmo-1; i++) cout << re[i] << endl;
        cout << re[stuAmo-1];

        return 0;
}
