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


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode *curr=head;

        while(curr!=NULL){

            if(curr->next!=NULL && curr->val==curr->next->val){  // sorted hai to next pe duplicate check hoga ki nhi hoga? haanji hogaaaa xD

                ListNode *temp=curr->next;
                curr->next = curr->next->next;

                delete temp;
            }

            else {
                curr=curr->next;
            }
        }
    }
 };