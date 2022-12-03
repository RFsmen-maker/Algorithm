#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
        char face[3][10][5] = {'\0'};
        char tempChar;
        int count1, count2;
        for(int i = 0; i < 3; i++)
        {
                count1 = 0;
                while((tempChar = getchar()) != '\n')
                {
                        count2 = 0;
                        if(tempChar != '[')
                                continue;
                        while((tempChar = getchar()) != ']')
                        {
                                face[i][count1][count2++] = tempChar;
                        }
                        face[i][count1][count2] = '\0';
                        count1++;
                }
        }
        count1 = 0;
        cin >> count1;
        char tempArray[100];
        char result[count1][100];
        bool flag = 1;
        for(int i = 0; i < count1; i++)
        {
                for(int j = 0; j < 5; j++)
                {
                        cin >> count2;
                        count2--;
                        if(!strcmp(face[2-abs(2-j)][count2], "\0") || count2 < 0 || count2 > 9) {
                                strcpy(result[i], "Are you kidding me? @\\/@");
                                flag = 0;
                        }
                        if(j == 1) {
                                strcat(tempArray, "(");
                        }
                        strcat(tempArray, face[2-abs(2-j)][count2]);
                        if(j == 3) {
                                strcat(tempArray, ")");
                        }
                }
                if(flag) {
                        strcpy(result[i], tempArray);
                }
                else {
                        flag = 1;
                }
                strcpy(tempArray, "\0");
        }

        for(int i = 0; i < count1-1; i++)
        {
                cout << result[i] << endl;
        }
        cout << result[count1-1];


        return 0;
}
