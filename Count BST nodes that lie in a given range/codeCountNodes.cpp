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


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
public:
int cnt = 0;
    void helper(Node* root, int l, int h) {
        if( !root) {
            return;
        }
        if(l<=root->data && h>=root->data) {
            cnt++;
            // return;
        }
        // if(root->data>l) {
            helper(root->left, l, h);
        // }
        // if(root->data<l) {
            helper(root->right, l, h);
        // }
        
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here 
      if(!root) {
            return 0;
      }
      helper(root, l, h);
      return cnt;
    }
};