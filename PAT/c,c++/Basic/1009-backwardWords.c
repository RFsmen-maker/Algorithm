#include <stdio.h>

#define STLEN 82

int main(void)
{
        int count = 1, cur = 0;
        int sign[STLEN] = {0};
        char sentence[STLEN];

        fgets(sentence, STLEN, stdin);

        while(sentence[cur] != '\n')
        {
                if(sentence[cur] == ' ')
                        sign[count++] = cur+1;
                cur++;
        }
        count--;
        while(count >= 0)
        {
                cur = sign[count];
                while(sentence[cur] != ' ' && sentence[cur] != '\n')
                {
                        putchar(sentence[cur++]);
                }
                if(count != 0)
                        putchar(' ');
                count--;
        }

        return 0;
}
