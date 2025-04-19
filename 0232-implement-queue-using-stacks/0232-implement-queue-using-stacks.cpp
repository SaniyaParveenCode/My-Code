#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (empty()) return 0;

        if (!st2.empty()) {
            int element = st2.top();
            st2.pop();
            return element;
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int element = st2.top();
            st2.pop();
            return element;
        }
    }

    int peek() {
        if (empty()) return 0;

        if (!st2.empty()) {
            return st2.top();
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};
