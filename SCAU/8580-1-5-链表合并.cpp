/*
 * 8580. 合并链表
*/
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
        list<int> l1, l2, res;
        int n, temp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> temp;
                l1.push_back(temp);
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> temp;
                l2.push_back(temp);
        }

        cout << "List A:";
        for (int i : l1) cout << i << ' ';
        cout << endl;

        cout << "List B:";
        for (int i : l2) cout << i << ' ';
        cout << endl;

        while (!l1.empty() && !l2.empty()) {
                auto &smaller = l1.front() > l2.front() ? l2 : l1;
                res.push_back(smaller.front());
                smaller.pop_front();
        }
        auto &left = l1.empty() ? l2 : l1;
        while (!left.empty()) {
                res.push_back(left.front());
                left.pop_front();
        }
        cout << "List C:";
        for (int i : res) cout << i << ' ';

        return 0;
}
