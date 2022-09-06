/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) {
            return false;
        }
        // if()
        unordered_map<ListNode*, int>mp;
        ListNode*p = head;
        
        while(p->next!=NULL) {
            if(mp.find(p)!=mp.end()) {
                return true;
            }
            mp[p]++;
            p=p->next;
        }
        return false;
    }
};