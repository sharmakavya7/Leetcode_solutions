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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(NULL);
        ListNode* temp = dummy;
        int carry=0;
        
        while(l1 || l2 || carry) {  // carry agr last me bachega to usko bhi to add krne ke process me consider krenge naaaaa
            int sum=0;
            
            if(l1!=NULL) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp=temp->next;
        }
        return dummy->next;
    }
};