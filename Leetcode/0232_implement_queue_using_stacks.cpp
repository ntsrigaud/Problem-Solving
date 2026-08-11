// Leetcode #0232 - Implement Queue using Stacks

#include <stack>

class MyQueue {
  std::stack<int> s1;
  std::stack<int> s2;
  bool reverse_order = false;

  void transfer_back() {
    // Transfer them back for correct insertion order
    if (reverse_order) {
      while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
      reverse_order = false;
    }
  }

public:
  MyQueue() {
    while (!s1.empty()) {
      s1.pop();
    }
  }

  void push(int x) {
    transfer_back();
    s1.push(x);
  }

  int pop() {
    int n = 0;

    if (reverse_order) {
      n = s2.top();
      s2.pop();
    } else {
      while (s1.size() > 1) {
        s2.push(s1.top());
        s1.pop();
      }
      reverse_order = true;

      n = s1.top();
      s1.pop();
    }

    return n;
  }

  int peek() {
    if (!reverse_order) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      reverse_order = true;
    }

    return s2.top();
  }

  bool empty() { return (reverse_order) ? s2.empty() : s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
