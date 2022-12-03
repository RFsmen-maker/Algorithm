/*
 * 1.2 合并顺序表
 * 类似归并排序
*/
#include <iostream>

using namespace std;

class SeqList {
public:
        int capacity;
        int curPos;
        int *elem;
        SeqList() {}
        void init(int size)
        {
                this->curPos = 0;
                this->capacity = size;
                this->elem = new int[size];
        }
        void load() {
                for (int i = 0; i < this->capacity; ++i) cin >> this->elem[i];
        }
        void read(int size)
        {
                this->init(size);
                this->load();
        }
        void show(const char *str)
        {
                cout << "List " << str << ':';
                for (int i = 0; i < this->capacity; ++i)
                        cout << this->elem[i] << ' ';
                cout << endl;
        }
};

int main(void)
{
        SeqList A, B, C;
        int a, b;
        cin >> a;
        A.read(a);
        cin >> b;
        B.read(b);
        C.init(a+b);

        while(A.curPos < A.capacity && B.curPos < B.capacity) {
                int &key = A.elem[A.curPos] < B.elem[B.curPos] ? A.elem[A.curPos++] : B.elem[B.curPos++];
                C.elem[C.curPos++] = key;
        }
        SeqList &left = A.curPos < A.capacity ? A : B;
        while (left.curPos < left.capacity)
                C.elem[C.curPos++] = left.elem[left.curPos++];

        A.show("A");
        B.show("B");
        C.show("C");

        return 0;
}
