// Leetcode #203 - Remove Linked List Elements

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
  ListNode *removeElements(ListNode *head, int val) {
    // Find new head first
    while (head != nullptr && head->val == val) {
      head = head->next;
    }

    if (head == nullptr) {
      return nullptr;
    }

    // Two-pointers algorithm
    ListNode *prev = head;
    ListNode *cur = head->next;

    while (cur != nullptr) {
      if (cur->val != val) {
        prev->next = cur;
        prev = prev->next;
      }

      cur = cur->next;
    }

    if (prev->next != nullptr && prev->next->val == val) {
      prev->next = nullptr;
    }

    return head;
  }
};
