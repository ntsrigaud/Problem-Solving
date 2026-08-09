// Leetcode #141 - Linked List Cycle

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // Floyd's Cycle-Finding Algorithm (Tortoise & Hare)
    auto *slow = head;
    auto *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = (fast->next != nullptr) ? fast->next->next : nullptr;

      if (slow == fast) {
        return true;
      }
    }

    return false;
  }
};
