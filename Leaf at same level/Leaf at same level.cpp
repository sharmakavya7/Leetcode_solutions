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
class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int level=0;
            for(int i=0; i<q.size(); i++) {
                Node* front = q.front();
                q.pop();
                if(!front->left && !front->right) {
                    level++;
                }
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(level && level!=q.size()) 
                return false;
        }
        return true;
    }
};