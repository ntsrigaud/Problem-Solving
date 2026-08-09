// Leetcode #160 - Intersection of Two Linked Lists

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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto *pos_a = headA;
    auto *pos_b = headB;

    // Traverse all the distance entirely until both pointers encounter or not
    while (pos_a != pos_b) {
      pos_a = (pos_a != nullptr) ? pos_a->next : headB;
      pos_b = (pos_b != nullptr) ? pos_b->next : headA;
    }

    return pos_a;
  }
};
