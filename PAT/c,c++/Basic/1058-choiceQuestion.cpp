/*
Basic-1058 Choice question.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        class QUESTION {
        public:
                int point;
                int options;
                int corOptions;
                int amoErr;
                vector<char> answer;
                void readin(void) {
                        char tempCh;
                        cin >> this->point >> this->options >> this->corOptions;
                        for(int j = 0; j < this->corOptions; j++)
                        {
                                cin >> tempCh;
                                this->answer.push_back(tempCh);
                        }
                }
        };
        class STUDENT {
        public:
                int score;
                int *choiceAmount;
                vector<char> *selection;
                void readin(int amoQue) {
                        char tempCh;
                        this->score = 0;
                        this->choiceAmount = new int[amoQue];
                        this->selection = new vector<char>[amoQue];
                        for(int j = 0; j < amoQue; j++)
                        {
                                while(cin >> tempCh && tempCh != ')')
                                {
                                        if(tempCh == '(') {
                                                   cin >> this->choiceAmount[j];
                                                   for(int k = 0; k < this->choiceAmount[j]; k++)
                                                   {
                                                           cin >> tempCh;
                                                           this->selection[j].push_back(tempCh);
                                                   }
                                           }
                                }
                        }
                }
        };

        char tempCh;
        int amoStu, amoQue;
        cin >> amoStu >> amoQue;

        QUESTION *question = new QUESTION[amoQue];

        for(int i = 0; i < amoQue; i++)
        {
                question[i].readin();
        }

        STUDENT *student = new STUDENT[amoStu];

        for(int i = 0; i < amoStu; i++)
        {
                student[i].readin(amoQue);
        }

        bool errFlag;
        int maxErr = 0;

        for(int i = 0; i < amoQue; i++)
        {
                for(int j = 0; j < amoStu; j++)
                {
                        errFlag = 0;
                        if(question[i].corOptions == student[j].choiceAmount[i]) {
                                for(int k = 0; k < question[i].corOptions; k++)
                                {
                                        if(question[i].answer[k] != student[j].selection[i][k]) {
                                                errFlag = 1;
                                                break;
                                        }
                                }
                        }
                        else {
                                errFlag = 1;
                        }
                        if(errFlag) {
                                question[i].amoErr++;
                        }
                        else {
                                student[j].score += question[i].point;
                        }
                }
                maxErr = maxErr < question[i].amoErr ? question[i].amoErr : maxErr;
        }

        for(int i = 0; i < amoStu; i++)
        {
                cout << student[i].score << endl;
        }

        if(!maxErr) {
                cout << "Too simple";
        }
        else {
                cout << maxErr;
                for(int i = 0; i < amoQue; i++)
                {
                        if(question[i].amoErr == maxErr) {
                                cout <<' '<< i+1;
                        }
                }
        }

        return 0;
}
