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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int l1 = 0, l2=0;
        while(temp1) {
            l1++;
            temp1 = temp1->next;
        }
        while(temp2) {
            l2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        int diff = abs(l1 - l2);
        
        if(l1>l2) {
            for(int i=0; i<diff; i++) {
                temp1 = temp1->next;
            }
        }
        else if(l2>l1) {
            for(int i=0; i<diff; i++) {
                temp2 = temp2->next;
            }
        }
        while(temp1!=temp2) {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1) return temp1;
        return temp2;
    }
};