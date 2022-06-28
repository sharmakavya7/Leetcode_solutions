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

// Tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution
{
    public:
    int flag = 1;
    int helper(Node* root) {    // O(n)
        
        if(!root) {
            return 0;
        }
        int lsum ;
        int rsum ;
        
        if(!root->left && !root->right) {
            return root->data;
        }
        if(flag==0) return 0;
        // if(root->left) {
            lsum=helper(root->left);    
        // }
        // sum+=root->data;
        // if(root->right) {
            rsum=helper(root->right);
        // }
        if(lsum+rsum!=root->data) {
            flag=0;
        }
        // sum+=root->data;
        return lsum+rsum+root->data;
    }
    bool isSumTree(Node* root)            // Total TC: O(n)
    {
         // Your code here
         flag = 1;
         helper(root);
         return flag;
    }
};