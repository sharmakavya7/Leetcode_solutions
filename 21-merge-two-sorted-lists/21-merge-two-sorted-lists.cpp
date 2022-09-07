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
        
        ListNode* temp1=l1;   
        ListNode* temp2=l2;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                if(head==NULL)
                {
                    head=tail=temp1;
                    temp1=temp1->next;
                }
                else
                {
                    tail->next=temp1;
                    tail=tail->next;
                    temp1=temp1->next;
                }
            }
            else
            {
                if(head==NULL)
                {
                    head=tail=temp2;
                    temp2=temp2->next;
                }
                else
                {
                    tail->next=temp2;
                    tail=tail->next;
                    temp2=temp2->next;
                }
            }
        }
        // adding remaining elements of bigger list.
        if(!temp1) {
            tail->next = temp2;
        }
        else {
            tail->next = temp1;
        }
        // while(temp1!=NULL)
        // {
        //     if(head==NULL)
        //     {
        //         head=tail=temp1;
        //         temp1=temp1->next;
        //     }
        //     else
        //     {
        //         tail->next=temp1;
        //         tail=tail->next;
        //         temp1=temp1->next;
        //     }
        // }
        // while(temp2!=NULL)
        // {
        //     if(head==NULL)
        //     {
        //         head=tail=temp2;
        //         temp2=temp2->next;
        //     }
        //     else
        //     {
        //         tail->next=temp2;
        //         tail=tail->next;
        //         temp2=temp2->next;
        //     }
        // }
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