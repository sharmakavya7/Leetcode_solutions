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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
    
    bool isPalindrome(ListNode* head) {
        int res = 0;
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {  // finding middle
            fast = fast->next->next;
            slow = slow->next;                 // slow will point to middle
        }
        slow = reverseList(slow);              // reversing the half starting from middle
        ListNode *p = head;
        ListNode * q = slow;
        while (p != NULL && q != NULL) {
            if (p->val != q->val) return false;
            p = p->next; q = q->next;
        }
        
        return true;
    }
};