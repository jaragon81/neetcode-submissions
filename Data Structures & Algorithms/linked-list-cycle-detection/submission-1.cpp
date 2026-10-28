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
    bool hasCycle(ListNode* head) {
        std::set<int> tmp{};
        bool ret = false;
        while (head && head->next != nullptr) {
            if (tmp.find(head->val) != tmp.end()) {
                ret = true;
                break;
            }
            tmp.insert(head->val);
            head = head->next;
        }
        return ret;
    }
};
