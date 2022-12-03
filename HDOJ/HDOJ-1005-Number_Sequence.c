#include <stdio.h>

#define MAX 10000

int main(void)
{
        int a, b, i, count = 0;
        long int n;
        int temp[MAX], result[MAX];
        while(~scanf("%d%d%ld", &a, &b, &n) != EOF)
        {
                if(!a&&!b&&!n)
                        break;
                temp[0] = 1;
                temp[1] = 1;
                temp[2] = 1;
                for (i = 3; i < 48; i++)
                        temp[i] = ((a * temp[i-1] + b * temp[i-2]) % 7);
                result[count++] = temp[n%48];
        }

        for (i = 0; i < count; i++)
        {
                printf("%d\n", result[i]);
        }

        return 0;
}
