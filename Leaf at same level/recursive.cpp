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

int solve(Node* root,int &flag){
    if(root==NULL) return 0;
    int l = solve(root->left,flag);
    int r = solve(root->right,flag);
    if(root->left && root->right && l!=r) flag=0;
    return 1+max(l,r);
    
    
}


bool check(Node *root)
{
    //Your code here
    int flag = 1;
    solve(root,flag);
    return flag;
}