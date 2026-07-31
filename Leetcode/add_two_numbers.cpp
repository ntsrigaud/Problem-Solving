// Leetcode #2 - Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;

    using CarryRest = std::pair<int, int>;
    CarryRest carryRest = {0, 0};

    auto updateCarryRest = [&]() -> void {
      int sum = ((l1 && l2) ? l1->val + l2->val
                 : (l1)     ? l1->val
                            : l2->val) +
                carryRest.first;
      carryRest = {sum / 10, sum % 10};
    };

    while (l1 != nullptr && l2 != nullptr) {
      updateCarryRest();
      if (head == nullptr) {
        head = new ListNode(carryRest.second);
        curr = head;
        l1 = l1->next;
        l2 = l2->next;
      } else {
        curr->next = new ListNode(carryRest.second);
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
      }
    }

    while (l1 != nullptr) {
      updateCarryRest();
      curr->next = new ListNode(carryRest.second);
      curr = curr->next;
      l1 = l1->next;
    }

    while (l2 != nullptr) {
      updateCarryRest();
      curr->next = new ListNode(carryRest.second);
      curr = curr->next;
      l2 = l2->next;
    }

    if (carryRest.first != 0) {
      curr->next = new ListNode(carryRest.first);
    }

    return head;
  }
};
