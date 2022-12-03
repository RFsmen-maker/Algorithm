#include <stdio.h>
#include <string.h>

#define MAX 1002

void chAdd(char [], char [], int, int);

void chAdd(char longer[MAX], char shorter[MAX], \
           int longer_len, int shorter_len)
{
        int sum, count = shorter_len;
        shorter_len--;
        longer_len--;
        while (count--)
        {
                sum = *(longer+(longer_len)) - '0' \
                + *(shorter+(shorter_len--)) - '0';
                if (sum >= 10)
                {
                        *(longer+(longer_len)) = (sum%10) + '0';
                        *(longer+(longer_len)-1) += 1;
                }
                else
                {
                        *(longer+(longer_len)) = sum + '0';
                }
                longer_len--;
        }
}

int main(void)
{
        int i, n;

        scanf("%d", &n);

                char front[100][MAX];
                char rear[100][MAX];
                char result[100][MAX];

                for (i = 0; i < n; i++)
                {
                        scanf("%s%s", front[i], rear[i]);

                        if (strlen(front[i]) >= strlen(rear[i]))
                        {
                                if (strlen(front[i]) == strlen(rear[i]) \
                                    && (front[i][0] - '0') + (rear[i][0] - '0') >= 10)
                                {
                                        result[i][0] = '0';
                                        result[i][1] = '\0';
                                        strcat(result[i], front[i]);
                                }
                                else
                                        strcpy(result[i], front[i]);

                                chAdd(result[i], rear[i], \
                                      strlen(result[i]), strlen(rear[i]));
                        }
                        else
                        {
                                strcpy(result[i], rear[i]);

                                chAdd(result[i], front[i], \
                                      strlen(result[i]), strlen(front[i]));
                        }
                }
                for (i = 0; i < n; i++)
                {
                        printf("Case %d:\n", i+1);
                        printf("%s + %s = %s\n", front[i], rear[i], result[i]);
                        if (i < n-1)
                                printf("\n");
                }

        return 0;
}
