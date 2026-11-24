/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* curr = &dummy;
        std::unordered_map<Node*, Node*> mp{};
        Node* src_cpy = head;
        while (head) {
            Node* node = new Node(head->val);
            mp[head] = node;
            curr->next = node;
            curr = curr->next;
            head = head->next;
        }

        head = src_cpy;
        curr = dummy.next;
        while (curr) {
            curr->random = mp[head->random];
            curr = curr->next;
            head = head->next;
        }

        return dummy.next;
    }
};
