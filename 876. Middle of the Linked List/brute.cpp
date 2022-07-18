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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL) {
            cnt++;
            temp=temp->next;
        }
        temp = head;
        if(cnt%2!=0) {
            int t = cnt/2;
            for(int i=0; i<t; i++) {
                temp = temp->next;
            }
        }
        else {
            int t = (cnt+1)/2;
            for(int i=0; i<t; i++) {
                temp = temp->next;
            }
        }
        return temp;
    }
};