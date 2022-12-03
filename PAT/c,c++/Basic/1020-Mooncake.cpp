/*
Basic-1020 Moomcake
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
        class MOONCAKE{
        public:
                double storage;
                double totalPrice;
                double singlePrice;
        };

        int types, marketRe, allSto = 0;
        cin >> types >> marketRe;
        MOONCAKE *mooncake = new MOONCAKE[types];
        double *tempSo = new double[types];
        int *seq = new int[types];
        for(int i = 0; i < types; i++) cin >> mooncake[i].storage;
        for(int i = 0; i < types; i++)
        {
                cin >> mooncake[i].totalPrice;
                tempSo[i]  = mooncake[i].singlePrice = mooncake[i].totalPrice / mooncake[i].storage;
                seq[i] = i;
                allSto += mooncake[i].storage;
        }

        double income = 0;
        if(allSto > marketRe) {
                sort(seq, seq+types,
                     [&tempSo](int a, int b) {return tempSo[a] > tempSo[b]; });
                int tempIn = 0;
                while(marketRe)
                {
                        if(marketRe >= mooncake[seq[tempIn]].storage) {
                                marketRe -= mooncake[seq[tempIn]].storage;
                                income += mooncake[seq[tempIn]].totalPrice;
                                mooncake[seq[tempIn]].storage = 0;
                        }
                        else {
                                income += marketRe * mooncake[seq[tempIn]].singlePrice;
                                mooncake[seq[tempIn]].storage -= marketRe;
                                marketRe = 0;
                        }
                        tempIn++;
                }
        }
        else {
                for(int i = 0; i < types; i++)
                {
                        income += mooncake[i].totalPrice;
                }
        }
        cout.setf(ios_base::floatfield, ios_base::fixed);
        cout.precision(2);
        cout << income;

        delete tempSo;
        delete seq;
        delete mooncake;

        return 0;
}
