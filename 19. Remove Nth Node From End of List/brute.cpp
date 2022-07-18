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


//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next){
            return nullptr;
        }
        //if two element
        if(!head->next->next){
            if(n==1){
                head->next=nullptr;
                return head;
            }
            else{
                return head->next;
            }
        }
        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL) {
            cnt++;
            temp = temp->next;
        }
        int r = cnt - n;  // 5-2 = 3

        //1st edge case if first element removed
        if(r==0) {
            return head->next;
        }
        temp = head;
        int ctr=0;
        while(temp){
            //if element found is n-1th from end
            if(ctr==cnt-n-1){
      
                if(temp->next->next!=nullptr){
                    temp->next=temp->next->next;
                }
                //2nd edge case if last element removed
                else{
                    temp->next = nullptr;
                }
            }
            temp = temp->next;
            ctr++;
        }
        return head;
    }
};

// Time Complex: O(n) + O(n) ~ O(n)