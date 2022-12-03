#include <iostream>

using namespace std;

char game[3] = {'B', 'C', 'J'};

class player {
public:
        char hand, most;
        unsigned int win, lose;
        unsigned int winHand[3];

        player() {
                this->win = this->lose = 0;
                for(int i = 0; i < 3; i++) winHand[i] = 0;
        }

        inline void winSort(void) {
                unsigned int temp = 0;
                for(int i = 1; i < 3; i++)
                {
                        if(winHand[i] > winHand[temp]) temp = i;
                }
                this->most = game[temp];
        }
};

int main(void)
{
        player p1, p2;
        unsigned int N, fair = 0;
        cin >> N;
        while(N--)
        {
                cin >> p1.hand >> p2.hand;
                // B > C > J > B
                switch(p1.hand)
                {
                case 'B':
                        {
                                if(p2.hand == 'C') {
                                        p1.win++, p2.lose++, p1.winHand[0]++;continue;
                                }
                                else if(p2.hand == 'J') {
                                        p2.win++, p1.lose++, p2.winHand[2]++;continue;
                                }
                        }break;
                case 'C':
                        {
                                if(p2.hand == 'J') {
                                        p1.win++, p2.lose++, p1.winHand[1]++;continue;
                                }
                                else if(p2.hand == 'B') {
                                        p2.win++, p1.lose++, p2.winHand[0]++;continue;
                                }
                        }break;
                case 'J':
                        {
                                if(p2.hand == 'B') {
                                        p1.win++, p2.lose++, p1.winHand[2]++;continue;
                                }
                                else if(p2.hand == 'C') {
                                        p2.win++, p1.lose++, p2.winHand[1]++;continue;
                                }
                        }break;
                };
                fair++;
        }
        p1.winSort(), p2.winSort();

        cout << p1.win << ' ' << fair << ' ' << p1.lose << endl
        << p2.win << ' ' << fair << ' ' << p2.lose << endl
        << p1.most << ' ' << p2.most;

        return 0;
}
