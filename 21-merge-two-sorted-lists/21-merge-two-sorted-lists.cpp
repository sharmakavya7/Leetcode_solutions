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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
        {
            return NULL;
        }
        if(l1 == NULL)
            return l2;

        if(l2 == NULL)
            return l1;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = NULL;
        ListNode* prev = NULL;   // jaha tak list sort ho chuki hai
        
        while(temp1!=NULL && temp2!=NULL) {
            if(temp1->val <= temp2->val) {
                if(head==NULL) {
                    head = temp1;
                    prev = temp1;
                    temp1 = temp1->next;
                }
                else {
                    prev->next = temp1;
                    prev = prev->next;
                    temp1 = temp1->next;
                }
            }
            else {
                if(head == NULL ){
                    head = temp2;
                    prev = temp2;
                    temp2 = temp2->next;
                }
                else {
                    prev->next = temp2;
                    prev = prev->next;
                    temp2 = temp2->next;
                }
            }
        }
        
        if(temp1!=NULL) {
            prev->next = temp1;
        }
        else if(temp2!=NULL) {
            prev->next = temp2;
        }
        return head;
    }
};



//alternate
// if(NULL == l1) return l2;
//     if(NULL == l2) return l1;
    
//     ListNode* head=NULL;    // head of the list to return
    
//     // find first element (can use dummy node to put this part inside of the loop)
//     if(l1->val < l2->val)       { head = l1; l1 = l1->next; }
//     else                        { head = l2; l2 = l2->next; }
    
//     ListNode* p = head;     // pointer to form new list
    
//     // I use && to remove extra IF from the loop
//     while(l1 && l2){
//         if(l1->val < l2->val)   { p->next = l1; l1 = l1->next; }
//         else                    { p->next = l2; l2 = l2->next; }
//         p=p->next;
//     }
    
//     // add the rest of the tail, done!
//     if(l1)  p->next=l1;
//     else    p->next=l2;
    
//     return head;