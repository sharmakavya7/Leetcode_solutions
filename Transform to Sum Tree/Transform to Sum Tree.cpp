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

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
    private:
        int helper(Node* node) {
            if(node == NULL) {
                return 0;
            }
            // Your code here
            int prev = node->data;
            
            node->data = helper(node->left)+helper(node->right);
            
            return node->data + prev;
        }
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        helper(node);
        
    }
};