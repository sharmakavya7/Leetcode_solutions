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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        //ListNode *dummy = NULL;
        //agr mai fast ko 2 aage se start krungi ro slow wala mid ke 1 pehli node pe ruk jaegaaaaa naaaaaaaaaaaaaaaaaaa
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            //dummy = dummy->next;
            fast = fast->next->next;
        }
        //ListNode *temp = slow;
        //dummy->next = slow->next;
        slow->next = slow->next->next;
        //free(slow->next);
        return head;
    }
};