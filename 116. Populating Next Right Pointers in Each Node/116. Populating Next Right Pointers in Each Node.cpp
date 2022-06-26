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


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root==NULL) {
            return root;
        }
        q.push(root);
        
        while(!q.empty()) {
            int n=q.size();
            Node* rightNode = nullptr;                    // set rightNode to null initially
            for(int i = n; i>0; i--) {                // traversing each level
                Node* cur = q.front(); 
                q.pop();            // pop a node from current level and,
                cur->next = rightNode;                  // set its next pointer to rightNode
                rightNode = cur;                          // update rightNode as cur for next iteration
                if(cur->right)                          // if a child exists
                    q.push(cur->right),                 // IMP: push right first to do right-to-left BFS
                    q.push(cur-> left);                  // then push left
            }
        }
        return root;
    }
};