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

class solution {
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if (node == NULL)
		return 0; 
    
   if (node->left == NULL&& node->right==NULL)
	{
		return 1;
	}
	int ans1=-1,ans2=-1;
	if(node->left)
	 ans1 = height(node->left);
	
	if(node->right)
	 ans2 = height(node->right);
	
	int height = 0;
	if (ans1 > ans2 && ans1 > height)
		height = ans1;
	else
		height = ans2;

	return height + 1;
    }
};