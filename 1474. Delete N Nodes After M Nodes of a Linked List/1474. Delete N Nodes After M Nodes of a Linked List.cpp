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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* res = new ListNode;
        res->next = head;
        
        ListNode* temp = res;
        
        while(temp->next!=NULL) {
            for(int i=0; i<m && temp->next; i++) {
                temp=temp->next;
            }
            ListNode* aage = temp;
            for(int i=0; i<n && aage->next; i++) {
                // ListNode* del = aage;
                aage = aage->next;
                // delete del;
            }
            temp->next = aage->next;
        }
        return res->next;
    }
};