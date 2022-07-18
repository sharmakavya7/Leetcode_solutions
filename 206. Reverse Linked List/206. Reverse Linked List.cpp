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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* cur = NULL;
    //     while (head) {
    //         ListNode* next = head -> next;
    //         head -> next = cur;
    //         cur = head;
    //         head = next;
    //     }
    //     return cur;
    // }

    // Alternate Solution:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) {
            return NULL;
        }
        ListNode* prev = NULL;      // previous node
        ListNode* cur = head; // current node
        ListNode* next = head->next;  // next node
        while(cur!=NULL) {
            next = cur->next;  // cur ke next me pohocha do next ko
            cur->next = prev;
            prev = cur;
            cur = next;
            // next = cur->next;
        }
        head = prev;
        return head;
    }
};