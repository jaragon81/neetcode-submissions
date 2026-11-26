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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{};
        ListNode *curr = &dummy;
        int carr = 0;
        while (l1 && l2) {
            ListNode *tmp = new ListNode(((l1->val + l2->val) % 10) + carr);
            carr = (l1->val + l2->val) / 10;
            curr->next = tmp;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (!l1 && !l2 && carr) {
            ListNode *tmp = new ListNode(carr);
            curr->next = tmp;
        } else if (!l1 && l2) {
            curr->next = l2;
            if (l2->val + carr < 10) {
                l2->val += carr;
            } else {
                while (l2 && l2->val + carr >= 10) {
                    l2->val = 0;
                    curr = l2;
                    l2 = l2->next;
                };
                if (l2) {
                    l2->val += carr;
                } else {
                    curr->next = new ListNode(carr);
                }
            }
        } else if (!l2 && l1) {
            curr->next = l1;
            if (l1->val + carr < 10) {
                l1->val += carr;
            } else {
                while (l1 && l1->val + carr >= 10) {
                    l1->val = 0;
                    curr = l1;
                    l1 = l1->next;            
                };
                if (l1) {
                    l1->val += carr;
                } else {
                    curr->next = new ListNode(carr);
                }
            }
        }

        return dummy.next;
    }
};
