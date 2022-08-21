class Solution {
public:
//     bool canReplace(string target, int pos, string stamp) {
//         for(int i=0; i<stamp.size(); i++) {
//             if(target[i+pos] != '?' && target[i+pos] != stamp[i]) {
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     int replace(string target, int pos, int sz, int cnt) {
//         for(int i=0; i<sz; i++) {
//             if(target[i+pos]!='?') {
//                 target[i+pos] = '?';
//                 cnt++;  // inc count only when there does not already exist a ? at that index
                
//             }
//         }
//         return cnt;
//     }
    
    vector<int> movesToStamp(string stamp, string target) {
        int ls = stamp.length();
        int lt = target.length();
        vector<int> ans;
        bool at_least_1 = true;
        int end   = lt-ls;
        
        while (at_least_1)  // made at least one conversion to '*'
        {
            at_least_1 = false;
            for(int i = 0; i<=end; i++)
            {
                if (target[i] == '#') continue;
                bool match = true;
                bool any_change = false;
                for (int j = 0; j<ls; j++)
                {
                    if (target[i+j] == '*') continue;  // already stampped
                    if (target[i+j] == '#') break;
                    if(stamp[j] != target[i+j])        // char matced
                    {
                        match = false;
                        break;
                    }
                    any_change = true;                 // char to stamp
                }
                if (match && any_change)               // convert stampped  to '*'
                {
                    ans.push_back(i);                  // add stamp to answer
                    for (int j=0; j<ls; j++) target[i+j] = '*';
                    at_least_1 = true;                 // set while flag 
					// mark skip area convert '*' to '#'
                    for (int j=i-1; j>=0 && target[j] == '*'; j--) target[j] = '#'; 
                }
            }
        }
        // check if all tagrget covered
        for(int i = 0; i<lt; i++)
        {
            if (target[i] != '*' && target[i] != '#') return {};
        }
        
        // revert ans order
        int i=0,j=ans.size() -1;
        while(i<j)
            swap(ans[i++],ans[j--]);
        
        return ans;
    }
};
// vector<int>visited(target.size(),0);
        // int cnt=0;
//         vector<int>ans;  // for storing starting index of every stamp found in target
        
//         // if there is no modification in the cur string, we return an empty array
//         bool changed = true;  
        
//         // while(cnt!=target.size()) {
//         do {
//             changed = false;
//             for( int i=0; i<target.size()-stamp.size(); i++ ) {  // loop on target to check if stamp is possible in target or not
//                 bool visited = true;
//                 int cnt=0;

//                     for(int j=0;j<stamp.size();j++) { 
                        
//                         if(target[i+j]=='?')
//                             cnt++; // take care we don't match only matched ones
                        
//                         if(target[i+j]!='?' && stamp[j]!=target[i+j]) { // simple wildcard matching 
//                             visited= false;
//                             break;
//                         }
//                     }
//                     if(visited && cnt<stamp.size()) {
                        
//                         changed = true;
//                         cout<<i<<" ";
//                         ans.push_back(i);
//                         for(int j=0;j<stamp.size();j++) 
//                             target[i+j]='?';
//                     }
                
//             }
//             // if(!changed) {
//             //     return {};
//             // }
//         }while(changed);
//         int i=0,j=ans.size() -1;
//         while(i<j)
//             swap(ans[i++],ans[j--]);
//         // reverse(ans.begin(), ans.end());
//         return ans;
//                 if(!visited[i] && canReplace(target, i, stamp)) {
                    
//                     cnt = replace(target, i, stamp.size(), cnt);
//                     visited[i] = 1;
//                     changed = true;    // if we replace any value, we mark it true
//                     ans.push_back(i);
                    
//                     if(cnt == target.size()) {
//                         break;
//                     }
//                 }