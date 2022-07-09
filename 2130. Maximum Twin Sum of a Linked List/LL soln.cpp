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


 // * Definition for singly-linked list.
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
    int pairSum(ListNode* head) {
        int res = 0;
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {  // finding middle
            fast = fast->next->next;
            slow = slow->next;                 // slow will point to middle
        }
        slow = reverseList(slow);              // reversing the half starting from middle
        while (slow != nullptr) {              // traverse first half from starting
            res = max(res, slow->val + head->val);  // and the other from middle
            slow = slow->next;
            head = head->next;
        }
        return res;
    }
};