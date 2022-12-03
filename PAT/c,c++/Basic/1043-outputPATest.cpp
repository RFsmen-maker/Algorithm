#include <iostream>

using namespace std;

int main(void)
{
        int countC[6] = {0};
        char c;
        while((c = getchar()) != '\n')
        {
                switch(c)
                {
                case 'P': countC[0]++; break;
                case 'A': countC[1]++; break;
                case 'T': countC[2]++; break;
                case 'e': countC[3]++; break;
                case 's': countC[4]++; break;
                case 't': countC[5]++; break;
                }
        }

        int temp = 0;
        for(int i = 1; i < 6; i++)
        {
                if(countC[i] < countC[temp]) {
                        temp = i;
                }
        }

        temp = countC[temp];
        int count = 0;
        for(int i = 0; i < 6; i++)
        {
                countC[i] -= temp;
                count += countC[i];
        }

        while(temp--)
                cout << "PATest";

        char tempA[] = "PATest";
        for(int i = 0; count; i++)
        {
                if(i == 6)
                        i = 0;
                while(countC[i] > 0)
                {
                        cout << tempA[i];
                        countC[i]--;
                        count--;
                        break;
                }
        }


        return 0;
}
