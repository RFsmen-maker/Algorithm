#include <iostream>

using namespace std;

int main(void)
{
        int countC[26] = {0};
        char c;
        while((c = getchar()) != '\n')
        {
                if((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) {
                        c = tolower(c);
                        countC[(c - 'a')]++;
                }
        }

        int temp = 0;
        for(int i = 1; i < 26; i++)
        {
                if(countC[i] > countC[temp]) {
                        temp = i;
                }
        }

        printf("%c %d", 'a' + temp, countC[temp]);

        return 0;
}
