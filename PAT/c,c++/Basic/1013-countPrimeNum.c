#include <stdio.h>
#include <math.h>

#define MAX 10000

int main(void)
{
        int m, n, count, inside, i, j, lineCount;
        scanf("%d%d", &m, &n);

        count = lineCount = 0;
        i = 1;
        while(i++)
        {
                inside = 0;
                for(j = 1; j <= sqrt(i); j++)
                {
                        if(!(i % j))
                                inside++;
                }
                if(inside == 1)
                {
                        count++;
                        if(m > count)
                                continue;
                        else
                        {
                                printf("%d", i);
                                lineCount++;
                        }
                        if(lineCount == 10)
                        {
                                putchar('\n');
                                lineCount = 0;
                        }
                        else
                                if(count != n)
                                        putchar(' ');
                }
                if(count == n)
                        break;
        }

        return 0;
}
