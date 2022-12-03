#include <stdio.h>

int main(void)
{
        int n, current, stage, sum;
        while (~scanf("%d", &n) && n != 0)
        {
                sum = n * 5;
                current = 0;
                while (n--)
                {
                        scanf("%d", &stage);
                        if (stage >= current)
                                sum += (stage - current) * 6;
                        if (stage < current)
                                sum += (current - stage) * 4;
                        current = stage;
                }
                printf("%d\n", sum);
        }
        return 0;
}
