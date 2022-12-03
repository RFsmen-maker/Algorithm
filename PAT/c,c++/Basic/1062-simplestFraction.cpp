/*
* Basic-1062 最简分数
* 测试点2、3不过
* 测试点2：之间指的是闭区间
* 除了2、4都不过
*/
#include <iostream>

using namespace std;

typedef struct FRAC{
        int N, M;
        double deci;
}Frac;

inline void getIn(struct FRAC & frac)
{
        cin >> frac.N;
        cin.get();
        cin >> frac.M;
        frac.deci = static_cast<double>(frac.N)
                / static_cast<double>(frac.M);
}

inline int maxComFac(int a, int b)
{
        return b == 0 ? a : maxComFac(b, a%b);
}

int main(void)
{
        Frac frac1, frac2;
        getIn(frac1);
        getIn(frac2);
        int K;
        cin >> K;

        double maxDo, minDo;
        if(frac1.deci > frac2.deci) {
                maxDo = frac1.deci * K;
                minDo = frac2.deci * K;
        }
        else {
                minDo = frac1.deci * K;
                maxDo = frac2.deci * K;
        }

        int tempCo = 0;
        for(int i = minDo; i < maxDo; ++i)
        {
                if(1 == maxComFac(i, K) && i != static_cast<int>(minDo) && i != static_cast<int>(maxDo)) {
                        if(tempCo != 0) cout << ' ';
                        cout << i << '/' << K;
                        tempCo++;
                }
        }

        return 0;
}
