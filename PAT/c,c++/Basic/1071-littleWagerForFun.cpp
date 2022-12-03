#include <iostream>

using namespace std;

int main(void)
{
        class {
        public:
                int jetton;
                int round;

                void win(int t)
                {
                        this->jetton += t;
                        cout << "Win " << t << "!  Total = " << this->jetton << '.' << endl;
                }

                void lose(int t)
                {
                        this->jetton -= t;
                        cout << "Lose " << t << ".  Total = " << this->jetton << '.' << endl;
                }

                void notEnough()
                {
                        cout << "Not enough tokens.  Total = " << this->jetton << '.' << endl;
                }

                void gameOver()
                {
                        cout << "Game Over." << endl;
                }
        }player;

        cin >> player.jetton >> player.round;
        while(player.round--)
        {
                int n1, b, t, n2;
                cin >> n1 >> b >> t >> n2;
                if(player.jetton <= 0) {
                        player.gameOver();
                        break;
                }
                if(player.jetton < t) {
                        player.notEnough();
                        continue;
                }
                if((!b && n1>n2) || (b && n1<n2)) {
                        player.win(t);
                        continue;
                }
                else {
                        player.lose(t);
                        continue;
                }
        }


        return 0;
}
