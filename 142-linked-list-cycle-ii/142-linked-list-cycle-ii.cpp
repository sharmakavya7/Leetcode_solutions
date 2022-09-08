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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        unordered_map<ListNode*, int>mp;
        
        // for(ListNode* temp=head; temp!=NULL; temp=temp->next) {
        //     mp[temp]++;
        // }
        
        for(ListNode* temp=head; temp!=NULL; temp=temp->next) {
            
            if(mp.find(temp)!=mp.end())
                return temp;
            
            mp[temp]++;
        }
        return NULL; 
    }
};