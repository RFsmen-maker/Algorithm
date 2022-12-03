#include <stdio.h>
#include <string.h>

int main(void)
{
        char color[1000][16];
        int n, i, j, count, max;
        while(~scanf("%d", &n) != EOF && n)
        {
                max = 0;
                for (i = 0; i < n; i++)
                {
                        scanf("%s", color[i]);
                        count = 0;
                        if (i > 0)
                        {
                                for (j = i-1; j >= 0; j--)
                                {
                                        if (strcmp(color[i], color[j]) == 0)
                                                count++;
                                }
                        }
                        max = max > count ? max : i;
                }
                printf("%s\n", color[max]);
        }
        return 0;
}
