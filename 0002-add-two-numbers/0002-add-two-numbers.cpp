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
        bool mem = false;
        ListNode* result = new ListNode(-1);
        ListNode* on = result;
        while (l1 || l2) {
            int sum = (mem ? 1 : 0);
            if (l1) {sum += l1->val; l1 = l1->next; }
            if (l2) {sum += l2->val; l2 = l2->next; }
            mem = sum >= 10;
            
            on->next = new ListNode(sum % 10);
            on = on->next;
        }
        if (mem) on->next = new ListNode(1);
        return result->next;
    }
};