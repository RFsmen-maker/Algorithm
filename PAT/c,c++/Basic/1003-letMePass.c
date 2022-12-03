#include <stdio.h>

int judgement(void)
{
        char ch;
        int a, b, c, after;
        a = b = c = after = 0;
        while((ch = getchar()) != '\n')
        {
                if(after == 0 && ch == 'A')
                        a++;
                else if(after == 0 && ch == 'P')
                        after = 1;
                else if(after == 1 && ch == 'A')
                        b++;
                else if(after == 1 && ch == 'T')
                        after = 2;
                else if(after == 2 && ch == 'A')
                        c++;
                else
                {
                        while(ch != '\n')
                                ch = getchar();
                        return 0;
                }
        }

        if (after == 2 && a >= 0 && b >= 1 && c == a * b)
                return 1;

        return 0;
}

int main(void)
{
        char *judge[2] = {"NO", "YES"};
        int n, count = 0;
        int out[10];
        scanf("%d", &n);
        getchar();
        while(n--)
                out[count++] = judgement();

        for (n = 0; n < count; n++)
        {
                printf("%s", judge[out[n]]);
                if(n < count)
                        putchar('\n');
        }

        return 0;
}
