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


//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 }; 

class Solution {
public:
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.size() == 0 ? nullptr : build(s, i);
    }

private:
    TreeNode* build(string& s, int& i) {
        int start = i;
        if (s[i] == '-') {
            i++;
        }
        while (isdigit(s[i])) {
            i++;
        }
        
        int num = stoi(s.substr(start, i - start));
        TreeNode* node = new TreeNode(num);
        if (s[i] == '(') {
            node->left = build(s, ++i);
            i++;    // )
        }
        if (s[i] == '(') {
            node->right = build(s, ++i);
            i++;    // )
        }
        return node;
    }
};