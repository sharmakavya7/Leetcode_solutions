#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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

        // alternate way to add remaining elements
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