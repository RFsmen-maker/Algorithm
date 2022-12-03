/*
* 225. implementStackUsingQueue
*/
#include <iostream>
#include <queue>

using namespace std;

// 参考 2
// 只使用一个队列，每次入栈将前 n 个出列再入队
// 入栈 O(2n+1), T = O(1)
class MyStack2 {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }

    /** Get the top element. */
    int top() {
        int r = q.front();
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

// 参考题解优化代码 1
// 入栈操作 O(2n+1)，其他 O(1)
// 与我的思路不同点在于：
// 我的更适用于有大量数据读入的情况，出栈、访问栈顶才倒转
// 官方题解更适用于大量读取、访问的情况，每次入栈元素倒转
class MyStack1 {
public:
        int top;
        queue<int> queue1; // 永久地作为一个栈
        queue<int> queue2; // 作为临时队列

        MyStack() {
        }

        void push(int x) { // 每入一个元素就倒转
                queue2.push(x);
                while(!queue1.empty()) {
                        queue2.push(queue1.front());
                        queue1.pop();
                }
                swap(queue1, queue2);
        }

        int pop() {
                int r = queue1.front();
                queue1.pop();
                return r;
        }

        int top() {
                int r = queue1.front();
                return r;
        }

        bool empty() {
                return queue1.empty();
        }
};

// 我的题解
// 入栈 O(1)，其他 O(n)
class MyStack {
public:
        queue<int> tempQ[2];
        bool flag; // 标记当前使用的队列
    MyStack() {
        flag = false;
    }

    void push(int x) {
            int tempIn = (flag == true) ? 1 : 0;
        tempQ[tempIn].push(x);
    }

    int pop() {
            int tempIn = (flag == true) ? 1 : 0;
            int tempIn_oppo = (flag == true) ? 0 : 1;
        while(tempQ[tempIn].size() != 1)
        {
                tempQ[tempIn_oppo].push(tempQ[tempIn].front());
                tempQ[tempIn].pop();
        }
        int dest = tempQ[tempIn].front();
        tempQ[tempIn].pop();
        flag = (flag == true) ? false : true;
        return dest;
    }

    int top() {
            int tempIn = (flag == true) ? 1 : 0;
            int tempIn_oppo = (flag == true) ? 0 : 1;
        while(tempQ[tempIn].size() != 1)
        {
                tempQ[tempIn_oppo].push(tempQ[tempIn].front());
                tempQ[tempIn].pop();
        }
        int dest = tempQ[tempIn].front();
        tempQ[tempIn_oppo].push(tempQ[tempIn].front());
        tempQ[tempIn].pop();
        flag = (flag == true) ? false : true;
        return dest;
    }

    bool empty() {
            int tempIn = (flag == true) ? 1 : 0;
        return tempQ[tempIn].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
