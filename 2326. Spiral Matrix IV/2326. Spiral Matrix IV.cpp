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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>nums(m, vector<int>(n,-1));

        int top=0, down=m-1, right=n-1, left=0;
        int dir=0;
        while(left<=right && top<=down && head!=NULL) {
            
            if(dir==0) {
                for(int i=left; i<=right && head; i++) {
                    nums[top][i] = head->val;
                    head = head->next;
                }
                dir=1;
                top++;
            }
            else if(dir==1) {
                for(int i=top; i<=down && head; i++) {
                    nums[i][right] = head->val;
                    head = head->next;
                }
                dir = 2;
                right--;
            }
            else if(dir==2) {
                for(int i=right; i>=left && head; i--) {
                    nums[down][i] = head->val;
                    head = head->next;
                }
                dir = 3;
                down--;
            }
            else if(dir==3) {
                for(int i=down; i>=top && head; i--) {
                    nums[i][left] = head->val;
                    head = head->next;
                }
                dir = 0;
                left++;
            }
        }
        return nums;
    }
};
