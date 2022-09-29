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

// const int N = 1e5+2;
int parent[100001];
int freq[100001];           // freq of grp size
multiset<int>sizes;

int find_parent(int node) {
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

void merge(int a, int b) {
    int sizeA = -parent[a];
    int sizeB = -parent[b];

    sizes.erase(sizes.find(sizeA));
    freq[sizeA]--;
    sizes.erase(sizes.find(sizeB));
    freq[sizeB]--;
    
    sizes.insert(sizeA + sizeB);
    freq[sizeA+sizeB]++;
    // cout<<freq[sizeA+sizeB]<<" "<<freq[sizeA]<<" ";
}

void join(int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);

    if(p1==p2) {
        return;
    }

    if(parent[p1] > parent[p2] ) {
        swap(p2, p1);
    }
    merge(p1, p2);
    parent[p1] += parent[p2];
    parent[p2] = p1;
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; i++) {
        parent[i] = -1;
        sizes.insert(1);
        freq[1]++;
    }

    for(int i=1; i<=q; i++) {
        int u, v;
        cin >> u >> v;
        join(u, v);

        int ans=0;

        int pv=-1;
        int mini = n+1;
        for(auto j=sizes.begin(); j!=sizes.end(); j++) {
            int val = (*j);
            if(freq[val] > 1) {
                // cout<<"to"<<" ";
                mini = 0;
                break;
            }
            // cout<<freq[val]<<" " << val<<" "<<pv<<" ";
            if(pv!=-1) {
                // cout<<"y"<<" ";
                mini = min(mini, val-pv);
            }
            pv = val;
        }
        if(mini == n+1) {
            mini = 0;
        }
        ans = mini;
        cout<<ans<<endl;
    }
    return 0;
}