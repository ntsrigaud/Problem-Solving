// Leetcode #0206 - Reverse Linked List

#include <stack>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    };

    std::stack<ListNode *> stack;
    ListNode *cur = head;
    while (cur != nullptr) {
      stack.push(cur);
      cur = cur->next;
    }

    ListNode *r_head = stack.top();
    stack.pop();

    cur = r_head;
    while (!stack.empty()) {
      cur->next = stack.top();
      stack.pop();
      cur = cur->next;
    }

    // Avoid dangling pointers
    cur->next = nullptr;

    return r_head;
  }
};
