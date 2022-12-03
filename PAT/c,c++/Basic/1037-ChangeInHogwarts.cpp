/*
* Basic-1037 Change In Hogwarts
*/
#include <iostream>

using namespace std;

int main(void)
{
        class MagicMoney {
        public:
                long long Galleon;
                int Sickle;
                int Knut;

                inline void readin(void) {
                        cin >> this->Galleon;
                        cin.get();
                        cin >> this->Sickle;
                        cin.get();
                        cin >> this->Knut;
                }
        }P, A, change;

        P.readin();
        A.readin();

        long long sum = static_cast<long long>(17 * 29 * (A.Galleon - P.Galleon) +
                                        29 * (A.Sickle - P.Sickle) +
                                         (A.Knut - P.Knut));

        if(sum < 0) {
                sum = -sum;
                cout << '-';
        }

        change.Knut = sum % 29;
        sum /= 29;
        change.Sickle = sum % 17;
        change.Galleon = sum / 17;

        cout << change.Galleon << '.' << change.Sickle << '.' << change.Knut;

        return 0;
}
