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
    ListNode* reverseList(ListNode* start, ListNode* end) {
        if(start==NULL) {
            return NULL;
        }
        ListNode* prev = NULL;      // previous node
        ListNode* temp = start->next;  // next node
        while(start!=end) {
            temp = start->next; 
            start->next = prev;
            prev = start;
            start = temp;
            // temp = start->next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto temp = head;
        
        for(int i=1; i<=k; i++) {
            if(temp==NULL) {
                return head;
            }
            temp=temp->next;
        }
        auto ans = reverseList(head, temp);
        head->next = reverseKGroup(temp, k);
        return ans;
    }
};