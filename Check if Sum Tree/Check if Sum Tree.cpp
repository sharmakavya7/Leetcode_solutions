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

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    int helper(Node* root) {
        
        if(!root) {
            return 0;
        }
        int sum = root->data;
        if(root->left) {
            sum+=helper(root->left);
        }
        // sum+=root->data;
        if(root->right) {
            sum+=helper(root->right);
        }
        // sum+=root->data;
        return sum;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(!root) return true;
         if(!root->left && !root->right) {
             return true;
         }
         if(root->data != helper(root->left) + helper(root->right)) {
             return false;
         }
         return isSumTree(root->left) && isSumTree(root->right);
    }
};