// Leetcode #0225 - Implement Stack using Queues

#include <cstddef>
#include <queue>
class MyStack {
  std::queue<int> q;

public:
  MyStack() {
    while (!q.empty()) {
      q.pop();
    }
  }

  void push(int x) { q.push(x); }

  int pop() {
    if (q.empty()) {
      return 0;
    }

    // Circle around
    size_t q_size = q.size();
    int n = 0;

    for (size_t i = 0; i < q_size - 1; ++i) {
      n = q.front();
      q.pop();
      q.push(n);
    }

    // Remove the last one and leave it out
    n = q.front();
    q.pop();

    return n;
  }

  int top() {
    int n = pop();
    push(n);
    return n;
  }

  bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
