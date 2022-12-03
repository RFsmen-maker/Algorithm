#include <iostream>

using namespace std;

int main(void)
{
        char input[81];
        char load[256];
        unsigned char c;
        int count = 0;
        cin >> input;

        while((c = input[count++]) != '\0')
        {
                if(c <= 'z' && c >= 'a')
                        c = toupper(c);
                load[c] = 1;
        }
        getchar();
        while((c = getchar()) != '\n')
        {
                if(c <= 'z' && c >= 'a')
                        c = toupper(c);
                load[c] = 0;
        }

        count = 0;
        while((c = input[count++]) != '\0')
        {
                if(c <= 'z' && c >= 'a')
                        c = toupper(c);
                if(load[c]) {
                        putchar(c);
                        load[c] = 0;
                }
        }

        return 0;
}
