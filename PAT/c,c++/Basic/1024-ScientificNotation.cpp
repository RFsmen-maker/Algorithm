/*
Basic-1024 Scientific Notation
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        char dir = getchar();

        char tempCh;
        vector<char> arr;
        bool zeroFlag = 1;
        while((tempCh = getchar()) != 'E')
        {
                if(tempCh <= '9' && tempCh >= '0') {
                        arr.push_back(tempCh);
                        if(tempCh != '0') zeroFlag = 0;
                }
        }
        if(zeroFlag) {
                cout << 0;
                return 0;
        }

        char coefDir = getchar();
        int coef;
        scanf("%d", &coef);

        if(dir == '-') cout << '-';
        if(coef == 0) {
                cout << arr[0] << '.';
                for(auto i = arr.begin()+1; i != arr.end(); i++)
                        cout << *i;
        }
        else {
                // 有两种情况需要考虑：
                // 1. 输入的位长大于乘上指数的数的位长；
                // 2. ... 小于 ...，后面需要添0；
                if(coefDir == '+') {
                        // 判断需不需要小数点
                        if(arr.size() - 1 == coef) {
                                for(auto i = arr.begin(); i != arr.end(); i++)
                                        cout << *i;
                        }
                        else if(arr.size() - 1 > coef) {
                                int pointPos = coef+1;
                                for(auto i = arr.begin(); i != arr.end(); i++)
                                {
                                        cout << *i;
                                        if(!(--pointPos)) cout << '.';
                                }
                        }
                        else if(arr.size() - 1 < coef) {
                                int rearZero = coef - (arr.size() - 1);
                                for(auto i = arr.begin(); i != arr.end(); i++)
                                        cout << *i;
                                while(rearZero--) cout << '0';
                        }
                }
                // 只需要考虑后面添 0 的情况
                else if(coefDir == '-') {
                        int foreZero = coef - 1;
                        cout << "0.";
                        while(foreZero--) cout << '0';
                        for(auto i = arr.begin(); i != arr.end(); i++)
                                cout << *i;
                }
        }

        return 0;
}
