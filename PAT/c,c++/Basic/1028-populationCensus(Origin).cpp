/*
Basic-1028 Population Census
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        class CITIZEN{
        public:
                string name;
                int year;
                int month;
                int day;
                void readin(void) {
                        cin >> this->name >> this->year;
                        cin.get();
                        cin >> this->month;
                        cin.get();
                        cin >> this->day;
                }
                bool errDate(const CITIZEN &bottom, const CITIZEN &top) {
                        if(this->year < top.year && this->year > bottom.year) return 1;
                        else {
                                if(this->year == top.year) {
                                        if(this->month < top.month) return 1;
                                        else {
                                                if(this->month != top.month) return 0;
                                                else {
                                                        if(this->day <= top.day) return 1;
                                                        else return 0;
                                                }
                                        }
                                }
                                else if(this->year == bottom.year) {
                                        if(this->month > bottom.month) return 1;
                                        else {
                                                if(this->month != bottom.month) return 0;
                                                else {
                                                        if(this->day >= bottom.day) return 1;
                                                        else return 0;
                                                }
                                        }
                                }
                                else return 0;
                        }
                }
        };
        const CITIZEN TODAY = {"today", 2014, 9, 6};
        const CITIZEN LIMITAGE = {"unborn", 1814, 9, 6};

        int N, effCount = 0;
        cin >> N;
        CITIZEN temp, youngest, oldest;
        temp.readin();
        if(temp.errDate(LIMITAGE, TODAY)) ++effCount;
        youngest = oldest = temp;
        for(int i = 1; i < N; i++)
        {
                temp.readin();
                if(temp.errDate(LIMITAGE, TODAY)) {
                        ++effCount;
                        if(!oldest.errDate(LIMITAGE, temp)) {
                                oldest = temp;
                        }
                        if(!youngest.errDate(temp, TODAY)) {
                                youngest = temp;
                        }
                }
        }

        if(effCount) {
                cout << effCount <<' '<< oldest.name <<' '<< youngest.name;
        }
        else {
                cout << effCount;
        }

        return 0;
}
