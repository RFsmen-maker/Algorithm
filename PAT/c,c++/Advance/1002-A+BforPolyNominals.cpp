#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        bool totalPoly[1001] = {0};
        class poly{
        public:
                int K;
                vector<int> power;
                vector<float> coefficient;

                void read(void) {
                        cin >> this->K;
                        for(int i = 0; i < this->K; i++)
                        {
                                int tempPow;
                                float tempCoe;
                                cin >> tempPow >> tempCoe;
                                this->power.push_back(tempPow);
                                this->coefficient.push_back(tempCoe);
                        }
                }
        }p1, p2;

        p1.read();
        p2.read();

        for(int i = 0; i < p1.K; i++)
        {
                totalPoly[p1.power[i]] = 1;
        }

        for(int i = 0; i < p2.K; i++)
        {
                totalPoly[p2.power[i]] = 1;
        }

        int temp, temp1, temp2;
        temp = temp1 = temp2 = 0;
        vector<int> rePower;
        vector<float> reCoefficient;
        int reK = 0;
        for(int i = 1000; i >= 0; i--)
        {
                if(totalPoly[i]) {
                        rePower.push_back(i);
                        reCoefficient.push_back(0.0);
                        if(p1.power.size() != 0 && i == p1.power[temp1]) {
                                reCoefficient[temp] += p1.coefficient[temp1];
                                temp1++;
                        }
                        if(p2.power.size() != 0 && i == p2.power[temp2]) {
                                reCoefficient[temp] += p2.coefficient[temp2];
                                temp2++;
                        }
                        if(reCoefficient[temp] != 0.0) {
                                temp++;
                                reK++;
                        }
                        else {
                                rePower.pop_back();
                                reCoefficient.pop_back();
                        }
                }
        }

        if(reK == 0) {
                cout << 0;
                return 0;
        }

        cout << reK << ' ';
        for(int i = 0; i < reK-1; i++)
        {
                cout << rePower[i] << ' ';
                int temp = (reCoefficient[i] * 10 + 0.5);
                reCoefficient[i] = (float)temp / 10;
                cout << reCoefficient[i] << ' ';
        }
        cout << rePower[reK - 1] << ' ';
        temp = (reCoefficient[reK-1] * 10 + 0.5);
        reCoefficient[reK-1] = (float)temp / 10;
        cout << reCoefficient[reK - 1];

        return 0;
}
