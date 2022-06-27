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

//  A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()) {
    //   vector<int>ans;
       while(q.size()) {
           Node* front = q.front();
           q.pop();
           while(front) {
               ans.push_back(front->data);
               
               if(front->left) {
                   q.push(front->left);
               }
               
               front = front->right;
           }
       }
    //   res.push_back(ans);
   }
   return ans;
}