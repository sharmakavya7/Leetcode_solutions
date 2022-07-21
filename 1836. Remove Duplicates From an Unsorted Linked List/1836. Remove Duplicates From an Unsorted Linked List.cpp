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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int>mp;
        
        for(auto t=head; t!=NULL; t=t->next) {
            mp[t->val]++;
            // cout<<mp[t->val]<<" ";
        }
        ListNode* dummy = new ListNode(0);
        // dummy->next = head;    // OH MY GOD!!!
        ListNode* prev = dummy;
        ListNode* cur = head;
        
        // for(ListNode* cur=head; cur!=NULL; cur=cur->next) {
        while(cur) {
            ListNode *currNext = cur->next;
            if(mp[cur->val]==1) {
                cur->next = NULL;
                prev->next = cur;
                prev = prev->next;
                cur = currNext;
            }
            else {
                cur=currNext;
            }
        }
        // if(dummy->next==NULL) return NULL;
        return dummy->next;
    }
};