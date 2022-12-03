#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
        int i, j, k;
        char zero[5] = "tret";
        char loNum[12][4] = {
                "jan", "feb", "mar", "apr", "may",
                "jun", "jly", "aug", "sep", "oct",
                "nov", "dec"};
        char hiNum[12][4] = {
                "tam", "hel", "maa", "huh", "tou",
                "kes", "hei", "elo", "syy", "lok",
                "mer", "jou"};

        int N;
        cin >> N;
        char output[N][9] = {""};
        char tempC[5];
        int tempN;
        bool flag = 0;
        for(i = 0; i < N; i++)
        {
                cin >> tempC;
                if(tempC[0] <= '9' && tempC[0] >= '0') {
                        if(tempC[0] == '0') {
                                strcat(output[i], zero);
                                continue;
                        }
                        tempN = atoi(tempC);
                        if(tempN / 13) {
                                strcat(output[i], hiNum[tempN / 13 - 1]);
                                flag = 1;
                        }
                        if(tempN % 13) {
                                if(flag) {
                                        strcat(output[i], " ");
                                }
                                strcat(output[i], loNum[tempN % 13 - 1]);
                        }
                        flag = 0;
                }
                else {
                        tempN = 0;
                        for(j = 0; j < 13; j++)
                        {
                                if(!flag) {
                                        if(!strcmp(tempC, loNum[j])) {
                                                tempN += j + 1;
                                                break;
                                        }
                                }
                                if(!strcmp(tempC, hiNum[j])) {
                                        tempN += (j + 1) * 13;
                                        if(getchar() == '\n') {
                                                break;
                                        }
                                        flag = 1;
                                }
                                if(flag) {
                                        cin >> tempC;
                                        for(k = 0; k < 13; k++) {
                                                if(!strcmp(tempC, loNum[k])) {
                                                        flag = 0;
                                                        tempN += k + 1;
                                                        break;
                                                }
                                        }
                                        break;
                                }
                        }
                        strcpy(output[i], to_string(tempN).c_str());
                }
        }

        for(i = 0; i < N; i++)
                cout << output[i] << endl;

        return 0;
}
