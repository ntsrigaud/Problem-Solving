#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      std::set<int> record;
      auto p_trav = head;
      ListNode *prev = nullptr;
      int cur_val = 0;

      while (p_trav != nullptr) {
        if (record.count(p_trav->val)) {
          // Prev will be already populated
          // Move onto the next non-recorded item
          cur_val = p_trav->val;
          while (p_trav != nullptr && p_trav->val == cur_val) {
            p_trav = p_trav->next;
          }
          prev->next = p_trav;
        } else {
          record.insert(p_trav->val);
          prev = p_trav;
          p_trav = p_trav->next;
        }
      }

      return head;
    }
};
