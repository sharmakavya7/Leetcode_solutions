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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyA = new ListNode (0);
        ListNode* dummyB = new ListNode (0);
        
        ListNode* tempA = dummyA;
        ListNode* tempB = dummyB;
        
        auto cur = head;
        
        for(auto cur = head; cur!=NULL; cur=cur->next) {
            if(cur->val < x) {
                ListNode *dummy = new ListNode(cur->val);
                tempA ->next = dummy;
                tempA = tempA->next;
            }
            else if(cur->val >= x) {
                ListNode *dummy = new ListNode(cur->val);
                tempB->next = dummy;
                tempB = tempB->next;
            }
        }
        tempA->next = dummyB->next;  // Link both partitions
        return dummyA->next;
    }
};