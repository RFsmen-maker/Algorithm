#include <stdio.h>

int main(void)
{
        char *week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
        char str[4][61];
        int result[3];
        int i, count;

        for(i = 0; i < 4; i++)
                scanf("%s", str[i]);
        i++;
        count = i = 0;
        while(str[0][i] != '\0' && str[1][i] != '\0')
        {
                if(str[0][i] == str[1][i])
                {
                        if(count == 0 && str[0][i] <= 'G' && str[0][i] >= 'A')
                        {
                                result[0] = str[0][i];
                                result[0] -= 'A';
                                count++;
                                i++;
                                printf("%s", week[result[0]]);
                                continue;
                        }
                        if(count == 1)
                        {
                                if(str[0][i] <= '9' && str[0][i] >= '0')
                                {
                                        result[1] = str[0][i] - '0';
                                        printf(" %02d:", result[1]);
                                        break;
                                }
                                if(str[0][i] <= 'N' && str[0][i] >= 'A')
                                {
                                        result[1] = str[0][i] - 'A' + 10;
                                        printf(" %02d:", result[1]);
                                        break;
                                }
                        }
                }
                i++;
        }
        for(i = 0; (str[2][i] != '\0' && str[3][i] != '\0'); i++)
        {
                if(str[2][i] == str[3][i] && str[2][i] <= 'z' && str[2][i] >= 'A')
                {
                        printf("%02d", i);
                        break;
                }
        }

        return 0;
}
