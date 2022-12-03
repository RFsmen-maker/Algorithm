/*
Basic-1057: Count the 0 and 1.
strategy:
        According to the question, the maximum number is the 26 * 10^5,
        which is contained in the type long.
        It's required to count the binary 1 and 0, just need to constantly
        make the sum number divided by 2.
        If the total number is the 0, just output the "0 0", forget about the
        explanation of the question.
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        string tempStr;
        getline(cin, tempStr);

        int len = tempStr.length();
        int tempIn;
        long totalNum = 0;
        for(auto tempCh = begin(tempStr); tempCh != end(tempStr); ++tempCh)
        {
                tempIn = 0;
                if(*tempCh <= 'Z' && *tempCh >= 'A') {
                        tempIn = (*tempCh) - 'A' + 1;
                }
                else if(*tempCh <= 'z' && *tempCh >= 'a') {
                        tempIn = (*tempCh) - 'a' + 1;
                }
                totalNum += tempIn;
        }

        int count1, count0;
        count1 = count0 = 0;
        while(totalNum > 0)
        {
                if(totalNum % 2) {
                        ++count1;
                }
                else {
                        ++count0;
                }
                totalNum >>= 1;
        }
        cout << count0 << ' ' << count1;

        return 0;
}
