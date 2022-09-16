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
//     ListNode* merge2Lists(ListNode*l1, ListNode*l2) {
//         ListNode* temp1 = l1;
//         ListNode* temp2 = l2;
//         ListNode* head = NULL;
//         ListNode* prev = NULL;   // jaha tak list sort ho chuki hai
        
//         while(temp1!=NULL && temp2!=NULL) {
//             if(temp1->val <= temp2->val) {
//                 if(head==NULL) {
//                     head = temp1;
//                     prev = temp1;
//                     temp1 = temp1->next;
//                 }
//                 else {
//                     prev->next = temp1;
//                     prev = prev->next;
//                     temp1 = temp1->next;
//                 }
//             }
//             else {
//                 if(head == NULL ){
//                     head = temp2;
//                     prev = temp2;
//                     temp2 = temp2->next;
//                 }
//                 else {
//                     prev->next = temp2;
//                     prev = prev->next;
//                     temp2 = temp2->next;
//                 }
//             }
//         }
        
//         if(temp1!=NULL) {
//             prev->next = temp1;
//         }
//         else if(temp2!=NULL) {
//             prev->next = temp2;
//         }
//         return head;
//     }
    
    ListNode* merge(ListNode* a,ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        ListNode* temp=NULL;
        if(a->val<=b->val) 
        {
            temp =a;
            temp->next = merge(a->next,b);
        }
        else 
        {
            temp = b;
            temp->next = merge(a,b->next);
        }
        return temp;        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode*dummy = NULL;
        
        for(int i=0; i<lists.size(); i++) {
            
            dummy = merge(dummy,lists[i]);
            
        }
        return dummy;
    }
};