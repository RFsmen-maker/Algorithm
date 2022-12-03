/*
* 232. 使用栈实现队列
*/
#include <iostream>
#include <stack>

using namespace std;

// 官方题解，据说均摊 T = O(1)
// 半动态，出栈时且存储栈为空时才倒转
class MyQueue1 {
private:
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

// 我的题解：与昨天使用队列实现栈的官方题解思路一样
// 每进一个元素对栈进行倒转
// push T = O(n), others T = O(1)
class MyQueue {
private:
        stack<int> inStack;
        stack<int> outStack;
        void pourIn() {
                while (!inStack.empty())
                {
                        outStack.push(inStack.top());
                        inStack.pop();
                }
        }

        void pourOut() {
                while (!outStack.empty())
                    {
                            inStack.push(outStack.top());
                            outStack.pop();
                    }
        }

public:

    MyQueue() {

    }

    void push(int x) {
            if (!outStack.empty()) {
                pourOut();
            }
            inStack.push(x);
                pourIn();
    }

    int pop() {
            int dest = outStack.top();
            outStack.pop();
            return dest;
    }

    int peek() {
            return outStack.top();
    }

    bool empty() {
        return outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
