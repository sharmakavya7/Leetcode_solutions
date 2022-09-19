class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        
        for(string path: paths) {
            string pt;
            int i;
            for(i = 0; i < path.size() && path[i] != ' '; i++) 
                pt += path[i];
            
            pt += '/'; // common part for every file
            i++;       // skip the space
            
            while(i < path.size()) {
                
                string temp, file;
                
                while(i < path.size() && path[i] != '(') {
                    temp += path[i]; 
                    i++;
                }
                
                while(i < path.size() && path[i] != ' ')  {
                    file += path[i];
                    i++;
                }
                
                mp[file].push_back(pt + temp);
                i++;
            }
        }
        for(auto &x: mp) {
            if(x.second.size()>1) 
                ans.push_back(x.second);
        }
        return ans;
    }
};

/*

So basically we need to find the files with same content.
So we can use a hash table to store the content and the file name. Then we can find the files with same content.

*/