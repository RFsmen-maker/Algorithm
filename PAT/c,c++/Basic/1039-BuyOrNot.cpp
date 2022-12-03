/*
* Basic-1039 Buy Or Not
* OOP Mode
*/
#include <iostream>

using namespace std;

int main(void)
{
        const int MAX = 62;
        const int NUM = 0;
        const int LOWER = 10;
        const int UPPER = 36;
        class Pearl{
        public:
                bool enough;
                int sum;
                int arr[MAX];

                Pearl() {
                        this->enough = 1;
                        this->sum = 0;
                        for(int i = 0; i < MAX; i++) this->arr[i] = 0;
                }

                inline void readin(void) {
                        char tempCh;
                        while((tempCh = getchar()) != '\n')
                        {
                                this->sum++;
                                if(tempCh <= '9' && tempCh >= '0')
                                        this->arr[NUM+(tempCh - '0')]++;
                                else if(tempCh <= 'z' && tempCh >= 'a')
                                        this->arr[LOWER+(tempCh - 'a')]++;
                                else
                                        this->arr[UPPER+(tempCh - 'A')]++;
                        }
                }

                inline int operator-(Pearl &tempP) {
                        int temp = 0;
                        for(int i = 0; i < MAX; i++)
                        {
                                int tempIn = this->arr[i] - tempP.arr[i];
                                if(tempIn < 0 && this->enough) {
                                        this->enough = 0;
                                        temp = -tempIn;
                                        continue;
                                }
                                if(this->enough) {
                                        temp += tempIn;
                                }
                                else {
                                        if(tempIn < 0) temp -= tempIn;
                                }
                        }
                        return temp;
                }
        };

        Pearl ava, need;
        ava.readin();
        need.readin();

        int sub = ava - need;
        if(ava.enough) cout << "Yes ";
        else cout << "No ";
        cout << sub;

        return 0;
}
