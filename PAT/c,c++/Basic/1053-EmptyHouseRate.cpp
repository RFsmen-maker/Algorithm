/*
Basic-1053 Empty House Rate
*/
#include <iostream>

using namespace std;

int main(void)
{
        int N, D;
        double e;
        cin >> N >> e >> D;
        int possible = 0, definite = 0;
        for(int i = 0; i < N; i++)
        {
                int day;
                cin >> day;
                int posCo = 0;
                double temp;
                for(int j = 0; j < day; j++)
                {
                        cin >> temp;
                        if(temp < e) {
                                posCo++;
                        }
                }
                if(static_cast<double>(posCo) / static_cast<double>(day) > 0.5) {
                        possible++;
                        if(day > D) {
                                definite++;
                                possible--;
                        }
                }
        }
        cout.setf(ios_base::floatfield, ios_base::fixed);
        cout.precision(1);
        double posRa = 100.0 * static_cast<double>(possible) / static_cast<double>(N);
        double defRa = 100.0 * static_cast<double>(definite) / static_cast<double>(N);
        if(posRa <= 0.00001) {
                cout << "0.0% ";
        }
        else {
                cout << posRa << "% ";
        }
        if(defRa <= 0.00001) {
                cout << "0.0%";
        }
        else {
                cout << defRa << "%";
        }

        return 0;
}
