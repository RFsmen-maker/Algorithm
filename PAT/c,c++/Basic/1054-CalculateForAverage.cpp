/*
* Basic-1054 Calculate for Average
* �������⣺���Ե� 2��3 һֱ����
* ���� <https://blog.csdn.net/weixin_45964844/article/details/113681652?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control>
* ���Ե� 2 �жϳ����ǵ�����number û�� s �����
* ���Ե� 3 �ж�����ǰ��ΪС�����ǷǷ���������
* ��Ȼ�������´�����
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        int N;
        cin >> N;

        int legalCo = 0;
        double sum;
        while(N--)
        {
                bool judge = 0;
                string tempStr;
                cin >> tempStr;

                if(tempStr.size() > 7) continue;

                int dotCo, preCheck;
                dotCo = preCheck = 0;
                for(auto i = tempStr.begin(); i != tempStr.end(); i++)
                {
                        if((*i <= '9' && *i >= '0') || (i == tempStr.begin() && *i == '-')) {
                                if(dotCo == 1) {
                                        preCheck++;
                                        if(preCheck > 2) {
                                                judge = 1;
                                                break;
                                        }
                                }
                                continue;
                        }
                        else if(*i == '.') {
                                dotCo++;
                                if(dotCo > 1 || (i+1) == tempStr.end() || i == tempStr.begin()) {
                                        judge = 1;
                                        break;
                                }
                        }
                        else {
                                judge = 1;
                                break;
                        }
                }

                double tempDo;
                if(dotCo) tempDo = atof(tempStr.c_str());
                else tempDo = static_cast<double>(atoi(tempStr.c_str()));
                if(tempDo > 1000 || tempDo < -1000) judge = 1;

                if(judge) {
                        cout << "ERROR: " << tempStr << " is not a legal number" << endl;
                }
                else {
                        sum += tempDo;
                        legalCo++;
                }
        }

        if(legalCo == 1) cout << "The average of 1 number is ";
        else cout << "The average of " << legalCo << " numbers is ";
        if(!legalCo) cout << "Undefined";
        else {
                cout.precision(2);
                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << sum / legalCo;
        }

        return 0;
}
