// Leetcode #0234 - Palindrome Linked List

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
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    std::stack<ListNode *> stack;

    while (fast != nullptr && fast->next != nullptr) {
      stack.push(slow);
      slow = slow->next;
      fast = fast->next->next;
    }

    // Skip middle element if any
    if (fast != nullptr) {
      slow = slow->next;
    }

    // Slow is at middle
    while (!stack.empty() && slow != nullptr) {
      if (slow->val != stack.top()->val) {
        return false;
      }

      stack.pop();
      slow = slow->next;
    }

    return stack.empty() && slow == nullptr;
  }
};
