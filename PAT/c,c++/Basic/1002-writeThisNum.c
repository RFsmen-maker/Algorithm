#include <stdio.h>

int main(void)
{
        char * z[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
        int out[5] = {0, 0, 0, 0, 0};
        int c;
        int count = 0;
        while((c = getchar()) != '\n')
                count += c - '0';

        c = 0;
        while(count != 0 || c > 5)
        {
                out[c] += count % 10;
                c++;
                count /= 10;
        }
        c--;
        while(c >= 0)
        {
                printf("%s", z[out[c--]]);
                if(c >= 0)
                        putchar(' ');
        }

        return 0;
}
