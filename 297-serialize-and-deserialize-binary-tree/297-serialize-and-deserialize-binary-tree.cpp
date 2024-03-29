/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // TC: O(n), SC: O(n)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                str.append("#,");
            }
            else {
                str.append(to_string(front->val)+',');
            }
           if(front!=NULL) {
               q.push(front->left);
               q.push(front->right);
           }
        }
       return str; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss,str,',');   // traverse through string char by char separated by ','
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            getline(ss,str,',');
            if(str=="#") {
                curr->left=NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(ss,str,',');
            if(str=="#") {
                curr->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
      return root;  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));