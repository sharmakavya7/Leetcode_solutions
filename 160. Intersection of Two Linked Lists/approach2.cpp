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
        
        while(temp1 && temp2 && temp1!=temp2) {
            temp1=temp1->next;
            temp2=temp2->next;
            
            if(temp1==temp2){
                return temp1;   // or return temp2 any
            }
            if(temp1==NULL) {
                temp1 = headB;
            }
            if(temp2==NULL) {
                temp2 = headA;
            }
        }
        return temp1;
    }
};