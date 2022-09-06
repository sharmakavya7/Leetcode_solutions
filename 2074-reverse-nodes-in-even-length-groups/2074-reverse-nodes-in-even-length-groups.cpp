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
    
    ListNode* helper(ListNode* head, int&len, int k) {
        if(head==NULL) return head;
        
        ListNode* prevNextHead;      // last node of current group
        ListNode* nextHead = head;       // head node of next group
        
        for(int i=0; i<k; i++) {       // k is initially 1
            prevNextHead = nextHead;   // points 2
            nextHead = nextHead->next; // points 3
        }
        len-=k;
        
        // returns head of next group
        ListNode *newHead=helper(nextHead,len,min(k+1,len));  
        // min(k+1, len) -> for edge cases like: [0,4,2,1,3] --> [0,2,4,3,1], we need to pass on length of next group accordingly
        
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        
        if(k%2==0) {
            // reverse
            while(cur!=nextHead) {
                ListNode* nxt = cur->next;    // cur ke next me pohocha do next ko
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
        }
        
        // head of prev group ko connect krna hai to the reversed linkedList
        if(k%2==0) {
            head->next = newHead;
        }
        else {
            prevNextHead->next = newHead;
        }
        
        return (k%2==0 ? prev : head);
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==NULL || head->next ==NULL) {
            return head;
        }
        ListNode* temp = head;
        int len = 1;
        while(temp->next!=NULL) {
            temp = temp->next;
            len++;
        }
        return helper(head, len, 1);
    }
};